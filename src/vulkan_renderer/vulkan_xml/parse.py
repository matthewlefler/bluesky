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
from vk_types import *

xml_filename = "vk.xml"
output_c_file_prepend = "bluesky_vulkan_xml"

structures: dict[str, vk_structure] = dict()

# [3][4]
# [<enum>ARRAY_LEN</enum>][3]
# [<enum>ARRAY_LEN</enum>][<enum>ARRAY_LEN2</enum>]
# [3][<enum>ARRAY_LEN2</enum>]

ignore_str = "IGNORE"
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

    "void*" : ignore_str, # pointers shouldn't be comparied anyways
    "VK_DEFINE_NON_DISPATCHABLE_HANDLE" : ignore_str # these pointers are meant to be opauque anyways
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
    protector = None
    if structure.ext.platform is not None:
        protector = platforms[structure.ext.platform].protect
        file_to_write_to.write(f"#ifdef {protector}\n")

    file_to_write_to.writelines([
        f"\nbool are_requirements_met_{structure.name}({structure.name} actual, {structure.name} requirement) ",
        "{\n",
        "    if (\n"
    ])

    first = True
    for member in structure.members:
        base_type = type_name_to_base.get(member.base_type, None)
        if base_type is None:
            base_type = member.base_type
        else:
            if base_type.category == "enum":
                base_type = "enum"
            elif base_type.category == "bitmask":
                bit_len = get_vk_flag_type_bit_len(base_type.name)
                for bit_num in range(bit_len):
                    if first:
                        first = False
                    else:
                        file_to_write_to.write(" &&\n")

                    bit_selector_str = "0b1" + (bit_num * "0")
                    file_to_write_to.write(f"        (actual.{member.name} & {bit_selector_str}) >= (requirement.{member.name} & {bit_selector_str})")
                continue
            else:
                base_type = base_type.name
        
        comparator = comparator_dict.get(get_type_string_arg(base_type, member.pointer_depth, member.array_len), None)
        if comparator is None:
            comparator = "=="
            print(f"KeyError: \"{get_type_string_arg(base_type, member.pointer_depth, member.array_len)}\"\tin {structure.name}")
        
        if comparator is ignore_str:
            continue

        if first:
            first = False
        else:
            file_to_write_to.write(" &&\n")

        file_to_write_to.write(f"        actual.{member.name} {comparator} requirement.{member.name}")

    file_to_write_to.writelines([
        "\n"
        "    ) {\n",
        "        return true;\n",
        "    }\n",
        "    return false;\n",
        "}\n"
    ])

    if protector is not None:
        file_to_write_to.write("#endif\n")
       

def write_compare_functions(file_to_write_to: TextIOWrapper, structures: list[vk_structure]) -> None:
    file_to_write_to.writelines([
        "#include <vulkan/vulkan.h>\n"
    ])
    for structure in structures:
        write_compare_function(file_to_write_to, structure)

if __name__ == "__main__":
    with (
        open(xml_filename, "r") as xml_file,
        open(f"{output_c_file_prepend}_struct_copy.c", "w") as output_copy_file,
        open(f"{output_c_file_prepend}_struct_comparision.c", "w") as output_comparision_file
    ):
        tree_root = ET.parse(xml_file).getroot()

        resolve_types(tree_root)
        print(f"resolved {len(type_name_to_base)} types")

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
