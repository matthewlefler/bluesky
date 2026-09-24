import logging
import xml.etree.ElementTree as ET

from vulkan_objects_dir import vulkan_objects
from vulkan_objects_dir.vulkan_objects_types_dir import types

def parse_include(element: ET.Element[str], defined_from: vulkan_objects.VkExtension | vulkan_objects.VkFeature) -> vulkan_objects.VkInclude | None:
    name = element.get("name")

    if name is None:
        logging.error("include's element has no name")
        return None

    return vulkan_objects.VkInclude(vulkan_objects.VkType(
        vulkan_objects.VkElement(
            element, 
            name, 
            vulkan_objects.ElementValid.VALID # its an include, of course its valid
        ),
        defined_from,
        types.Category.CATEGORY_INCLUDE
    ))
