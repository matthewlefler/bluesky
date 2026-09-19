import xml.etree.ElementTree as ET

import vulkan_objects_dir.extensions
import vulkan_objects_dir.features
import vulkan_objects_dir.platforms
import vulkan_objects_dir.vulkan_objects

def get_vulkan_object(xml_file_path: str, api_version_major: int = 1, api_version_minor: int = 4, target_apis: list[str] = ["vulkan"]) -> vulkan_objects_dir.vulkan_objects.VulkanObject | None:
    root = ET.parse(xml_file_path).getroot()

    platforms = vulkan_objects_dir.platforms.get_platforms(root)
    features = vulkan_objects_dir.features.get_features(root)
    extensions = vulkan_objects_dir.extensions.get_extensions(root, platforms)

    api_version_patch = 0
    return vulkan_objects_dir.vulkan_objects.VulkanObject(
        vulkan_objects_dir.vulkan_objects.VkVersion(api_version_major, api_version_minor, api_version_patch),
        f"{api_version_major}.{api_version_minor}.{api_version_patch}",
        target_apis,
        extensions,
        features,
        
    )