import logging
import xml.etree.ElementTree as ET

from vulkan_objects_dir import vulkan_objects
from vulkan_objects_dir.vulkan_objects_types_dir import types

def parse_basetype(element: ET.Element[str], defined_from: vulkan_objects.VkFeature | vulkan_objects.VkExtension) -> vulkan_objects.VkBasetype | None:
    name = element.find("name")
    if name is not None:
        name = name.text

    if name is None:
        logging.error("parse_basetype: name is None")
        return None

    type_str = element.find("type")
    if type_str is not None:
        type_str = type_str.text
    # TODO: parse (#ifdef _objc) and etc.

    return vulkan_objects.VkBasetype(
        vulkan_objects.VkType(
            vulkan_objects.VkElement(
                element,
                name,
                vulkan_objects.ElementValid.VALID
            ),
            defined_from,
            types.Category.CATEGORY_BASETYPE
        ),
        type_str
    )
