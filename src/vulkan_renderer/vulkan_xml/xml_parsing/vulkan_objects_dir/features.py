import xml.etree.ElementTree as ET

from vulkan_objects_dir import vulkan_objects
from vulkan_objects_dir import dependencies

FEATURE_TAG_NAME = "feature"

def get_features(root: ET.Element[str]) -> dict[str, vulkan_objects.VkFeature]:
    features = root.findall(FEATURE_TAG_NAME)
    return_dict: dict[str, vulkan_objects.VkFeature] = dict()

    for feature_element in features:
        feature = parse_feature(feature_element)
        return_dict[feature.base.name] = feature

    return return_dict

def parse_feature(feature_element: ET.Element[str]) -> vulkan_objects.VkFeature | None:
    # attributes:
    # - api     = list of `,` seperated strings
    # - name    = string
    # - number  = version number
    # - depends = depends string
    apis    = feature_element.get("api")
    name    = feature_element.get("name")
    number  = feature_element.get("number")
    depends = feature_element.get("depends")

    if name is None:
        return None

    if depends is not None:
        depends = dependencies.parse_depend_string(depends)

    if apis is not None:
        apis = apis.split(",")

    if number is not None:
        versions = [int(x) for x in number.split(".")]
        number = vulkan_objects.VkVersion(versions[0], versions[1], 0)

    return vulkan_objects.VkFeature(
        vulkan_objects.VkElement( 
            feature_element, # base element
            name, # name
            None, # protect string
            vulkan_objects.ElementValid.UNKNOWN # is the element valid, unknown b/c validation requires all features and extensions
        ),
        apis, # list of api strings or none
        number, # version number
        depends # dependencies
    )

def meets_minimum_api_version(features: dict[str, vulkan_objects.VkFeature], target_api_version: vulkan_objects.VkVersion) -> dict[str, vulkan_objects.VkFeature]:
    valid_feature: dict[str, vulkan_objects.VkFeature] = dict()

    for feature_name, feature in features.items():
        if feature.version_number.Major >= target_api_version.Major:
            continue
        if feature.version_number.Major == target_api_version.Major:
            if feature.version_number.Minor >= target_api_version.Minor:
                continue

        valid_feature[feature_name] = feature

    return valid_feature