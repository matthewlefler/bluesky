# python file to parse the vk.xml file
# and create the {output_c_filename} c file
from io import TextIOWrapper
import xml.etree.ElementTree as ET
from dataclasses import dataclass
from enum import Enum

from debug import *
from depends import *
from vk_version import *
from structures import *

xml_filename = "vk.xml"
output_c_file_prepend = "bluesky_vulkan_xml"

extension_name_valid: dict[str, int] = dict()
structures: dict[str, structure] = dict()

def collect_valid_extensions(element: ET.Element[str]) -> list[ET.Element[str]]:
    extensions = list(element.iter("extension"))
    print(f"collected {len(extensions)} extensions")

    extension_list: list[tuple[str, ET.Element[str]]] = []
    extension_indices = dict()
    for index, extension in enumerate(extensions):
        name = extension.get("name")
        if name is not None:
            extension_list.append((name, extension))
            extension_name_valid[name] = -1
            extension_indices[name] = index

    return_array = []

    i = 0
    while i < len(extension_list):
        name = extension_list[i][0]
        extension = extension_list[i][1]

        supported = extension.get("supported")
        if supported is not None and "vulkan" not in supported.split(","):
            extension_name_valid[name] = 0
            i += 1
            continue

        depends = extension.get("depends")
        if depends is not None:
            depends = parse_depends(depends)
            if depends is not None:
                return_val = calc_depends_struct(depends, extension_name_valid, structures)
                if isinstance(return_val, list):
                    for index, dependincy_name in enumerate(return_val):
                        first_index = i + index
                        second_index = extension_indices[dependincy_name]
                        if second_index == None:
                            print(f"for {name}, index of {dependincy_name} not found")
                            extension_name_valid[dependincy_name] = 0
                            i += 1 
                            continue
                        temp = extension_list[first_index] # swap first and second indices
                        extension_list[first_index] = extension_list[second_index]
                        extension_list[second_index] = temp
                        continue
                else:
                    if return_val == 0:
                        print(f"{name} not vaild")
                        extension_name_valid[name] = 0
                        i += 1
                        continue

        extension_name_valid[name] = 1
        return_array.append(extension)
        i += 1

    return return_array

# [3][4]
# [<enum>ARRAY_LEN</enum>][3]
# [<enum>ARRAY_LEN</enum>][<enum>ARRAY_LEN2</enum>]
# [3][<enum>ARRAY_LEN2</enum>]

def collect_structures(root: ET.Element[str]) -> list[structure]:
    return_array = []
    type_tags = list(root.iter("type"))

    for type_tag in type_tags:
        category = type_tag.get("category")
        name = type_tag.get("name")
        if category != "struct" or name is None:
            continue
        
        members = type_tag.findall("member")
        collected_members = []
        for member in members:
            struct_type = parse_struct_member(member)
            if struct_type is None:
                continue
            collected_members.append(struct_type)

        return_array.append(structure(name, collected_members))    

    return return_array

@dataclass
class platform:
    name: str
    protect: str

platforms: dict[str, platform] = dict()

def collect_platforms(root: ET.Element[str]) -> list[ET.Element[str]]:
    all_platforms = list(root.iter("platform"))

    for a_platform in all_platforms:
        name = a_platform.get("name")
        protect = a_platform.get("protect")

        if name is None or protect is None:
            continue

        platforms[name] = platform(name, protect)

    return all_platforms

def collect_vaild_enums(element: ET.Element[str]) -> list[ET.Element[str]]:
    extensions = list(element.iter("extension"))
    return_array = []

    for extension in extensions:
        if not "vulkan" in extension.get("supported", "").split(","):
            continue
        for require in extension:
            if eval_depends(require, extension_name_valid, structures) == False:
                continue
            for element in require:
                if element.tag == "enum":
                    return_array.append(element)

    return return_array

comparator_dict = {
    "uint8_t"  : ">=",
    "uint16_t" : ">=",
    "uint32_t" : ">=",
    "uint64_t" : ">=",
    "uint128_t" : ">=",

    "int8_t"  : ">=",
    "int16_t" : ">=",
    "int32_t" : ">=",
    "int64_t" : ">=",
    "int128_t" : ">=",

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

def get_enums_that_extend_from(enums: list[ET.Element[str]], extends_from: str) -> list[ET.Element[str]]:
    return_array = []
    for enum in enums:
        extends = enum.get("extends")

        if extends is None or extends != extends_from:
            continue
        return_array.append(enum)

    return return_array

def convert_enum_name_to_struct_name(name: str) -> str:
    # VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_NALU_SLICE_SEGMENT_INFO_KHR
    # to
    # VIDEO_ENCODE_H265_NALU_SLICE_SEGMENT_INFO_KHR
    name = name.removeprefix("VK_STRUCTURE_TYPE_")
    struct_name = ""
    capitalize_next = True
    for char in name:
        if char == "_":
            capitalize_next = True
            continue

        if capitalize_next: 
            struct_name += char
            capitalize_next = False
        else:
            struct_name += char.lower()

    struct_name = "Vk" + struct_name

    if struct_name.endswith("Khr") or struct_name.endswith("Ext"):
        struct_name_len = len(struct_name)
        struct_name = struct_name[:struct_name_len - 3] + struct_name[struct_name_len - 3:].upper()

    return struct_name
        

def write_copy_extends_from_vk_struct_type(file_to_write_to: TextIOWrapper, enums: list[ET.Element[str]]) -> None:
    enums_that_extend_vk_struct_type = get_enums_that_extend_from(enums, "VkStructureType")

    file_to_write_to.writelines([
        "#include <stdlib.h>\n"
        "\n"
        "#include <vulkan/vulkan.h>\n"
        "\n"
        "void* copy_struct_extends_from_vk_struct(void* structure) {\n",
        "    switch (*(VkStructureType*) structure) {\n"
    ])
    for enum in enums_that_extend_vk_struct_type:
        enum_name = enum.get("name")

        if enum_name is None:
            continue

        struct_name = convert_enum_name_to_struct_name(enum_name)

        file_to_write_to.writelines([
            f"        case {enum_name}:\n",
            f"            return malloc(sizeof({convert_enum_name_to_struct_name(enum_name)}));\n"
        ])
    
    file_to_write_to.writelines([
        "        default:\n",
        "            return NULL;\n",
        "    }\n",
        "}\n"
    ]) 

if __name__ == "__main__":
    with (
        open(xml_filename, "r") as xml_file,
        open(f"{output_c_file_prepend}_struct_copy.c", "w") as output_copy_file,
        open(f"{output_c_file_prepend}_struct_comparision.c", "w") as output_comparision_file
    ):
        tree_root = ET.parse(xml_file).getroot()

        collected_platforms = collect_platforms(tree_root)
        print(f"got {len(collected_platforms)} plaforms")

        valid_extensions = collect_valid_extensions(tree_root)        
        print(f"got {len(valid_extensions)} valid extensions")

        collected_structures = collect_structures(tree_root)
        print(f"got {len(collected_structures)} structures")

        valid_enums = collect_vaild_enums(tree_root)
        print(f"got {len(valid_enums)} valid enums")

        write_copy_extends_from_vk_struct_type(output_copy_file, valid_enums)

        