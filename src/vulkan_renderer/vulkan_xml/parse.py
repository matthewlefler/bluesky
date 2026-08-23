# python file to parse the vk.xml file
# and create the {output_c_filename} c file
from io import TextIOWrapper
import xml.etree.ElementTree as ET
from dataclasses import dataclass
from enum import Enum
import re
import time

from debug import *
from depends import *
from vk_version import *
from vk_structures import *
from platforms import *
from enums import *
from extensions import *
from vk_types import *

TAB_SPACE = "    "

xml_filename = "vk.xml"
output_c_file_prepend = "bluesky_vulkan_xml"

structures: dict[str, vk_structure] = dict()

# [3][4]
# [<enum>ARRAY_LEN</enum>][3]
# [<enum>ARRAY_LEN</enum>][<enum>ARRAY_LEN2</enum>]
# [3][<enum>ARRAY_LEN2</enum>]

IGNORE_STR = "IGNORE"
FROM_EXTERNAL_HEADER_STR = "from_external_header"
BITMASK_STR = "bitmask"
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

    "int" : ">=",

    "size_t" : ">=",

    "float"  : ">=",
    "double" : ">=",

    "enum" : "==",
    "funcpointer" : "==",

    "VkBool32" : ">=",
    "VkFlags"  : ">=",

    "VkStructureType" : "==",

    "char" : "==",

    FROM_EXTERNAL_HEADER_STR : "==",

    "ANativeWindow" : "==",
    "AHardwareBuffer" : "==",
    "CAMetalLayer" : "==",
    "MTLDevice_id" : "==",
    "MTLCommandQueue_id" : "==",
    "MTLBuffer_id" : "==",
    "MTLBuffer_id" : "==",
    "MTLTexture_id" : "==",
    "MTLTexture_id" : "==",
    "IOSurfaceRef" : "==",
    "IOSurfaceRef" : "==",
    "MTLSharedEvent_id" : "==",
    "MTLSharedEvent_id" : "==",
    "OHNativeWindow" : "==",
    "OHBufferHandle" : "==",
    "OH_NativeBuffer" : "==",

    # ignore

    "void" : IGNORE_STR, # void can't be comparied anyways
    "VK_DEFINE_NON_DISPATCHABLE_HANDLE" : IGNORE_STR, # these pointers are meant to be opauque anyways
    "VK_DEFINE_HANDLE" : IGNORE_STR # look it up, should be this or "=="
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
        f"bool are_requirements_met_{structure.name}({structure.name} actual, {structure.name} requirement)"," {\n",
    ])

    member_comparisions: dict[str, str] = dict()
    inline_member_comparisions: dict[str, bool] = dict()
    for member in structure.members:
        comparision_string = ""

        base_type = type_name_to_base.get(member.base_type, None)
      
        if base_type is None:
            base_type = member.base_type
        else:
            if base_type.category == "enum":
                base_type = "enum"
            elif base_type.category == "funcpointer":
                base_type = "funcpointer"
            elif base_type.category == "union":
                # print(member.selector)
                
                member_comparisions[member.name] = "true /* union comparision placeholder */"
                inline_member_comparisions[member.name] = True
                continue

            elif base_type.category == BITMASK_STR:
                # 0 0 -> 0
                # 0 1 -> 1
                # 1 0 -> 0
                # 1 1 -> 0
                # if   requirements are met, get all 0s which will equal 0,
                # else requirements are not met
                
                base_type = BITMASK_STR
            elif base_type.requires is not None and base_type.requires.endswith(".h"):
                base_type = FROM_EXTERNAL_HEADER_STR
            elif base_type.requires is not None and base_type.requires.endswith(".h"):
                base_type = FROM_EXTERNAL_HEADER_STR
            else:
                base_type = base_type.name

        comparator = comparator_dict.get(base_type, None)
        base_type_is_struct = is_structure(base_type)
        base_type_is_from_external_header = base_type == FROM_EXTERNAL_HEADER_STR
        base_type_is_bitmask = base_type == BITMASK_STR

        if(
            not base_type_is_bitmask and
            not base_type_is_struct and
            not base_type_is_from_external_header and
            comparator is None
        ):
            comparator = "=="
            print(f"KeyError: \"{base_type}\"\tin {structure.name}")
    
        if comparator is not IGNORE_STR:
            if member.length is not None:
                number_of_braces = 0
                indexer = ord("i")
                total_indentation = 0
                array_selector = ""
                is_null_terminated_string = False
                comparision_string += f"    bool is_{member.name}_req_met = true;\n"
                for indentation,array_length in enumerate(member.length):
                    if array_length == NULL_TERMINATED:
                        is_null_terminated_string = True
                        continue

                    other_member = None

                    is_constant = False
                    constant_type = type_constants.get(array_length, None)
                    if array_length.isnumeric():
                        other_member = struct_member("array_len", "uint32_t", 0, None, None, [], None, None)
                        is_constant = True
                    if array_length.startswith(MATH_EXP):
                        array_length = array_length.removeprefix(MATH_EXP)
                        other_member = struct_member("array_len", "uint32_t", 0, None, None, [], None, None)
                        is_constant = True

                        for temp_member in structure.members:
                            if temp_member.name in array_length:
                                is_constant = False 

                    if constant_type is not None:
                        other_member = struct_member("constant_number", constant_type, 0, None, None, [], None, None) 
                        is_constant = True

                    for temp_member in structure.members:
                        if temp_member.name == array_length:
                            other_member = temp_member
                            is_constant = False

                    if other_member is None:
                        if array_length != NULL_TERMINATED:
                            print(f"ERROR: other member not found in struct: {structure.name}, in member: {member.name}, with other's name: {array_length} | {get_type_string(member)}")
                        continue

                    number_of_braces += 1


                    if is_constant:
                        comparision_string += f"{TAB_SPACE * indentation}    for({other_member.base_type} {chr(indexer)} = 0; {chr(indexer)} < {array_length}; ++{chr(indexer)}) " + "{\n"
                    else:
                        actual_string = array_length
                        requirement_string = array_length
                        for temp_member in structure.members:
                            if temp_member.name in re.split("{|}| |\\(|\\)", actual_string):
                                actual_string = actual_string.replace(temp_member.name, f"actual.{temp_member.name}")
                                requirement_string = requirement_string.replace(temp_member.name, f"requirement.{temp_member.name}")

                        comparision_string += f"{TAB_SPACE * indentation}    for({other_member.base_type} {chr(indexer)} = 0; {chr(indexer)} < {actual_string} && {chr(indexer)} < {requirement_string}; ++{chr(indexer)}) " + "{\n"
                    array_selector += f"[{chr(indexer)}]"
                    indexer += 1
                    total_indentation += 1

                comparision_string += f"{TAB_SPACE * total_indentation}    if( "
                
                if is_null_terminated_string: 
                    comparision_string += f"strcmp(actual.{member.name}{array_selector}, requirement.{member.name}{array_selector}) != 0"
                elif base_type_is_struct:
                    comparision_string += f"are_requirements_met_{base_type}(actual.{member.name}{array_selector}, requirement.{member.name}{array_selector}) == false"
                elif base_type_is_bitmask:
                    comparision_string += f"((~actual.{member.name}{array_selector}) & requirement.{member.name}{array_selector}) == 0"
                elif base_type_is_from_external_header:
                    comparision_string += f"&actual.{member.name}{array_selector} == &requirement.{member.name}{array_selector}"
                else:
                    comparision_string += f"actual.{member.name}{array_selector} {comparator} requirement.{member.name}{array_selector} == false"

                    indexer += 1
                comparision_string +=     f" ) " + "{\n"
                comparision_string +=     f"{TAB_SPACE * total_indentation}        is_{member.name}_req_met = false;\n"
                comparision_string +=     f"{TAB_SPACE * total_indentation}    " + "}\n"

                for brace_index in range(number_of_braces):
                    comparision_string += f"{TAB_SPACE * (number_of_braces - brace_index)}" + "}\n"

                inline_member_comparisions[member.name] = False

            else:
                if base_type_is_struct:
                    comparision_string = f"are_requirements_met_{base_type}({member.pointer_depth * "*"}actual.{member.name}, {member.pointer_depth * "*"}requirement.{member.name})"
                elif base_type_is_bitmask:
                    comparision_string = f"((~{member.pointer_depth * "*"}actual.{member.name}) & {member.pointer_depth * "*"}requirement.{member.name}) == 0"
                elif base_type_is_from_external_header:
                    comparision_string += f"&{member.pointer_depth * "*"}actual.{member.name} == &{member.pointer_depth * "*"}requirement.{member.name}"
                else:
                    comparision_string = f"{member.pointer_depth * "*"}actual.{member.name} {comparator} {member.pointer_depth * "*"}requirement.{member.name}"
                inline_member_comparisions[member.name] = True

            member_comparisions[member.name] = comparision_string

    for name in member_comparisions:
        if not inline_member_comparisions[name]:
            file_to_write_to.write(member_comparisions[name])

    first = True
    file_to_write_to.write("    if( \n")
    for name in member_comparisions:
        if first:
            first = False
        else:
            file_to_write_to.write(" &&\n")

        inline = inline_member_comparisions[name]
        if inline:
            file_to_write_to.write(f"        {member_comparisions[name]}")
        else:
            file_to_write_to.write(f"        is_{name}_req_met")

    file_to_write_to.writelines([
        "\n",
        "    ) {\n",
        "        return true;\n",
        "    }\n",
        "    return false;\n",
        "}\n"
    ])

    if protector is not None:
        file_to_write_to.write("#endif\n")

    file_to_write_to.write("\n")
       

