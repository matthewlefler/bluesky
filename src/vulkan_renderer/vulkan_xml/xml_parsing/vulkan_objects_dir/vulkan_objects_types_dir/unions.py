import logging
import xml.etree.ElementTree as ET

from vulkan_objects_dir import vulkan_objects

def parse_union(element: ET.Element[str], defined_from: vulkan_objects.VkExtension | vulkan_objects.VkFeature) -> vulkan_objects.VkUnion | None:
    name = element.get("name")
    if name is None:
        logging.error("parse_union: name is None")
        return None

    members: list[vulkan_objects.VkUnionMember] = []

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
