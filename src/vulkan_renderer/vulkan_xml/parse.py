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
from platforms import *
from enums import *
from extensions import *

xml_filename = "vk.xml"
output_c_file_prepend = "bluesky_vulkan_xml"

structures: dict[str, vk_structure] = dict()

# [3][4]
# [<enum>ARRAY_LEN</enum>][3]
# [<enum>ARRAY_LEN</enum>][<enum>ARRAY_LEN2</enum>]
# [3][<enum>ARRAY_LEN2</enum>]

def collect_structures(root: ET.Element[str]) -> list[vk_structure]:
    return_array = []
    type_tags = list(root.iter("extension"))

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

        return_array.append(vk_structure(name, collected_members))    

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
        

def write_copy_extends_from_vk_struct_type(file_to_write_to: TextIOWrapper, enums: list[vk_enum]) -> None:
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
        if enum.deprecated is not None or enum.alias is not None or enum.extension_from.deprecatedby is not None:
            continue

        enum_name = enum.name

        struct_name = enum_name_to_struct[enum_name].name

        protector = None
        if enum.extension_from.platform is not None:
            platform = platforms[enum.extension_from.platform]
            protector = f"#ifdef {platform.protect}\n"

        if protector:
            file_to_write_to.write(protector)

        file_to_write_to.writelines([
            f"        case {enum_name}:\n",
            f"            return malloc(sizeof({struct_name}));\n"
        ])

        if protector:
            file_to_write_to.write("#endif\n")
    
    file_to_write_to.writelines([
        "        default:\n",
        "            return NULL;\n",
        "    }\n",
        "}\n"
    ]) 

def write_compare_function(file_to_write_to: TextIOWrapper, structure: vk_structure) -> None:
    file_to_write_to.write("hi\n")
    

def write_compare_functions(file_to_write_to: TextIOWrapper, structures: list[vk_structure]) -> None:
    for structure in structures:
        write_compare_function(file_to_write_to, structure)

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

        valid_enums = collect_vaild_enums(tree_root, extension_name_valid, structures)
        print(f"got {len(valid_enums)} valid enums")

        find_enums_from_structures(collected_structures, valid_enums)
        write_copy_extends_from_vk_struct_type(output_copy_file, valid_enums)
        write_compare_functions(output_comparision_file, collected_structures)
