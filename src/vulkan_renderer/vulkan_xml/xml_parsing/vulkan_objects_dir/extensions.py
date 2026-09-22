from vulkan_objects_dir import vulkan_objects
from vulkan_objects_dir import dependencies

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

def filter_by_supported_apis(extensions: dict[str, vulkan_objects.VkExtension], supported_apis: list[str]) -> dict[str, vulkan_objects.VkExtension]:
    """
    returns all extension that support at least one of the apis in `supported_apis`
    """
    valid_extensions: dict[str, vulkan_objects.VkExtension] = dict()

    for extension_name, extension in extensions.items():
        for api in apis:
            if api in extension.supported_apis:
                valid_extensions[extension_name] = extension

    return valid_extensions

def validate_extensions(extensions: dict[str, vulkan_objects.VkExtension], target_api_version: VkVersion) -> dict[str, vulkan_objects.VkExtension]:
    """
    vaildates the input extensions, and return a dictionary containing the valid extensions
    """
    valid_extensions: dict[str, vulkan_objects.VkExtension] = dict()

    keep_going = True
    while keep_going:
        keep_going = False
        for extension_name, extension in extensions.items():
            if extension.base.valid != vulkan_objects.ElementValid.UNKNOWN:
                continue

            valid = vulkan_objects.ElementValid.VALID
            if extension.depends is not None:
                valid = dependencies.validate(extension.depends, target_api_version, extensions)

            valid_extensions[extension_name].base.valid = vulkan_objects.ElementValid.INVALID
            if valid == vulkan_objects.ElementValid.VALID:
                valid_extensions[extension_name] = extension
                extensions[extension_name]
            if valid == vulkan_objects.ElementValid.UNKNOWN:
                keep_going == True

                