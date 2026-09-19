#!python
from io import TextIOWrapper
import sys

import vulkan_object

OUTPUT_DIR: str | None = None
FILE_PREPEND="bluesky_vulkan_xml"

def write_copy_struct(output_c_file: TextIOWrapper, output_h_file: TextIOWrapper, structs: dict):
    output_h_file.write("#include <vulkan/vulkan.h>\n\n")
    output_h_file.write("void *malloc_structure(VkBaseInStructure *structure);\n")

    output_c_file.write("#include <stdlib.h>\n")
    output_c_file.write("#include <vulkan/vulkan.h>\n\n")
    output_c_file.write("#include \"src/utilities/logger/logger.h\"\n")

    output_c_file.write(f"#include \"{output_h_file.name}\"\n\n")
    output_c_file.write("void *malloc_structure(VkBaseInStructure *structure) {\n")
    output_c_file.write("    switch(structure->sType) {\n")
    for struct_name in structs:
        struct = structs[struct_name]

        sType = struct.sType
        if sType is None:
            continue

        if struct.protect is not None:
            output_c_file.write(f"#ifdef {struct.protect}\n")

        output_c_file.write(f"        case {sType}:\n")
        output_c_file.write(f"            return malloc(sizeof({struct.name}));\n")

        if struct.protect is not None:
            output_c_file.write(f"#endif\n")

    output_c_file.write("        default:\n")
    output_c_file.write("            log_message(LOG_LEVEL_DEBUG, \"unknown struct type: %d\", structure->sType);")
    output_c_file.write("            return NULL;\n")
    output_c_file.write("    }\n")
    output_c_file.write("}\n")


if __name__ == "__main__":
    if not (len(sys.argv) == 2 or len(sys.argv) == 3):
        print("usage: python parse.py <path to ouput directory> [alternate vk.xml file]")
        exit(1)

    OUTPUT_DIR = sys.argv[1]

    ALT_XML = None
    if len(sys.argv) >= 3:
        ALT_XML = sys.argv[2]

    with (
        open(f"{OUTPUT_DIR}/{FILE_PREPEND}_struct_copy.c", "w") as copy_structure_c_file,
        open(f"{OUTPUT_DIR}/{FILE_PREPEND}_struct_copy.h", "w") as copy_structure_h_file,
        open(f"{OUTPUT_DIR}/{FILE_PREPEND}_struct_compare.c", "w") as compare_structure_switch_c_file,
        open(f"{OUTPUT_DIR}/{FILE_PREPEND}_struct_compare.h", "w") as compare_structure_switch_h_file,
        open(f"{OUTPUT_DIR}/{FILE_PREPEND}_struct_compare_functions.c", "w") as compare_structure_funcs_c_file,
        open(f"{OUTPUT_DIR}/{FILE_PREPEND}_struct_compare_functions.h", "w") as compare_structure_funcs_h_file
    ):
        
        # write_copy_struct(copy_structure_c_file, copy_structure_h_file, vk.structs)
        obj = vulkan_object.get_vulkan_object("vk.xml")