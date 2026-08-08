# python file to parse the vk.xml file
# and create the {output_c_filename} c file
from io import TextIOWrapper
import xml.etree.ElementTree as ET
from collections.abc import Callable
from functools import partial
from dataclasses import dataclass
from enum import Enum

VULKAN_VERSION_MAJOR = 1
VULKAN_VERSION_MINOR = 4
VULKAN_VERSION = (VULKAN_VERSION_MAJOR << 4) + VULKAN_VERSION_MINOR

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

    tag = element.tag or ""
    text = element.text or ""
    tail = element.tail or ""
    attrib = element.attrib
    if not tag.isspace():
        print(f"{tag}:", end="")
    else:
        print(f"None:", end="")
    if not text.isspace():
        print(f" {text}", end="")
    if not tail.isspace():
        print(f" | {tail}", end="")
    if not len(attrib) <= 0:
        print(f" | {attrib}", end="")
    print("")


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

def calc_depends_struct(depends_struct: DependsStruct) -> int | list[str]:
    left = None
    right = None

    if isinstance(depends_struct.left, DependsStruct):
        left = calc_depends_struct(depends_struct.left)
    else:
        if depends_struct.left.startswith("VK_VERSION_"):
            if parse_VK_VERSION(depends_struct.left) <= VULKAN_VERSION:
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
        right = calc_depends_struct(depends_struct.right)
    else:
        if depends_struct.right.startswith("VK_VERSION_"):
            if parse_VK_VERSION(depends_struct.right) <= VULKAN_VERSION:
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

def parse_VK_VERSION(version: str) -> int:
    version = version.removeprefix("VK_VERSION_")
    major = int(version[0])
    minor = int(version[2])

    return (major << 4) + minor

def eval_depends(element: ET.Element[str]) -> bool:
    depends = element.get("depends")
    if depends is None:
        return True
    
    depends = parse_depends(depends)
    if depends is not None:
        return_val = calc_depends_struct(depends)
        if isinstance(return_val, int):
            if return_val == 1:
                return True
    return False

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
                return_val = calc_depends_struct(depends)
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

@dataclass
class struct_member:
    name: str
    base_type: str
    pointer_depth: int   # -1 = not a pointer
    array_len: list # -1 = not an array

@dataclass
class structure:
    name: str
    members: list[struct_member]

def parse_struct_member(member: ET.Element[str]) -> struct_member | None:
    # <member api="list of api-s" noautovalidity="bool" optional="bool">
    #   <type>type</type>****...
    #   <name>name</name>[array_len]
    #   <comment>comment</comment>
    # </member>
    member_api = member.get("api")
    if member_api is not None and "vulkan" not in member_api.split(","):
        return None
    
    member_type = member.find("type")
    member_name = member.find("name")
    member_enum = member.findall("enum")
    pointer_str = ""
    if member_type is not None:
        pointer_str = member_type.tail or ""

    array_str = ""
    if member_name is not None:
        array_str = member_name.tail or ""    
    
    pointer_depth = -1
    if not pointer_str.isspace():
        pointer_depth = pointer_str.count("*")

    array_len = []
    if array_str.startswith("["):
        array_len_start = array_str.find("[")
        while array_len_start != -1:
            array_len_end = array_str.find("]", array_len_start)
            if array_len_end == -1:
                break

            array_len.append( int(array_str[array_len_start+1:array_len_end]) )

            array_len_start = array_str.find("[", array_len_start + 1)
        
        for enum in member_enum:
            array_len.append(enum.text)
            
            tail = enum.tail

            if tail is not None:
                array_len_start = tail.find("[")
                while array_len_start != -1:
                    array_len_end = tail.find("]", array_len_start)
                    array_len.append( int(tail[array_len_start:array_len_end]) )

                    array_len_start = tail.find("[", array_len_start + 1)

        
    if len(array_len) == 0:
        array_len = [-1]
    

    if member_type is not None and member_name is not None and member_type.text is not None and member_name.text is not None:
        return struct_member(member_name.text, member_type.text, pointer_depth, array_len)
    return None


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

def collect_vaild_enums(element: ET.Element[str]) -> list[ET.Element[str]]:
    extensions = list(element.iter("extension"))
    return_array = []

    for extension in extensions:
        if not "vulkan" in extension.get("supported", "").split(","):
            continue
        for require in extension:
            if eval_depends(require) == False:
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

def copy_extend_from(file_to_write_to: TextIOWrapper, enums: list[ET.Element[str]], extends_from: str):
    for enum in enums:
        pass
    

if __name__ == "__main__":
    with (
        open(xml_filename, "r") as xml_file,
        open(f"{output_c_file_prepend}_struct_copy", "w") as output_copy_file,
        open(f"{output_c_file_prepend}_struct_comparision", "w") as output_comparision_file
    ):
        tree_root = ET.parse(xml_file).getroot()

        valid_extensions = collect_valid_extensions(tree_root)        
        print(f"got {len(valid_extensions)} valid extensions")

        collected_structures = collect_structures(tree_root)
        print(f"got {len(collected_structures)} structures")

        valid_enums = collect_vaild_enums(tree_root)
        print(f"got {len(valid_enums)} valid enums")

        

        