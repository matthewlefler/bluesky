#!python
import logging
from io import TextIOWrapper
import sys
import subprocess
import os

import vulkan_object
from contextlib import chdir


# EXCESSIVE_DEBUG = True
EXCESSIVE_DEBUG = False

OUTPUT_DIR: str | None = None
FILE_PREPEND="bluesky_vulkan_xml"

FILE_COMMENT="""/**
 * auto-generated file DO NOT EDIT, change the generator functions instead
 * it is recommened to add these files to your .gitignore as well
 * @author matthew lefler | @skye
*/\n
"""

def write_malloc_struct(output_c_file: TextIOWrapper, output_h_file: TextIOWrapper, structs: dict[str, vulkan_object.VkStructure]) -> None:
    output_h_file.write(FILE_COMMENT)
    output_c_file.write(FILE_COMMENT)

    
    output_h_file.write("#include <vulkan/vulkan.h>\n\n")
    output_h_file.write("void *alloc_structure(VkBaseInStructure *structure);\n") # void *malloc(size_t __size)

    output_c_file.write("#include <stdlib.h>\n")
    output_c_file.write("#include <vulkan/vulkan.h>\n\n")
    output_c_file.write("#include \"logger.h\"\n")

    output_c_file.write(f"#include \"{output_h_file.name}\"\n\n")
    output_c_file.write("void *alloc_structure(VkBaseInStructure *structure) {\n")
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
        output_c_file.write(f"            return calloc(1, sizeof({struct_name}));\n")

        if protect is not None:
            output_c_file.write(f"#endif\n")

    output_c_file.write("        default:\n")
    output_c_file.write("            log_message(LOG_LEVEL_ERROR, \"in alloc_structure -> unknown struct type: %d\", structure->sType);\n")
    output_c_file.write("            return NULL;\n")
    output_c_file.write("    }\n")
    output_c_file.write("}\n")
    

def write_compare_funcs(output_c_file: TextIOWrapper, output_h_file: TextIOWrapper, obj: vulkan_object.VulkanObject) -> None:
    output_c_file.write(FILE_COMMENT)
    output_h_file.write(FILE_COMMENT)
    
    output_h_file.write("#include \"logger.h\"\n")
    output_h_file.write("#include <vulkan/vulkan.h>\n\n")
    
    output_c_file.write(f"#include <string.h>\n")
    output_c_file.write(f"#include \"{output_h_file.name}\"\n\n")

    temp_fallthroughtypes: set[str] = set()

    output_h_file.write("bool vulkan_xml_compare_VkPhysicalDeviceFeatures2(VkPhysicalDeviceFeatures2* actual, VkPhysicalDeviceFeatures2* requirements);\n")
    output_c_file.write("bool vulkan_xml_compare_VkPhysicalDeviceFeatures2(VkPhysicalDeviceFeatures2* actual, VkPhysicalDeviceFeatures2* requirements) {\n")
    output_c_file.write("    if(\n")
    output_c_file.write("        actual->sType == requirements->sType &&\n")
    output_c_file.write("        vulkan_xml_compare_VkPhysicalDeviceFeatures(&actual->features, &requirements->features)\n")
    output_c_file.write("    ) {\n")
    output_c_file.write("        return true;\n")
    output_c_file.write("    }\n")
    output_c_file.write("    return false;\n")
    output_c_file.write("}\n")
    
    for struct_name, struct in obj.structures.items():
        if not (struct_name == "VkPhysicalDeviceFeatures" or (struct.extends is not None and "VkPhysicalDeviceFeatures2" in struct.extends)):
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
            if not (member.name == "sType" or member.name == "pNext"):
                if member.c_type != "VkBool32":
                    logging.error(f"write_compare_funcs -> structure {struct.base_type.base.name} has {member.c_type} {member.name} that is not \"VkBool32\" or is one of the \"sType\" or \"pNext\" fields")
                if member.pointer_depth > 0:
                    logging.info(f"write_compare_funcs -> structure {struct.base_type.base.name} has {member.c_type} {member.name} that has a pointer depth more than 0")

            if member.name in ignore_names:
                continue

            if member.name == "sType":
                member_comparators.append(f"requirements->{member.name} == actual->{member.name}")
            else:
                # r | a | o
                # ---------
                # 0 | 0 | 1
                # 0 | 1 | 1
                # 1 | 0 | 0
                # 1 | 1 | 1
                member_comparators.append(f"!(requirements->{member.name} == VK_TRUE && actual->{member.name} == VK_FALSE)")
            
        if len(member_comparators) <= 0:
            logging.error(f"write_compare_funcs -> structure {struct.base_type.base.name} has no comparable fields?")
            output_c_file.write("return true;\n")
        else:
            if EXCESSIVE_DEBUG:
                output_c_file.write(f"log_message(LOG_LEVEL_DEBUG, \"write_compare_funcs -> comparing: {struct_name}\");\n")
                for member, comparator in zip(struct.members[0:1] + struct.members[2:], member_comparators):
                    output_c_file.write(f"log_message(LOG_LEVEL_DEBUG, \"    %d <- %d and %d\\t{member.name}\", {comparator}, actual->{member.name}, requirements->{member.name}); ")

            output_c_file.write("\n")

            output_c_file.write("    if(\n")
            first = True
            for comparator in member_comparators:
                if not first:
                    output_c_file.write(" &&\n")
                output_c_file.write(f"        {comparator}")
                first = False

            output_c_file.write("\n    ) {\n")
            output_c_file.write("        return true;\n")
            output_c_file.write("    }\n")
            output_c_file.write("    return false;\n")
        
        output_c_file.write("}\n")
        if protect is not None:
            output_c_file.write(f"#endif\n")
            output_h_file.write(f"#endif\n")

    if len(temp_fallthroughtypes) > 0:
        logging.error(f"fall through types: {temp_fallthroughtypes}")


