import xml.etree.ElementTree as ET

from vulkan_objects_dir import vulkan_objects

def validate_items(
    defines: dict[str, vulkan_objects.VkDefine],
    bitmasks: dict[str, vulkan_objects.VkBitMask],
    handles: dict[str, vulkan_objects.VkHandle],
    enums: dict[str, vulkan_objects.VkEnum],
    function_pointers: dict[str, vulkan_objects.VkFunctionPointer],
    structures: dict[str, vulkan_objects.VkStructure],
    unions: dict[str, vulkan_objects.VkUnion],

    valid_extensions: dict[str, vulkan_objects.VkExtension],
    valid_features: dict[str, vulkan_objects.VkFeature],
    platforms: dict[str, vulkan_objects.VkPlatform]
) -> None:
    for feature in valid_features.values():
        if not feature.base.valid == vulkan_objects.ElementValid.VALID:
            continue
        

    print(valid_extensions)
    for extension_name, extension in valid_extensions.items():
        if not extension.base.valid == vulkan_objects.ElementValid.VALID:
            for required in extension.requires:
                for name in required.types:
                    if name in structures:
                        structures[name].base_type.base.valid = vulkan_objects.ElementValid.VALID
                        if extension.platform is not None:
                            structures[name].base_type.base.protect = extension.platform.base.protect
                            
                    elif name in unions:
                        unions[name].base_type.base.valid = vulkan_objects.ElementValid.VALID
                        if extension.platform is not None:
                            unions[name].base_type.base.protect = extension.platform.base.protect

                    elif name in bitmasks:
                        bitmasks[name].base_type.base.valid = vulkan_objects.ElementValid.VALID
                        if extension.platform is not None:
                            bitmasks[name].base_type.base.protect = extension.platform.base.protect

                    elif name in function_pointers:
                        function_pointers[name].base_type.base.valid = vulkan_objects.ElementValid.VALID
                        if extension.platform is not None:
                            function_pointers[name].base_type.base.protect = extension.platform.base.protect

                    elif name in handles:
                        handles[name].base_type.base.valid = vulkan_objects.ElementValid.VALID
                        if extension.platform is not None:
                            handles[name].base_type.base.protect = extension.platform.base.protect

                    elif name in defines:
                        defines[name].base_type.base.valid = vulkan_objects.ElementValid.VALID
                        if extension.platform is not None:
                            defines[name].base_type.base.protect = extension.platform.base.protect

                for name in required.enumerations:
                    if name in enums:
                        enums[name].base.base.valid = vulkan_objects.ElementValid.VALID



def parse_element_list(element: ET.Element[str]) -> vulkan_objects.VkDefinedElementList | None:
    depends = element.get("depend")
    supported_apis = element.get("supported")

    enumerations: list[str] = []
    commands:     list[str] = []
    types:        list[str] = []
    features:     list[str] = []

    for sub_element in element:
        name = sub_element.get("name")
        if name is None:
            print(f"ERROR: got element in element list with no name: {sub_element}")

        if sub_element.tag == "enum":
            enumerations.append(name)
        elif sub_element.tag == "command":
            commands.append(name)
        elif sub_element.tag == "type":
            types.append(name)
        elif sub_element.tag == "feature":
            features.append(name)

    return vulkan_objects.VkDefinedElementList(
        depends,
        vulkan_objects.ElementValid.UNKNOWN,
        supported_apis,
        enumerations,
        commands,
        types,
        features
    )