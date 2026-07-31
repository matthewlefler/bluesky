# python file to parse the vk.xml file
# and create the {output_c_filename} c file
import xml.etree.ElementTree as ET
from collections.abc import Callable
from functools import partial
from dataclasses import dataclass
from enum import Enum

xml_filename = "vk.xml"
output_c_file_prepend = "bluesky_vulkan_xml"

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

class DependsOperation(Enum):
    OR = 1
    AND = 2

@dataclass
class DependsStruct:
    operation: DependsOperation
    left: DependsStruct | str
    right: DependsStruct | str

def parse_depends(string: str) -> DependsStruct | None:
    return parse_depends_recurse([string])

def parse_depends_recurse(string: list[str]) -> DependsStruct | None:
    # , is or
    OR_CHAR = ","
    # + is and
    AND_CHAR = "+"
    # ( and ) define order
    OPEN_PAREN = "("
    CLOSE_PAREN = ")"
        
    depends_operation = None
    left = None
    right = None
    name = ""

    while True:
        if len(string[0]) <= 0:
            break
        char = string[0][0]
        string[0] = string[0][1:] # remove first character (pop it)
        
        if char == OR_CHAR:
            depends_operation = DependsOperation.OR
            name = ""
        elif char == AND_CHAR:
            depends_operation = DependsOperation.AND
            name = ""
        elif char == OPEN_PAREN:
            paresed = parse_depends_recurse(string)
            if left == None:
                left = paresed
            else:
                right = paresed
        elif char == CLOSE_PAREN:
            break
        else:
            index = 0
            while True:
                if index >= len(string[0]) or string[0][index] == OR_CHAR or string[0][index] == AND_CHAR or string[0][index] == CLOSE_PAREN:
                    break
                index += 1    
            name = char + string[0][0:index] # consume name of extension
            string[0] = string[0][index:]

            if left == None:
                left = name
            else:
                right = name

    if depends_operation == None or left == None or right == None:
        return None
    # print(f"parsed, got {left} {depends_operation} {right}")
    # print(f"remaining string: {string[0]}")
    return DependsStruct(depends_operation, left, right)

def print_depends_struct(depends_struct: DependsStruct, level = 0):
    left = depends_struct.left
    right = depends_struct.right
    operation = depends_struct.operation
    if isinstance(left, str):
        print(level * "  " + left)
    else:
        print_depends_struct(left, level + 1)

    if operation == DependsOperation.OR:
        print(level * "  " + "or")
    else:
        print(level * "  " + "and")

    if isinstance(right, str):
        print(level * "  " + right)
    else: 
        print_depends_struct(right, level + 1)


def collect_enums(element: ET.Element[str]) -> list[ET.Element[str]]:
    extensions = element.findall("extension")
    return_array = []

    for extension in extensions:
        if not "vulkan" in extension.get("supported", "").split(","):
            continue
        for require in extension:
            require_depends = require.get("depends")
            if require_depends != None:
                parse_depends(require_depends)


        pass

    return return_array


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

if __name__ == "__main__":
    with (
        open(xml_filename, "r") as xml_file,
        open(f"{output_c_file_prepend}_struct_copy", "w") as output_comparision_file,
        open(f"{output_c_file_prepend}_struct_comparision", "w") as output_comparision_file
    ):
        error_count = 0

        temp = parse_depends("(vk_a,vk_b)+vk_c")
        if temp is not None:
            print_depends_struct(temp)
        else:
            print("got None")

        tree = ET.parse(xml_file).getroot()

        print(f"processed {0} structures")
