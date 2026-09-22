import xml.etree.ElementTree as ET

import vulkan_objects_dir.extensions
import vulkan_objects_dir.features
import vulkan_objects_dir.platforms
from vulkan_objects_dir.vulkan_objects import *

import vulkan_objects_dir.vulkan_objects_types_dir.types

def get_vulkan_object(xml_file_path: str, api_version_major: int, api_version_minor: int, target_apis: list[str] = ["vulkan"]) -> vulkan_objects_dir.vulkan_objects.VulkanObject | None:
    api_version_patch = 0 # again this is here for completeness's sake, but also if this becomes important at any points it should be easier to implement
    root = ET.parse(xml_file_path).getroot()

    target_api_version = vulkan_objects_dir.vulkan_objects.VkVersion(api_version_major, api_version_minor, api_version_patch)

    platforms = vulkan_objects_dir.platforms.get_platforms(root)

    features = vulkan_objects_dir.features.get_features(root)
    valid_features = vulkan_objects_dir.features.meets_minimum_api_version(features, target_api_version)

    extensions = vulkan_objects_dir.extensions.get_extensions(root, platforms)
    valid_extensions = vulkan_objects_dir.extensions.filter_by_supported_apis(extensions, target_apis)
    valid_extensions = vulkan_objects_dir.extensions.validate_extensions(valid_extensions, target_api_version)

    (
        includes,
        defines,
        basetypes,
        bitmasks,
        handles,
        enumerations,
        function_pointers,
        structures,
        unions
    ) = vulkan_objects_dir.vulkan_objects_types_dir.types.get_all_types(root)
    
    return vulkan_objects_dir.vulkan_objects.VulkanObject(
        version=target_api_version,
        readable_version_name=target_api_version.get_name(),
        supported_apis=target_apis,
        platforms=platforms,
        extensions=valid_extensions,
        features=valid_features,
        includes=includes,
        defines=defines,
        basetypes=basetypes,
        bitmasks=bitmasks,
        handles=handles,
        enumerations=enumerations,
        function_pointers=function_pointers,
        structures=structures,
        unions=unions
    )