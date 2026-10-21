#!python
import logging
from io import TextIOWrapper
import sys
import subprocess
import os

import vulkan_object
from contextlib import chdir

OUTPUT_DIR: str | None = None
FILE_PREPEND="bluesky_vulkan_xml"

FILE_COMMENT="""/**
 * auto-generated file DO NOT EDIT, change the generator functions instead
 * it is recommened to add these files to your .gitignore as well
 * @author matthew lefler | @skye
*/\n
"""

def write_copy_struct(output_c_file: TextIOWrapper, output_h_file: TextIOWrapper, structs: dict[str, vulkan_object.VkStructure]) -> None:
    output_h_file.write(FILE_COMMENT)
    output_c_file.write(FILE_COMMENT)
    
    output_h_file.write("#include <vulkan/vulkan.h>\n\n")
    output_h_file.write("void *malloc_structure(VkBaseInStructure *structure);\n")

    output_c_file.write("#include <stdlib.h>\n")
    output_c_file.write("#include <vulkan/vulkan.h>\n\n")
    output_c_file.write("#include \"logger.h\"\n")

    output_c_file.write(f"#include \"{output_h_file.name}\"\n\n")
    output_c_file.write("void *malloc_structure(VkBaseInStructure *structure) {\n")
    output_c_file.write("    switch(structure->sType) {\n")
    for struct_name, struct in structs.items():
        sType = struct.sType
        if sType is None:
            continue

        protect = None
        if isinstance(struct.base_type.defined_from, vulkan_object.VkExtension) and struct.base_type.defined_from.platform is not None:
            protect = struct.base_type.defined_from.platform.protect

        if protect is not None:
            output_c_file.write(f"#ifdef {protect}\n")

        output_c_file.write(f"        case {sType}:\n")
        output_c_file.write(f"            return malloc(sizeof({struct_name}));\n")

        if protect is not None:
            output_c_file.write(f"#endif\n")

    output_c_file.write("        default:\n")
    output_c_file.write("            log_message(LOG_LEVEL_DEBUG, \"unknown struct type: %d\", structure->sType);\n")
    output_c_file.write("            return NULL;\n")
    output_c_file.write("    }\n")
    output_c_file.write("}\n")

ACTUAL_PARAMETER = "ACTUAL_PARAM_PLACEHOLDER"
REQUIREMENTS_PARAMETER = "REQUIREMENTS_PARAM_PLACEHOLDER"
def get_comparator_string(member: vulkan_object.VkStructureMember, comparator: str, array_sel: str, target_ptr_depth: int) -> str:
    if target_ptr_depth == 0:
        return comparator.replace(ACTUAL_PARAMETER, f"actual->{member.name}{array_sel}").replace(REQUIREMENTS_PARAMETER, f"requirements->{member.name}{array_sel}")
    else:
        return comparator.replace(ACTUAL_PARAMETER, f"&(actual->{member.name}{array_sel})").replace(REQUIREMENTS_PARAMETER, f"&(requirements->{member.name}{array_sel})")
    