def write_compare_funcs_switch(output_c_file: TextIOWrapper, output_h_file: TextIOWrapper, compare_funcs_h_file: TextIOWrapper, obj: vulkan_object.VulkanObject) -> None:
    output_c_file.write(FILE_COMMENT)
    output_h_file.write(FILE_COMMENT)

    output_h_file.write("#include <vulkan/vulkan.h>\n\n")
    
    output_c_file.write("#include \"logger.h\"\n")
    output_c_file.write(f"#include <string.h>\n")
    output_c_file.write(f"#include \"{output_h_file.name}\"\n\n")
    output_c_file.write(f"#include \"{compare_funcs_h_file.name}\"\n\n")

    output_c_file.write("bool compare_struct_extends_from_VkPhysicalDeviceFeatures2(VkBaseInStructure *actual, VkBaseInStructure *requirements) {\n")
    output_c_file.write("    switch(actual->sType) {\n")

    output_c_file.write("        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2:\n")
    output_c_file.write(f"            return vulkan_xml_compare_VkPhysicalDeviceFeatures2((VkPhysicalDeviceFeatures2*) actual, (VkPhysicalDeviceFeatures2*) requirements);\n")

    for struct_name, struct in obj.structures.items():
        sType = struct.sType
        if sType is None or struct.extends is None:
            continue

        if "VkPhysicalDeviceFeatures2" not in struct.extends:
            continue

        protect = None
        if isinstance(struct.base_type.defined_from, vulkan_object.VkExtension) and struct.base_type.defined_from.platform is not None:
            protect = struct.base_type.defined_from.platform.protect

        if protect is not None:
            output_c_file.write(f"#ifdef {protect}\n")

        output_c_file.write(f"        case {sType}:\n")
        output_c_file.write(f"            return vulkan_xml_compare_{struct_name}(({struct_name}*) actual, ({struct_name}*) requirements);\n")

        if protect is not None:
            output_c_file.write(f"#endif\n")

    output_c_file.write("        default:\n")
    output_c_file.write("            log_message(LOG_LEVEL_DEBUG, \"in compare_struct_extends_from_VkPhysicalDeviceFeatures2 -> unknown struct type: %d\", actual->sType);\n")
    output_c_file.write("            return false;\n")
    output_c_file.write("    }\n")
    output_c_file.write("    return false;\n")
    output_c_file.write("}\n")


