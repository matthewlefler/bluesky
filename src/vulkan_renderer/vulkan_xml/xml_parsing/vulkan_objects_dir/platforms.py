import xml.etree.ElementTree as ET

from vulkan_objects_dir import vulkan_objects

PLATFORM_TAG = "platform"
PLATFORMS_TAG = "platforms"

def get_platforms(root: ET.Element[str]) -> dict[str, vulkan_objects.VkPlatform]:
    platform_elements = root.findall(PLATFORMS_TAG)
    return_dict: dict[str, vulkan_objects.VkPlatform] = dict()

    for platforms_element in platform_elements:
        for platform_element in platforms_element:
            if platform_element.tag != PLATFORM_TAG:
                continue

            platform = parse_platform(platform_element)
            if platform is not None:
                return_dict[platform.base.name] = platform

    return return_dict


def parse_platform(element: ET.Element[str]) -> vulkan_objects.VkPlatform | None:
    name = element.get("name")
    protect = element.get("protect")

    if name is None:
        return None

    # note: a platform is always valid if the protect statment is valid
    return vulkan_objects.VkPlatform(vulkan_objects.VkElement(element, name, vulkan_objects.ElementValid.VALID), protect)