import logging
import xml.etree.ElementTree as ET

from vulkan_objects_dir import vulkan_objects

def parse_function_pointer(element: ET.Element[str], defined_from: vulkan_objects.VkFeature | vulkan_objects.VkExtension) -> vulkan_objects.VkFunctionPointer | None:
    name = None
    proto = element.find("proto")
    if proto is not None:
        name_tag = proto.find("name")
        if name_tag is not None:
            name = name_tag.text
    
    if name is None:
        logging.error("parse_function_pointer: name is None")
        return None
    
    return vulkan_objects.VkFunctionPointer(
        vulkan_objects.VkType(
            vulkan_objects.VkElement(
                element,
                name,
                vulkan_objects.ElementValid.VALID
            ),
            defined_from,
            vulkan_objects.types.Category.CATEGORY_FUNCTION_POINTER
        )
    )
