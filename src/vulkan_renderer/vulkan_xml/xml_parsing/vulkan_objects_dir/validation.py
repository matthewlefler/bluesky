import logging
import xml.etree.ElementTree as ET

from vulkan_objects_dir import vulkan_objects, dependencies

def combine_features_extensions(valid_extensions: dict[str, vulkan_objects.VkExtension], valid_features: dict[str, vulkan_objects.VkFeature], target_apis: list[str]) -> vulkan_objects.VkDefinedElementList:
    return_list = vulkan_objects.VkDefinedElementList(
        None, vulkan_objects.ElementValid.VALID, None,
        enumerations = [],
        commands     = [],
        types        = [],
        features     = [],
    )

    for feature_name, feature in valid_features.items():
        for require in feature.requires:
            if(
                (require.depends is not None and dependencies.validate(require.depends) != vulkan_objects.ElementValid.VALID) or 
                (require.supported_apis is not None and any([x if x in target_apis else None for x in require.supported_apis]))
            ):
                continue

            return_list.enumerations.extend(require.enumerations)
            return_list.commands.extend(require.commands)
            return_list.features.extend(require.features)
            return_list.types.extend(require.types)

        for depreciate in feature.depreciates:
            if(
                (depreciate.depends is not None and dependencies.validate(depreciate.depends) != vulkan_objects.ElementValid.VALID) or 
                (depreciate.supported_apis is not None and any([x if x in depreciate.supported_apis else None for x in target_apis]))
            ):
                continue

            for enum in depreciate.enumerations:
                return_list.enumerations.remove(enum)
            for command in depreciate.commands:
                return_list.commands.remove(command)
            for feature in depreciate.features:
                return_list.features.remove(feature)
            for type_ in depreciate.types:
                return_list.types.remove(type_)

        for obsolete in feature.obsoletes: # type: ignore
            if(
                (obsolete.depends is not None and dependencies.validate(obsolete.depends) != vulkan_objects.ElementValid.VALID) or 
                (obsolete.supported_apis is not None and any([x if x in obsolete.supported_apis else None for x in target_apis]))
            ):
                continue

            for enum in obsolete.enumerations:
                return_list.enumerations.remove(enum)
            for command in obsolete.commands:
                return_list.commands.remove(command)
            for feature in obsolete.features:
                return_list.features.remove(feature)
            for type_ in obsolete.types:
                return_list.types.remove(type_)

    for extension_name, extension in valid_extensions.items():
        for require in extension.requires:
            if(
                (require.depends is not None and dependencies.validate(require.depends) != vulkan_objects.ElementValid.VALID) or 
                (require.supported_apis is not None and not any([x if x in target_apis else None for x in require.supported_apis]))
            ):
                continue

            return_list.enumerations.extend(require.enumerations)
            return_list.commands.extend(require.commands)
            return_list.features.extend(require.features)
            return_list.types.extend(require.types)

        for depreciate in extension.depreciates:
            if(
                (depreciate.depends is not None and dependencies.validate(depreciate.depends) != vulkan_objects.ElementValid.VALID) or 
                (depreciate.supported_apis is not None and not any([x if x in depreciate.supported_apis else None for x in target_apis]))
            ):
                continue

            for enum in depreciate.enumerations:
                return_list.enumerations.remove(enum)
            for command in depreciate.commands:
                return_list.commands.remove(command)
            for feature in depreciate.features:
                return_list.features.remove(feature)
            for type_ in depreciate.types:
                return_list.types.remove(type_)

        for obsolete in extension.obsoletes:
            if(
                (obsolete.depends is not None and dependencies.validate(obsolete.depends) != vulkan_objects.ElementValid.VALID) or 
                (obsolete.supported_apis is not None and any([x if x in obsolete.supported_apis else None for x in target_apis]))
            ):
                continue

            for enum in obsolete.enumerations:
                return_list.enumerations.remove(enum)
            for command in obsolete.commands:
                return_list.commands.remove(command)
            for feature in obsolete.features:
                return_list.features.remove(feature)
            for type_ in obsolete.types:
                return_list.types.remove(type_)

    return return_list

def parse_element_list(element: ET.Element[str], defined_from_name: str) -> vulkan_objects.VkDefinedElementList | None:
    depends = element.get("depend")
    supported_apis = element.get("api")

    enumerations: list[vulkan_objects.VkDefinedElementListItem] = []
    commands:     list[vulkan_objects.VkDefinedElementListItem] = []
    types:        list[vulkan_objects.VkDefinedElementListItem] = []
    features:     list[vulkan_objects.VkDefinedElementListItem] = []

    for sub_element in element:
        name = sub_element.get("name")
        if name is None:
            logging.error(f"got element in element list with no name: {sub_element}")
            continue

        item = vulkan_objects.VkDefinedElementListItem(
            name, defined_from_name
        )

        if sub_element.tag == "enum":
            enumerations.append(item)
        elif sub_element.tag == "command":
            commands.append(item)
        elif sub_element.tag == "type":
            types.append(item)
        elif sub_element.tag == "feature":
            features.append(item)

    if supported_apis is not None:
        print(f"parse {supported_apis}")
        supported_apis = supported_apis.split(",")

    if depends is not None:
        depends = dependencies.parse_depend_string(depends)

    return vulkan_objects.VkDefinedElementList(
        depends,
        vulkan_objects.ElementValid.UNKNOWN,
        supported_apis,
        enumerations,
        commands,
        types,
        features
    )