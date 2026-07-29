# python file to parse the vk.xml file
# and create the {output_c_filename} c file
import xml.etree.ElementTree as ET
from collections.abc import Callable
from functools import partial

xml_filename = "vk.xml"
output_c_prepend = "vulkan_xml_"

def walk_tree(func: Callable[[ET.Element[str]], None], tree: ET.Element[str]) -> None:
    for element in tree:
        func(element)
        walk_tree(func, element)

def collect_all(func: Callable[[ET.Element[str]], bool], tree: ET.Element[str]) -> list[ET.Element[str]]:
    return collect_all_recurse(func, tree, [])

def collect_all_recurse(func: Callable[[ET.Element[str]], bool], tree: ET.Element[str], return_list: list[ET.Element[str]]) -> list[ET.Element[str]]:
    for element in tree:
        if func(element):
            return_list.append(element)
        collect_all_recurse(func, element, return_list)

    return return_list

def struct_extends(element: ET.Element[str], extends_from: str) -> bool:
    extends = element.get("structextends", "")
    if len(extends) <= 0:
        return False
    
    extends = extends.split(",")
    if extends_from in extends:
        return True
    else:
        return False
    
def extends(element: ET.Element[str], extends_from: str) -> bool:
    extends = element.get("extends", "")
    if len(extends) <= 0:
        return False
    
    extends = extends.split(",")
    if extends_from in extends:
        return True
    
    return False

def is_vk_structure_type_struct(element: ET.Element[str]) -> bool:
    if element.get("category") != "struct":
        return False
    for sub_element in element:
        for sub_sub_element in sub_element:
            if sub_sub_element.tag == "type" and sub_sub_element.text == "VkStructureType":
                return True

    return False

def is_tag(element: ET.Element[str], tag: str) -> bool:
    if element.tag == tag:
        return True
    return False

def debug_print_tree(element: ET.Element[str], last: list[bool] = [], level: int = 0) -> None:
    # │ ├ └ ─
    last_len = len(last)
    for index,boolean in enumerate(last):
        if(index == last_len-1):
            if boolean == True:
                print("└───", end="")
            else:
                print("├───", end="")
        else:
            if boolean == True:
                print("    ", end="")
            else:
                print("│   ", end="")

    print(f"{element.tag}\t: {element.text}\t| {element.tail}\t| {element.attrib}")

    sub_element_len = len(element)
    for index,sub_element in enumerate(element):
        if sub_element_len-1 == index:
            debug_print_tree(sub_element, last + [True], level + 1)
        else:
            debug_print_tree(sub_element, last + [False], level + 1)

comparator_dict = {
    "uint8_t"  : ">=",
    "uint16_t" : ">=",
    "uint32_t" : ">=",
    "uint64_t" : ">=",

    "int8_t"  : ">=",
    "int16_t" : ">=",
    "int32_t" : ">=",
    "int64_t" : ">=",

    "size_t" : ">=",

    "float"  : ">=",
    "double" : ">=",

    "enum" : ">=",

    "VkBool32" : ">=",
    "VkFlags"  : ">=",

    "VkStructureType" : "==",
    # ignore
    "void" : "IGNORE",
    "char" : "IGNORE",
}

def get_protectors(sType: str) -> tuple[str, str]:
    protector_begin = ""
    protector_end = ""
    for enum in vk_enum_types:
        if enum.get("name") == sType or enum.get("alias") == sType:
            protector_begin = f"#ifdef {enum.get("protect")}\n"
            protector_end += "#endif\n"

    for extension in vk_extensions:
        for require in extension:
            for item in require:
                if item.get("name") == sType:
                    for platform in vk_platorms:
                        if platform.get("name") == extension.get("platform"):
                            protector_begin += f"#ifdef {platform.get("protect")}\n"
                            protector_end += "#endif\n"

    return (protector_begin,protector_end)

def get_supported(sType) -> list[str]:
    for extension in vk_extensions:
        for require in extension:
            for item in require:
                if item.get("name") == sType:
                    if require.get("api") != None:
                        return require.get("api", "").split(",")
                    return extension.get("supported", "").split(",")
    return []

vk_structure_types=[]
vk_enum_types=[]
vk_structure_type_names=[]
vk_platorms=[]
vk_extensions=[]

