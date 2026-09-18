import vulkan_objects
import dependencies

import xml.etree.ElementTree as ET

EXTENSION_TAG_NAME = "extension"

def get_extensions(root: ET.Element[str]) -> dict[str, vulkan_objects.VkFeature]:
    extensions = root.findall(EXTENSION_TAG_NAME)
    return_dict: dict[str, vulkan_objects.VkFeature] = dict()

    for extension_element in extensions:
        feature = parse_extension(feature_element)
        return_dict[feature.base.name] = feature

    return return_dict

def parse_extension(extension_element: ET.Element[str]) -> vulkan_objects.VkExtension | None:
    # attributes:
    # - api     = list of `,` seperated strings
    # - name    = string
    # - depends = depends string
    supported_apis = extension_element.get("supported")
    version_number = extension_element.get("number")
    name     = extension_element.get("name")
    depends  = extension_element.get("depends")
    ext_type = extension_element.get("type")

    promoted_to = extension_element.get("promotedto")
    depreciated_by = extension_element.get("deprecatedby")
    obsoleted_by = extension_element.get("obsoletedby")
    provisional = extension_element.get("provisional")

    if name is None:
        return None

    if depends is not None:
        depends = dependencies.parse_depend_string(depends)

    if supported_apis is not None:
        supported_apis = supported_apis.split(",")

    if provisional is not None:
        provisional = bool(provisional)

    return vulkan_objects.VkExtension(
        vulkan_objects.VkElement( # base element
            name, # name
            None, # protect string
            vulkan_objects.ElementValid.UNKNOWN # is the element valid, unknown b/c validation requires all features and extensions
        ),
        supported_apis,
        version_number,
        ext_type,
        depends,
        promoted_to,
        depreciated_by,
        obsoleted_by,
        provisional
    )