def write_helper_print_VkStructureType(output_c_file: TextIOWrapper, output_h_file: TextIOWrapper, obj: vulkan_object.VulkanObject) -> None:
    output_h_file.write(FILE_COMMENT)
    output_c_file.write(FILE_COMMENT)

    output_h_file.write("#include <vulkan/vulkan.h>\n\n")
    output_h_file.write("char *helper_print_VkStructureType(VkBaseInStructure *structure);\n")

    output_c_file.write("#include <vulkan/vulkan.h>\n\n")
    output_c_file.write("#include \"logger.h\"\n")

    output_c_file.write(f"#include \"{output_h_file.name}\"\n\n")
    output_c_file.write("char *helper_print_VkStructureType(VkBaseInStructure *structure) {\n")
    output_c_file.write("    switch(structure->sType) {\n")
    for struct_name, struct in obj.structures.items():
        sType = struct.sType
        if sType is None:
            continue

        protect = None
        if isinstance(struct.base_type.defined_from, vulkan_object.VkExtension) and struct.base_type.defined_from.platform is not None:
            protect = struct.base_type.defined_from.platform.protect

        if protect is not None:
            output_c_file.write(f"#ifdef {protect}\n")

        output_c_file.write(f"        case {sType}:\n")
        output_c_file.write(f"            return \"{struct.sType}\";\n")

        if protect is not None:
            output_c_file.write(f"#endif\n")

    output_c_file.write("        default:\n")
    output_c_file.write("            log_message(LOG_LEVEL_ERROR, \"in helper_print_VkStructureType -> unknown struct type: %d\", structure->sType);\n")
    output_c_file.write("            return NULL;\n")
    output_c_file.write("    }\n")
    output_c_file.write("}\n")

    
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
                subprocess.call(["git", "clone", "https://github.com/KhronosGroup/Vulkan-Docs.git", "-q"])
        with chdir(f"{TEMP_DIR_PATH}/Vulkan-Docs"):
            subprocess.call(["git", "checkout", f"tags/v{VULKAN_VERSION}", "-q"])
            
        subprocess.call(["cp", f"{TEMP_DIR_PATH}/Vulkan-Docs/xml/vk.xml", f"{TEMP_DIR_PATH}/vk.xml"]) # build/tmp/Vulkan-Docs/xml/vk.xml
    except:
        exit(-1)

    with (
        open(f"{OUTPUT_DIR}/{FILE_PREPEND}_struct_copy.c", "w") as copy_structure_c_file,
        open(f"{OUTPUT_DIR}/{FILE_PREPEND}_struct_copy.h", "w") as copy_structure_h_file,
        open(f"{OUTPUT_DIR}/{FILE_PREPEND}_struct_compare.c", "w") as compare_structure_switch_c_file,
        open(f"{OUTPUT_DIR}/{FILE_PREPEND}_struct_compare.h", "w") as compare_structure_switch_h_file,
        open(f"{OUTPUT_DIR}/{FILE_PREPEND}_struct_compare_functions.c", "w") as compare_structure_funcs_c_file,
        open(f"{OUTPUT_DIR}/{FILE_PREPEND}_struct_compare_functions.h", "w") as compare_structure_funcs_h_file,
        open(f"{OUTPUT_DIR}/{FILE_PREPEND}_helper_print_VkStructureType.c", "w") as helper_print_VkStructureType_c_file,
        open(f"{OUTPUT_DIR}/{FILE_PREPEND}_helper_print_VkStructureType.h", "w") as helper_print_VkStructureType_h_file
    ):
        logging.info(f"vulkan version {VULKAN_VERSION}")
        obj = vulkan_object.get_vulkan_object(f"{TEMP_DIR_PATH}/vk.xml", 1, 4, ["vulkan"])

        if obj is None:
            logging.error("unable to parse vk.xml")
            exit(-1)
        
        write_malloc_struct(copy_structure_c_file, copy_structure_h_file, obj.structures)
        write_compare_funcs(compare_structure_funcs_c_file, compare_structure_funcs_h_file, obj)
        write_compare_funcs_switch(compare_structure_switch_c_file, compare_structure_switch_h_file, compare_structure_funcs_h_file, obj)
        write_helper_print_VkStructureType(helper_print_VkStructureType_c_file, helper_print_VkStructureType_h_file, obj)