def write_compare_funcs(output_c_file: TextIOWrapper, output_h_file: TextIOWrapper, obj: vulkan_object.VulkanObject) -> None:
    output_c_file.write(FILE_COMMENT)
    output_h_file.write(FILE_COMMENT)
    
    output_h_file.write("#include <vulkan/vulkan.h>\n\n")
    
    output_c_file.write(f"#include <string.h>\n")
    output_c_file.write(f"#include \"{output_h_file.name}\"\n\n")

    temp_fallthroughtypes: set[str] = set()
    
    for struct_name, struct in obj.structures.items():
        if struct.sType is None:
            continue

        protect = None
        if isinstance(struct.base_type.defined_from, vulkan_object.VkExtension) and struct.base_type.defined_from.platform is not None:
            protect = struct.base_type.defined_from.platform.protect

        if protect is not None:
            output_c_file.write(f"#ifdef {protect}\n")
            output_h_file.write(f"#ifdef {protect}\n")
        
        output_h_file.write(f"bool vulkan_xml_compare_{struct_name}({struct_name}* actual, {struct_name}* requirements);\n")
        output_c_file.write(f"bool vulkan_xml_compare_{struct_name}({struct_name}* actual, {struct_name}* requirements)"+" {\n")

        member_comparators: list[str] = []

        ignore_names: list[str] = ["pNext"]
        for member in struct.members:
            if member.name in ignore_names:
                continue

            target_ptr_depth = 0
            comparator = f"{ACTUAL_PARAMETER} == {REQUIREMENTS_PARAMETER}"
            if member.c_type in obj.structures:
                target_ptr_depth = 1
                comparator = f"vulkan_xml_compare_{member.c_type}({ACTUAL_PARAMETER}, {REQUIREMENTS_PARAMETER})"
            elif member.c_type in obj.basetypes:
                comparator = f"{ACTUAL_PARAMETER} == {REQUIREMENTS_PARAMETER}"
            elif member.c_type in obj.bitmasks:
                # actual | ~requirements
                # actual or not(requirements)
                # a | r | out
                #---|---|-----
                # 0 | 0 |  1
                # 0 | 1 |  0
                # 1 | 0 |  1
                # 1 | 1 |  1
                comparator = f"({ACTUAL_PARAMETER} | ~{REQUIREMENTS_PARAMETER})"
            elif member.c_type in obj.handles:
                comparator = f"{ACTUAL_PARAMETER} == {REQUIREMENTS_PARAMETER}"
            elif member.c_type in obj.enumerations:
                comparator = f"{ACTUAL_PARAMETER} == {REQUIREMENTS_PARAMETER}"
            elif member.c_type in obj.function_pointers:
                comparator = f"{ACTUAL_PARAMETER} == {REQUIREMENTS_PARAMETER}"
            elif member.c_type == "void" and member.pointer_depth > 0:
                comparator = f"{ACTUAL_PARAMETER} == {REQUIREMENTS_PARAMETER}"
                target_ptr_depth = 1
            else:
                temp_fallthroughtypes.add(member.c_type)
                comparator = f"{ACTUAL_PARAMETER} == {REQUIREMENTS_PARAMETER}"

            array_sel = ""
            if len(member.array_lens) > 0:
                output_c_file.write(f"\tbool req_{member.name}_met = true;\n")
                depth = 1
                indexer = "i"
                # is a n dimensional array
                for i, length in enumerate(member.array_lens):
                    length_type = "size_t"
                    length_name = length.length
                    other_length_name = ""
                    internal_reference = False
                    if len(member.alternate_lengths) > 0:
                        length_name = member.alternate_lengths[i]
                    
                    for other_member in struct.members:
                        if isinstance(length_name,str) and other_member.name in length_name:
                            length_type = other_member.c_type
                            other_length_name = length_name.replace(other_member.name, f"requirements->{other_member.name}") # type:ignore
                            length_name = length_name.replace(other_member.name, f"actual->{other_member.name}")
                            internal_reference = True
                            break

                    if length.length == vulkan_object.NULL_TERMINATED:
                        comparator = f"strcmp({ACTUAL_PARAMETER}, {REQUIREMENTS_PARAMETER}) == 0"
                        target_ptr_depth = 1
                    elif vulkan_object.NULL_TERMINATED in length.attributes:
                        comparator = f"memcmp({ACTUAL_PARAMETER}, {REQUIREMENTS_PARAMETER}, MIN({length.length}, MIN(strlen({ACTUAL_PARAMETER}), strlen({REQUIREMENTS_PARAMETER}))+1))"
                        target_ptr_depth = 1
                    else:
                        array_sel += f"[{indexer}]"
                        if internal_reference:
                            output_c_file.write(f"{depth * "\t"}for({length_type} {indexer} = 0; {indexer} < {length_name} && {indexer} < {other_length_name}; ++{indexer})" + "{\n")
                        else:
                            output_c_file.write(f"{depth * "\t"}for({length_type} {indexer} = 0; {indexer} < {length_name}; ++{indexer})" + "{\n")
                        indexer = chr(ord(indexer) + 1)
                        depth += 1

                if struct_name == "VkImageBlit2" and (member.name == "dstOffsets" or member.name == "srcOffsets"):
                    print(f"\n\n{member.pointer_depth}, {comparator}, {array_sel}, {target_ptr_depth + depth - 1}")
                    print(get_comparator_string(member, comparator, array_sel, target_ptr_depth))
                    print("\n")

                output_c_file.write(f"{depth * "\t"}if(!({get_comparator_string(member, comparator, array_sel, target_ptr_depth)}))" + "{\n")
                output_c_file.write(f"{depth * "\t"}\treq_{member.name}_met = false;\n")
                output_c_file.write(f"{depth * "\t"}" + "}\n")

                output_c_file.write(f"\t{(depth - 1) * "}"}\n")
                comparator = f"req_{member.name}_met"
                target_ptr_depth = -1

            member.pointer_depth
            member_comparators.append(get_comparator_string(member, comparator, array_sel, target_ptr_depth))

        # the IF statement 
        output_c_file.write("    if (\n")

        for index, comparator in enumerate(member_comparators):
            if index != 0:
                output_c_file.write(" &&\n")
            output_c_file.write(f"        {comparator}")

        output_c_file.write("\n    ) {\n")
        output_c_file.write("        return true;\n")
        output_c_file.write("    }\n")
        output_c_file.write("    return false;\n")

        output_c_file.write("}\n") # close the function body

        if protect is not None:
            output_c_file.write(f"#endif\n")
            output_h_file.write(f"#endif\n")

    logging.info(f"fall through types: {temp_fallthroughtypes}")


