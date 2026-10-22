import logging
import xml.etree.ElementTree as ET

from vulkan_objects_dir import vulkan_objects
from vulkan_objects_dir.vulkan_objects_types_dir import types

def parse_member(structure_member_element: ET.Element[str]) -> vulkan_objects.VkStructureMember | None:
    name = None
    name_element = structure_member_element.find("name")
    if name_element is not None and name_element.text is not None:
        name = name_element.text

    if name is None:
        logging.error("struct member name is None")
        return None
    
    lengths = structure_member_element.get("len")
    alt_lens_temp = structure_member_element.get("altlen")

    type_tag = structure_member_element.find("type")
    if type_tag is None:
        logging.error("struct member does not have a type")
        return None
    pointer_depth = 0
    if type_tag.tail is not None:
        pointer_depth = type_tag.tail.count('*')

    temp_array_lengths: list[vulkan_objects.VkMemberArrayLen] = types.get_arrays(structure_member_element)

    optional = structure_member_element.get("optional")
    externally_synced = structure_member_element.get("externsync")
    allowed_values = structure_member_element.get("values")
    limit_type = structure_member_element.get("limittype")
    
    c_type = structure_member_element.find("type")
    if c_type is not None:
        c_type = c_type.text
    
    if c_type is None:
        logging.error("structures.py -> parse_member: c_type is None")
        return None
    

    if optional is not None:
        optional = [bool(x) for x in optional.split(",")]

    if externally_synced is not None:
        externally_synced = bool(externally_synced)
    else:
        externally_synced = False

    return vulkan_objects.VkStructureMember(
        name,
        temp_array_lengths,
        optional,
        externally_synced,
        allowed_values,
        limit_type,
        c_type,
        pointer_depth
    )

# def resolve_member_array_lengths(structure_members: list[vulkan_objects.VkStructureMember]) -> None:
#     for structure_member in structure_members:
#         for index, length in enumerate(structure_member.array_lens):
#             if isinstance(length, str):
#                 for other_structure_member in structure_members:
#                     if length == other_structure_member.name:
#                         # replace
#                         structure_member.array_lens[index] = other_structure_member

def parse_structure(structure_element: ET.Element[str], defined_from: vulkan_objects.VkFeature | vulkan_objects.VkExtension) -> vulkan_objects.VkStructure | None:
    name = structure_element.get("name")
    if name is None:
        return None

    sType = None
    members: list[vulkan_objects.VkStructureMember] = []

    for member_element in structure_element:
        member: vulkan_objects.VkStructureMember | None = parse_member(member_element)

        if member is None:
            logging.error(f"failed to parse structure member in struct {name}")
            continue

        if member.name == "sType":
            sType = member.allowed_values
            
        members.append(member)

    extends = structure_element.get("structextends")
    if extends is not None:
        extends = extends.split(",")

    returned_only = structure_element.get("returnedonly")
    allow_duplicate = structure_element.get("allowduplicate")
    alias = structure_element.get("alias")
    required_limit_type = structure_element.get("requiredlimittype")

    if returned_only is not None:
        returned_only = bool(returned_only)
    else:
        returned_only = False

    if allow_duplicate is not None:
        allow_duplicate = bool(allow_duplicate)
    else:
        allow_duplicate = False # TODO: check default

    return vulkan_objects.VkStructure(
        vulkan_objects.VkType(
            vulkan_objects.VkElement(
                structure_element,
                name,
                vulkan_objects.ElementValid.UNKNOWN
            ),
            defined_from,
            types.Category.CATEGORY_STRUCTURE
        ),
        sType,
        extends,
        returned_only,
        allow_duplicate,
        alias,
        required_limit_type,
        members
    )
