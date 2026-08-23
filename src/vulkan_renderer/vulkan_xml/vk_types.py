import xml.etree.ElementTree as ET
from dataclasses import dataclass

@dataclass
class vk_type:
    name: str
    category: str | None
    requires: str | None

type_name_to_base: dict[str, vk_type] = dict()
type_name_to_type: dict[str, vk_type] = dict()
type_constants: dict[str, str] = dict() # name to type

def resolve_types(root: ET.Element[str]) -> None:
    types_list = list(root.iter("types"))
    enums_list = list(root.iter("enums"))

    resolve_list: list[ET.Element[str]] = []
    for types in types_list:      
        for type_tag in types:
            name = type_tag.find("name")
            alt_name = type_tag.get("name")
            actual_type = type_tag.find("type")
            proto = type_tag.find("proto")

            alias = type_tag.get("alias")
            if alias is not None:
                resolve_list.append(type_tag)
                continue

            name_text = None
            if name is not None and name.text is not None:
                name_text = name.text
            elif alt_name is not None:
                name_text = alt_name
            elif proto is not None:
                proto_name = proto.find("name")
                if proto_name is not None and proto_name.text is not None:
                    name_text = proto_name.text
            
            if name_text is None:
                continue

            if actual_type is None or actual_type.text is None:
                type_name_to_base[name_text] = vk_type(name_text, type_tag.get("category"), type_tag.get("requires"))
            else:
                type_name_to_base[name_text] = vk_type(actual_type.text, type_tag.get("category"), type_tag.get("requires"))    

        for type_tag in resolve_list:
            name = type_tag.find("name")
            alt_name = type_tag.get("name")
            actual_type = type_tag.find("type")
            proto = type_tag.find("proto")

            name_text = None
            if alt_name is not None:
                name_text = alt_name
            elif name is not None and name.text is not None:
                name_text = name.text
            elif proto is not None:
                proto_name = proto.find("name")
                if proto_name is not None and proto_name.text is not None:
                    name_text = proto_name.text

            if name_text is None:
                print(f"name not found for {name}")
                continue

            alias = type_tag.get("alias")
            if alias not in type_name_to_base:
                print(f"alias not found for {name_text} with alias {alias}")
                continue
            else:
                type_name_to_base[name_text] = type_name_to_base[alias]

    for types in types_list:      
        for type_tag in types:
            name = type_tag.find("name")
            alt_name = type_tag.get("name")
            proto = type_tag.find("proto")

            alias = type_tag.get("alias")
            
            name_text = None
            if name is not None and name.text is not None:
                name_text = name.text
            elif alt_name is not None:
                name_text = alt_name
            elif proto is not None:
                proto_name = proto.find("name")
                if proto_name is not None and proto_name.text is not None:
                    name_text = proto_name.text
            
            if name_text is None:
                continue

            type_name_to_type[name_text] = vk_type(name_text, type_tag.get("category"), type_tag.get("requires"))  

    # resolve constants
    for enums in enums_list:
        # type="constants"
        if enums.get("type") != "constants":
            continue

        for enum in enums:
            name = enum.get("name")
            enum_type = enum.get("type")
            value = enum.get("value")
            if name is None or enum_type is None or value is None:
                continue
            type_constants[name] = enum_type

def get_vk_flag_type_bit_len(flag_name: str):
    base_type = type_name_to_base[flag_name]
    return int(base_type.name.removeprefix("uint").removesuffix("_t"))