if __name__ == "__main__":
    logging.basicConfig(
        level=logging.NOTSET,
        format='[%(asctime)s] [%(levelname)s]: %(message)s',
        datefmt='%Y-%m-%d %H:%M:%S'
    )

    if not (len(sys.argv) == 3 or len(sys.argv) == 4):
        print("usage: python parse.py <vulkan version> <path to ouput directory> <path to tmp dir>")
        exit(1)

    VULKAN_VERSION = sys.argv[1]
    OUTPUT_DIR = sys.argv[2]
    TEMP_DIR_PATH = sys.argv[3]
    
    os.makedirs(TEMP_DIR_PATH, exist_ok=True)
    logging.info(f"args:\n\t{sys.argv[0]}\n\t{sys.argv[1]}\n\t{sys.argv[2]}")

    ### pull the correct vk.xml for the current vulkan api version being used/linked ###

    # git clone repo for vk.xml
    # checkout proper tag
    # copy vk.xml
    # TODO: add flag to rm -rf temp files
    try:
        if not os.path.exists(f"{TEMP_DIR_PATH}/Vulkan-Docs"):
            with chdir(TEMP_DIR_PATH):
                subprocess.call(["git", "clone", "https://github.com/KhronosGroup/Vulkan-Docs.git"])
        with chdir(f"{TEMP_DIR_PATH}/Vulkan-Docs"):
            subprocess.call(["git", "checkout", f"tags/v{VULKAN_VERSION}"])
            
        subprocess.call(["cp", f"{TEMP_DIR_PATH}/Vulkan-Docs/xml/vk.xml", f"{TEMP_DIR_PATH}/vk.xml"]) # build/tmp/Vulkan-Docs/xml/vk.xml
    except:
        exit(-1)
    
    with (
        open(f"{OUTPUT_DIR}/{FILE_PREPEND}_struct_copy.c", "w") as copy_structure_c_file,
        open(f"{OUTPUT_DIR}/{FILE_PREPEND}_struct_copy.h", "w") as copy_structure_h_file,
        open(f"{OUTPUT_DIR}/{FILE_PREPEND}_struct_compare.c", "w") as compare_structure_switch_c_file,
        open(f"{OUTPUT_DIR}/{FILE_PREPEND}_struct_compare.h", "w") as compare_structure_switch_h_file,
        open(f"{OUTPUT_DIR}/{FILE_PREPEND}_struct_compare_functions.c", "w") as compare_structure_funcs_c_file,
        open(f"{OUTPUT_DIR}/{FILE_PREPEND}_struct_compare_functions.h", "w") as compare_structure_funcs_h_file
    ):
        logging.info(f"vulkan version {VULKAN_VERSION}")
        obj = vulkan_object.get_vulkan_object(f"{TEMP_DIR_PATH}/vk.xml", 1, 4, ["vulkan"])

        if obj is None:
            logging.error("unable to parse vk.xml")
            exit(-1)
        
        write_copy_struct(copy_structure_c_file, copy_structure_h_file, obj.structures)
        write_compare_funcs(compare_structure_funcs_c_file, compare_structure_funcs_h_file, obj)
        exit(-1)
        