if __name__ == "__main__":
    with open(xml_filename, "r") as xml_file:
        with open(output_c_filename, "w") as output_c_file:
            error_count = 0

            tree = ET.parse(xml_file).getroot()
            # debug_print_tree(tree)

            vk_structure_types = collect_all(is_vk_structure_type_struct, tree)
            vk_enum_types = collect_all(partial(is_tag, tag="enums"), tree)
            vk_structure_type_names = []
            vk_platorms=collect_all(partial(is_tag, tag="platform"), tree)
            vk_extensions=collect_all(partial(is_tag, tag="extension"), tree)
            vk_types=collect_all(partial(is_tag, tag="type"), tree)

            vkstructuretypes_len = len(vk_structure_types)
            print(f"found {vkstructuretypes_len} structures")

            for element in vk_structure_types:
                for member in element:
                    for sub_element in member:
                        if sub_element.text == "sType":
                            vk_structure_type_names.append(member.get("values", "NOT_FOUND"))

            # file header
            output_c_file.writelines([
                "#include <stdlib.h>\n"
                "#include <vulkan/vulkan.h>\n"
                "\n"
            ])

            output_c_file.writelines([
                "void* copy_structure(void* structure) {\n",
                "    void* return_struct = NULL;\n"
                "    switch(*(VkStructureType*) structure) {\n",
            ])           
            
            i = 0
            while i < vkstructuretypes_len:
                struct_type = vk_structure_types[i].get("name", "NOT_FOUND")
                sType = vk_structure_type_names[i]

                if sType == "NOT_FOUND":
                    i += 1
                    continue

                if not "vulkan" in get_supported(sType):
                    i += 1
                    continue
                
                protector_begin,protector_end = get_protectors(sType)
                
                if(protector_begin != ""):
                    output_c_file.write(protector_begin)

                output_c_file.writelines([
                    f"        case {sType}:\n",
                    f"            return_struct = malloc(sizeof({struct_type}));\n",
                    f"            break;\n"
                ])

                if(protector_begin != ""):
                    output_c_file.writelines([
                        f"{protector_end}",
                    ])
                i += 1

            output_c_file.writelines([
                "        default:\n"
                "            return_struct = NULL;\n"
                "            break;\n"
                "    }\n",
                "    *((VkStructureType*) return_struct) = *((VkStructureType*) structure);\n"
                "    return return_struct;\n"
                "}\n",
            ])

            output_c_file.write("\n")

# comparision functions
            i = 0
            while i < vkstructuretypes_len:
                struct_type = vk_structure_types[i].get("name", "NOT_FOUND")
                sType = vk_structure_type_names[i]
                output_begin = ""
                comparisons = ""

                if "vulkan" not in get_supported(sType):
                    i += 1
                    continue
                
                protector_begin,protector_end = get_protectors(sType)

                output_begin += f"bool compare_{struct_type}({struct_type} a, {struct_type} b)"
                output_begin += " {\n"

                output_begin += "    if (\n"

                first = True
                for element in vk_structure_types[i]:
                    if element.tag == "member":
                        element_type = None
                        name = None
                        for sub in element:
                            if sub.tag == "type":
                                element_type = sub.text
                            if sub.tag == "name":
                                name = sub.text
                        
                        if element_type is None or name is None:
                            continue
                        if name == "pNext" or name == "sType": # skip redundant or useless checks
                            continue

                        # account for enums
                        for enum in vk_enum_types:
                            if element_type == enum.get("name") or enum.get("alias") == sType:
                                element_type = "enum"

                        for vk_type in vk_types:
                            vk_type_name = vk_type.find("name")
                            the_type = vk_type.find("type")
                            if vk_type_name == element_type and the_type != None and the_type.text != None:
                                element_type = the_type.text

                        comparator = comparator_dict.get(element_type)
                        if comparator is None:
                            print(f"ERROR {error_count}, comparator for type {element_type} not found\t| for struct {vk_structure_types[i].get("name")}")
                            error_count += 1
                            continue
                        if comparator == "IGNORE":
                            continue

                        if not first:
                            comparisons += " &&\n"
                        first = False
                        
                        comparisons += f"        a.{name}"
                        comparisons += f" {comparator} "    # comparator
                        comparisons += f"b.{name}"

                output_end  = "\n    ) {\n"
                output_end += "        return true;\n"
                output_end += "    }\n"
                output_end += "    return false;\n"
                output_end += "}\n"

                if comparisons == "":
                    if(protector_begin != None):
                        output_c_file.write(protector_begin)

                    output_c_file.writelines([
                        output_begin,
                        "        true",
                        output_end
                    ])

                    if(protector_end != None):
                        output_c_file.write(protector_end)
                    i += 1
                    continue



                if(protector_begin != None):
                    output_c_file.write(protector_begin)

                output_c_file.writelines([
                    output_begin,
                    comparisons,
                    output_end
                ])

                if(protector_end != None):
                    output_c_file.write(protector_end)
                i += 1
            
# compare two arbitrary structure:
            output_c_file.write("\n")

            output_c_file.writelines([
                "bool compare_structure(void* a, void* b) {\n",
                "    if(!(*(VkStructureType*) a != *(VkStructureType*) b)) {\n"
                "        return false;\n",
                "    }\n\n"
                "    switch(*(VkStructureType*) a) {\n",
            ])           
            
            vkstructuretypes_len = len(vk_structure_types)
            i = 0
            while i < vkstructuretypes_len:
                struct_type = vk_structure_types[i].get("name", "NOT_FOUND")
                sType = vk_structure_type_names[i]

                if "vulkan" not in get_supported(sType):
                    i += 1
                    continue
                
                protector_begin,protector_end = get_protectors(sType)
                
                if(protector_begin != None):
                    output_c_file.write(f"{protector_begin}")

                output_c_file.writelines([
                    f"        case {struct_type}:\n",
                    f"            return compare_{struct_type}(({struct_type}*) a, ({struct_type}*) b)\n",
                ])

                if(protector_begin != None):
                    output_c_file.write(f"{protector_end}")
                i += 1

            output_c_file.writelines([
                "    }\n",
                "    return false;\n"
                "}\n",
            ])

            output_c_file.write("\n")

            print(f"processed {vkstructuretypes_len} structures")
