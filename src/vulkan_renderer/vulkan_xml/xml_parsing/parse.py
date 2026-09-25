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
 * auto-generated file not not edit
 * @author matthew lefler | @skye
*/\n
"""

def write_copy_struct(output_c_file: TextIOWrapper, output_h_file: TextIOWrapper, structs: dict[str, vulkan_object.VkStructure]):
    output_h_file.write(FILE_COMMENT)
    output_h_file.write("#include <vulkan/vulkan.h>\n")
    output_h_file.write("#include <vulkan/vulkan_core.h>\n\n")
    output_h_file.write("void *malloc_structure(VkBaseInStructure *structure);\n")

    output_c_file.write(FILE_COMMENT)
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
    # git clone repo for vk.xml
    # checkout proper tag
    # copy vk.xml
    # rm -rf repo
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
            exit(-1)
        
        write_copy_struct(copy_structure_c_file, copy_structure_h_file, obj.structures)
        