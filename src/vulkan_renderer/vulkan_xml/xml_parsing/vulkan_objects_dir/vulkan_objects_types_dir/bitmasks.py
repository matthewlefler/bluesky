import logging
import xml.etree.ElementTree as ET

from vulkan_objects_dir import vulkan_objects
from vulkan_objects_dir.vulkan_objects_types_dir import types

VKFLAGS = "VkFlags"
VKFLAGS64 = "VkFlags64"

def parse_bitmask(element: ET.Element[str], defined_from: vulkan_objects.VkFeature | vulkan_objects.VkExtension) -> vulkan_objects.VkBitMask | None:
    name = element.get("name")
    name_tag = element.find("name")
    if name is None and name_tag is not None:
        name = name_tag.text

    if name is None:
        logging.error("parse_bitmask: name is none")
        return None

    flag_type = element.find("type")
    if flag_type is not None:
        flag_type = flag_type.text
    if flag_type is None:
        logging.error("parse_bitmask: flag_type is none")
        return None

    bit_width = None
    if flag_type == VKFLAGS:
        bit_width = 32 # VKFLAGS is typedef'ed as a uint32_t
    if flag_type == VKFLAGS64:
        bit_width = 64 # VKFLAGS64 is typedef'ed as a uint64_t

    if bit_width == None:
        logging.error("parse_bitmask: bit_width is none")
        return None

    bit_values_enum_name = element.get("bitvalues")

    return vulkan_objects.VkBitMask(
        vulkan_objects.VkType(
            vulkan_objects.VkElement(
                element,
                name,
                vulkan_objects.ElementValid.VALID
            ),
            defined_from,
            types.Category.CATEGORY_BITMASK
        ),
        bit_width,
        bit_values_enum_name,
        flag_type
    )
