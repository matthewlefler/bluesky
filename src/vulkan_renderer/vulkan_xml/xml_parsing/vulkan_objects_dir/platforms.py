import xml.etree.ElementTree as ET

from vulkan_objects_dir import vulkan_objects

PLATFORM_TAG = "platform"

def get_platforms(root: ET.Element[str]) -> dict[str, vulkan_objects.VkPlatform]:
    platform_elements = root.findall(PLATFORM_TAG)
    return_dict: dict[str, vulkan_objects.VkPlatform] = dict()

    for platform_element in platform_elements:
        platform = parse_platform(platform_element)
        if platform is not None:
            return_dict[platform.base.name] = platform

    return return_dict


def parse_platform(element: ET.Element[str]) -> vulkan_objects.VkPlatform | None:
    name = element.get("name")
    protect = element.get("protect")

    if name is None or protect is None:
        return None

    # note: a platform is always valid if the protect statment is valid
    return vulkan_objects.VkPlatform(vulkan_objects.VkElement(element, name, protect, True))