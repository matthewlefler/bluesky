import vulkan_objects
import dependencies

import xml.etree.ElementTree as ET

EXTENSION_TAG_NAME = "extension"

def get_extensions(root: ET.Element[str], platforms: dict[str, vulkan_objects.VkPlatform]) -> dict[str, vulkan_objects.VkExtension]:
    extensions = root.findall(EXTENSION_TAG_NAME)
    return_dict: dict[str, vulkan_objects.VkExtension] = dict()

    for extension_element in extensions:
        extension = parse_extension(extension_element, platforms)
        if extension is not None:
            return_dict[extension.base.name] = extension

    return return_dict


def parse_extension(extension_element: ET.Element[str], platforms: dict[str, vulkan_objects.VkPlatform]) -> vulkan_objects.VkExtension | None:
    # attributes:
    # - supported     = list of `,` seperated strings, the api this extension is supported in
    # - name          = string
    # - depends       = depends string (see: dependencies module)
    # - number        = extension id number
    # - type          = extension type, "instance" or "device"
    # - promotedto    = extension or feature this is promoted to
    # - depreciatedby = extension or feature this is depreciated by
    # - obsoleted_by  = extension or feature this is obsoleted by
    # - provisional   = `true` or `None`
    # - platform      = platform name

    supported_apis = extension_element.get("supported")
    id_number      = extension_element.get("number")
    name           = extension_element.get("name")
    depends        = extension_element.get("depends")
    ext_type       = extension_element.get("type")

    promoted_to    = extension_element.get("promotedto")
    depreciated_by = extension_element.get("deprecatedby")
    obsoleted_by   = extension_element.get("obsoletedby")
    provisional    = extension_element.get("provisional")

    platform = extension_element.get("platform")

    if name is None:
        return None

    if depends is not None:
        depends = dependencies.parse_depend_string(depends)

    if supported_apis is not None:
        supported_apis = supported_apis.split(",")

    if provisional is not None:
        provisional = bool(provisional)

    if id_number is not None:
        id_number = int(id_number)

    if platform is not None:
        if platform not in platforms:
            print(f"ERROR: platform {platform} in given platforms")
        else:
            platform = platforms[platform]

    return vulkan_objects.VkExtension(
        vulkan_objects.VkElement( # base element
            name, # name
            None, # protect string
            vulkan_objects.ElementValid.UNKNOWN # is the element valid, unknown b/c validation requires all features and extensions
        ),
        supported_apis,
        id_number,
        ext_type,
        platform,
        depends,
        promoted_to,
        depreciated_by,
        obsoleted_by,
        provisional
    )

def validate_extensions(extensions: dict[str, vulkan_objects.VkExtension]) -> dict[str, vulkan_objects.VkExtension]:
    """
    vaildates the input extensions, and return a dictionary containing the valid extensions
    """
    valid_extensions: dict[str, vulkan_objects.VkExtension] = dict()

    for extension_name in extensions:
        extension = extensions[extension_name]

        