def write_compare_functions(c_file_to_write_to: TextIOWrapper, h_file_to_write_to: TextIOWrapper, structures: list[vk_structure]) -> None:
    c_file_to_write_to.writelines([
        "#include <vulkan/vulkan.h>\n",
        "#include <string.h>\n\n",
        f"#include \"{h_file_to_write_to.name}\"\n\n"
    ])

    h_file_to_write_to.writelines([
        "#include <vulkan/vulkan.h>\n",
        "\n",
        "/**\n",
        " * This Header file contains all the comparision functions\n"
        " * required by the rendering engine to test any device for compatability\n"
        "*/\n\n",
    ])
    
    for structure in structures:

        protector = None
        if structure.ext.platform is not None:
            protector = platforms[structure.ext.platform].protect
            h_file_to_write_to.write(f"#ifdef {protector}\n")
        h_file_to_write_to.write(f"bool are_requirements_met_{structure.name}({structure.name} actual, {structure.name} requirement);\n")
        if protector is not None:
            h_file_to_write_to.write("#endif\n")

        write_compare_function(c_file_to_write_to, structure)

VK_STRUCTURE_TYPE = "VkStructureType"

if __name__ == "__main__":
    time_before = time.time_ns()
    with (
        open(xml_filename, "r") as xml_file,
        open(f"{output_c_file_prepend}_struct_copy.c", "w") as output_copy_file,
        open(f"{output_c_file_prepend}_struct_comparision_functions.c", "w") as output_comparision_func_file_c,
        open(f"{output_c_file_prepend}_struct_comparision_functions.h", "w") as output_comparision_func_file_h,
        open(f"{output_c_file_prepend}_struct_comparision_vk_struct_type.c", "w") as output_struct_comparision_file_c
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
        print(f"wrote copy functions")

        structures_to_compare = get_stucts_that_extend_from(collected_structures, VK_STRUCTURE_TYPE)
        write_compare_functions(output_comparision_func_file_c, output_comparision_func_file_h, collected_structures)
        print(f"wrote {len(structures_to_compare)} comparision functions")

    time_after = time.time_ns()
    print(f"took {(time_after - time_before) / 1e9} s")

