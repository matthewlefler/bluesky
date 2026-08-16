from dataclasses import dataclass
import xml.etree.ElementTree as ET

import enums
import extensions as extensions_py
import vk_types

@dataclass
class struct_member:
    name: str
    base_type: str
    pointer_depth: int   # -1 = not a pointer
    array_len: list # -1 = not an array
    optional: bool | None
    values: str | None

@dataclass
class vk_structure:
    name: str
    members: list[struct_member]
    
    ext: extensions_py.extension

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
    
    optional = member.get("optional")
    if optional is not None:
        optional = bool(optional)

    if member_type is not None and member_name is not None and member_type.text is not None and member_name.text is not None:
        return struct_member(member_name.text, member_type.text, pointer_depth, array_len, optional, member.get("values"))
    return None

struct_name_to_enum: dict[str, enums.vk_enum] = dict()
enum_name_to_struct: dict[str, vk_structure]  = dict()

def find_enums_from_structures(structures: list[vk_structure], enums: list[enums.vk_enum]):
    for structure in structures:
        for member in structure.members:

            if member.name == "sType" and member.values is not None:
                enum_name_to_struct[member.values] = structure

                for enum in enums:
                    if enum.name == member.values:
                        struct_name_to_enum[structure.name] = enum

                # stop it get some help
                break

def collect_structures(root: ET.Element[str]) -> list[vk_structure]:
    return_array = []
    type_tags = list(root.iter("type"))
    extensions = list(root.iter("extension"))

    for type_tag in type_tags:
        category = type_tag.get("category")
        name = type_tag.get("name")
        alias = type_tag.get("alias")
        if category != "struct" or name is None or alias is not None:
            continue
        
        members = type_tag.findall("member")
        collected_members = []
        for member in members:
            struct_type = parse_struct_member(member)
            if struct_type is None:
                continue
            collected_members.append(struct_type)

        ext = None
        for extension in extensions:
            for require in extension:
                for element in require:
                    if element.get("name") == name:
                        ext = extensions_py.parse_extension(extension)      
        if ext is None:
            continue
        return_array.append(vk_structure(name, collected_members, ext))    

    return return_array

def get_type_string(member: struct_member) -> str:
    return_str = f"{member.base_type}{(member.pointer_depth * "*")}"

    if member.array_len[0] != -1:
        for array in member.array_len:
            return_str += f"[{array}]"
    
    return return_str

def get_type_string_arg(base_type: str, pointer_depth: int, array_len: list) -> str:
    return_str = f"{base_type}{(pointer_depth * "*")}"

    if array_len[0] != -1:
        for array in array_len:
            return_str += f"[{array}]"
    
    return return_str