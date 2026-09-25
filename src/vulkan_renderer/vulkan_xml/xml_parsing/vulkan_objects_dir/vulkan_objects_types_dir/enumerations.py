import logging
import xml.etree.ElementTree as ET

from vulkan_objects_dir import vulkan_objects

def parse_enumeration(element: ET.Element[str], defined_from: vulkan_objects.VkFeature | vulkan_objects.VkExtension) -> vulkan_objects.VkEnum | None:
    name = element.get("name")
    if name is None:
        logging.error("parse_enumeration: name is None")
        return None

    return vulkan_objects.VkEnum(
        vulkan_objects.VkType(
            vulkan_objects.VkElement(
                element,
                name,
                vulkan_objects.ElementValid.VALID
            ),
            defined_from,
            vulkan_objects.types.Category.CATEGORY_ENUMERATION
        ),
        [] # empty list
    )
