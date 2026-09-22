import xml.etree.ElementTree as ET

from vulkan_objects_dir import vulkan_objects
from vulkan_objects_dir.vulkan_objects_types_dir import types

def parse_include(element: ET.Element[str]) -> vulkan_objects.VkInclude | None:
    name = element.get("name")

    if name is None:
        return None
        print("ERROR: include's element has no name")

    return vulkan_objects.VkInclude(vulkan_objects.VkType(
        vulkan_objects.VkElement(
            element, 
            name, 
            None, 
            vulkan_objects.ElementValid.VALID # its an include, of course its valid
        ),
        types.Category.CATEGORY_INCLUDE
    ))
