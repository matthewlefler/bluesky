import xml.etree.ElementTree as ET

import vulkan_objects_dir.extensions, vulkan_objects_dir.features, vulkan_objects_dir.platforms, vulkan_objects_dir.validation
from vulkan_objects_dir.util import xml_util
from vulkan_objects_dir.vulkan_objects import *

import vulkan_objects_dir.vulkan_objects_types_dir.types

def get_vulkan_object(xml_file_path: str, api_version_major: int, api_version_minor: int, target_apis: list[str] = ["vulkan"]) -> VulkanObject | None:
    api_version_patch = 0 # again this is here for completeness's sake, but also if this becomes important at any points it should be easier to implement
    root = ET.parse(xml_file_path).getroot()
    # remove comments
    xml_util.remove_all_tags(root, "comment")

    target_api_version = VkVersion(api_version_major, api_version_minor, api_version_patch)
    dependencies.set_target_api_version(target_api_version)

    platforms = vulkan_objects_dir.platforms.get_platforms(root)

    features = vulkan_objects_dir.features.get_features(root)
    extensions = vulkan_objects_dir.extensions.get_extensions(root, platforms)

    dependencies.set_dictionaries(extensions, features)

    valid_features = vulkan_objects_dir.features.meets_minimum_api_version(features, target_api_version)
    valid_extensions = vulkan_objects_dir.extensions.filter_by_supported_apis(extensions, target_apis)
    valid_extensions = vulkan_objects_dir.extensions.validate_extensions(valid_extensions)

    element_list = vulkan_objects_dir.validation.combine_features_extensions(valid_extensions, valid_features, target_apis)

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
    ) = vulkan_objects_dir.vulkan_objects_types_dir.types.get_all_types(root, element_list)

    return VulkanObject(
        version=target_api_version,
        readable_version_name=target_api_version.get_name(),
        supported_apis=target_apis,

        platforms  = platforms,
        extensions = valid_extensions,
        features   = valid_features,

        includes          = includes,          # dict(),
        defines           = defines,           # dict(),
        basetypes         = basetypes,         # dict(),
        bitmasks          = bitmasks,          # dict(),
        handles           = handles,           # dict(),
        enumerations      = enumerations,      # dict(),
        function_pointers = function_pointers, # dict(),
        structures        = structures,        # dict(),
        unions            = unions             # dict(),
    )