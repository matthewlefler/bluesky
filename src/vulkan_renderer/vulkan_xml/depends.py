from dataclasses import dataclass
from enum import Enum
import xml.etree.ElementTree as ET

import vk_version
import vk_structures as structures_py

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

def calc_depends_struct(depends_struct: DependsStruct, extension_name_valid: dict[str, int], structures: dict[str, structures_py.vk_structure]) -> int | list[str]:
    left = None
    right = None

    if isinstance(depends_struct.left, DependsStruct):
        left = calc_depends_struct(depends_struct.left, extension_name_valid, structures)
    else:
        if depends_struct.left.startswith("VK_VERSION_"):
            if vk_version.parse_VK_VERSION(depends_struct.left) <= vk_version.VULKAN_VERSION:
                left = 1
            else:
                left = 0
        elif "::" in depends_struct.left:
            names = depends_struct.left.split("::")
            struct_name = names[0]
            member_name = names[1]
            struct = structures.get(struct_name, None)
            if struct is None:
                left = 0
            else:
                left = 0
                for member in struct.members:
                    if member.name == member_name:
                        left = 1
                        break
        else:
            left = extension_name_valid[depends_struct.left]
            if left == -1:
                left = [depends_struct.left]

    if isinstance(depends_struct.right, DependsStruct):
        right = calc_depends_struct(depends_struct.right, extension_name_valid, structures)
    else:
        if depends_struct.right.startswith("VK_VERSION_"):
            if vk_version.parse_VK_VERSION(depends_struct.right) <= vk_version.VULKAN_VERSION:
                right = 1
            else:
                right = 0
        elif "::" in depends_struct.right:
            names = depends_struct.right.split("::")
            struct_name = names[0]
            member_name = names[1]
            struct = structures.get(struct_name, None)
            if struct is None:
                left = 0
            else:
                left = 0
                for member in struct.members:
                    if member.name == member_name:
                        left = 1
                        break
        else:
            right = extension_name_valid[depends_struct.right]
            if right == -1:
                right = [depends_struct.right]

    if isinstance(left, int) and isinstance(right, int):
        if depends_struct.operation == DependsOperation.OR:
            return left or right
        elif depends_struct.operation == DependsOperation.AND:
            return left and right
        else:
            raise RuntimeError(f"DependsOperation is not OR or AND: {depends_struct.operation}")
    else:
        return_array = []
        if isinstance(left, list):
            return_array = return_array + left
        if isinstance(right, list):
            return_array = return_array + right
        return return_array


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

def eval_depends(element: ET.Element[str], extension_name_valid: dict[str, int], structures: dict[str, structures_py.vk_structure]) -> bool:
    depends = element.get("depends")
    if depends is None:
        return True
    
    depends = parse_depends(depends)
    if depends is not None:
        return_val = calc_depends_struct(depends, extension_name_valid, structures)
        if isinstance(return_val, int):
            if return_val == 1:
                return True
    return False
