import logging
import xml.etree.ElementTree as ET

from vulkan_objects_dir import vulkan_objects
from vulkan_objects_dir.vulkan_objects_types_dir import types

def parse_member(element: ET.Element[str]) -> vulkan_objects.VkUnionMember | None:
    selection = element.get("selection")
    name_element = element.find("name")
    type_tag = element.find("type")
    if name_element is None or name_element.text is None:
        logging.error("unions.py -> parse_member: name or name.text is None")
        return None
    if selection is None:
        logging.error("unions.py -> parse_member: selection is None")
        return None
    if type_tag is None or type_tag.text is None:
        logging.error("unions.py -> parse_member: type_tag or type_tag.text is None")
        return None

    array_lens = types.get_arrays(element)
    lengths = element.get("len")
    if lengths is not None:
        lengths = lengths.split(",")
        for length, array_length in zip(lengths, array_lens):
            array_length.attributes.append(length)

    alt_lens_temp = element.get("altlen")
    if alt_lens_temp is not None:
        alt_lens: list[str] = alt_lens_temp.split(",")
        for alt_len, length in zip(alt_lens, array_lens):
            length.alternate_length = alt_len

    optional = element.get("optional")
    if optional is not None:
        optional = [bool(x) for x in optional.split(",")]

    pointer_depth = 0
    pointer_str = type_tag.tail
    if pointer_str is not None:
        pointer_depth = pointer_str.count("*")

    externally_synced = element.get("externsync")
    if externally_synced is not None:
        externally_synced = bool(externally_synced)
    else:
        externally_synced = False

    allowed_values = element.get("values")
    limit_type = element.get("limittype")

    return vulkan_objects.VkUnionMember(
        name_element.text,
        array_lens,
        optional,
        externally_synced,
        allowed_values,
        limit_type,
        type_tag.text,
        pointer_depth
    )

def parse_union(element: ET.Element[str], defined_from: vulkan_objects.VkExtension | vulkan_objects.VkFeature) -> vulkan_objects.VkUnion | None:
    name = element.get("name")
    if name is None:
        logging.error("parse_union: name is None")
        return None

    members: list[vulkan_objects.VkUnionMember] = []
    for element in element.findall("member"):
        member = parse_member(element)
        if member is None:
            logging.error("parse_union: member is None")
            continue
        members.append(member)

    return vulkan_objects.VkUnion(
        vulkan_objects.VkType(
            vulkan_objects.VkElement(
                element,
                name,
                vulkan_objects.ElementValid.VALID
            ),
            defined_from,
            vulkan_objects.types.Category.CATEGORY_UNION
        ),
        members
    )
