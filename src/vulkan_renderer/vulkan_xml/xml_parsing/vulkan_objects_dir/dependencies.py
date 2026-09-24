import logging
from dataclasses import dataclass
from enum import Enum

from vulkan_objects_dir import vulkan_objects

class DependsOperation(Enum):
    OR = 0
    AND = 1
    NONE = -1

@dataclass
class Depends:
    # each sub_depends is one of 
    #   A Depends, 
    #   or a name string, which is one of:
    #     - VK_VERSION_{major}_{minor}
    #     - VK_XXX_extension
    #     - structure_name::feature_name
    sub_depends: list[Depends | str]
    operation: DependsOperation

extension_dictionary: dict[str, vulkan_objects.VkExtension] = dict()
feature_dictionary:   dict[str, vulkan_objects.VkFeature]   = dict()


def set_dictionaries(extensions: dict[str, vulkan_objects.VkExtension], features: dict[str, vulkan_objects.VkFeature]) -> None:
    vulkan_objects.dependencies.extension_dictionary = extensions
    vulkan_objects.dependencies.feature_dictionary = features


target_api_version: vulkan_objects.VkVersion
def set_target_api_version(version: vulkan_objects.VkVersion) -> None:
    vulkan_objects.dependencies.target_api_version = version


def validate_name(name: str) -> vulkan_objects.ElementValid:
    # is the name of a api verion
    if name.startswith("VK_VERSION_"):
        version = [int(x) for x in name.removeprefix("VK_VERSION_").split("_")]
        if version[0] < target_api_version.Major:
            return vulkan_objects.ElementValid.INVALID
        elif version[0] == target_api_version.Major:
            if version[1] >= target_api_version.Minor:
                return vulkan_objects.ElementValid.VALID
            else:
                return vulkan_objects.ElementValid.INVALID
        else:
            return vulkan_objects.ElementValid.VALID

    # struct name
    #   These are dependent on runtime features which can only be determined at runtime
    if "::" in name:
        return vulkan_objects.ElementValid.VALID
    # extension name
    if name in extension_dictionary:
        return extension_dictionary[name].base.valid
    if name in feature_dictionary:
        return feature_dictionary[name].base.valid
    
    logging.error(f"extension name \'{name}\' not found in extension/feature dictonary")
    return vulkan_objects.ElementValid.INVALID


def validate(depend: Depends) -> vulkan_objects.ElementValid:
    valid: vulkan_objects.ElementValid = vulkan_objects.ElementValid.UNKNOWN
    for sub_depend in depend.sub_depends:
        if isinstance(sub_depend, Depends):
            valid = validate(sub_depend)
        elif isinstance(sub_depend, str):
            valid = validate_name(sub_depend)
            
        else:
            logging.error(f"sub_depend {sub_depend} is not a `string` or a `Depends` object")
            valid = vulkan_objects.ElementValid.INVALID

        if depend.operation == DependsOperation.OR:
            if valid:
                return vulkan_objects.ElementValid.VALID
        elif depend.operation == DependsOperation.AND:
            if not valid:
                return vulkan_objects.ElementValid.INVALID

    if depend.operation == DependsOperation.OR:
        return vulkan_objects.ElementValid.INVALID
    elif depend.operation == DependsOperation.AND:
        return vulkan_objects.ElementValid.VALID
    
    return vulkan_objects.ElementValid.INVALID
        
def parse_depend_string(depends: str) -> Depends | None:
    """
    parses a depends statments i.e. "name1,(name2+name3),name4"
    """
        
    # parens () for order
    # , means OR
    # + means AND
    #
    # i.e.
    # vk_name1,(vk_name2+vk_name3),vk_name4
    # means
    # vk_name1 or (both vk_name2 and vk_name3) or vk_name4
    OPEN_PAREN_CHAR = '('
    CLOSE_PAREN_CHAR = ')'
    OR_CHAR = ','
    AND_CHAR = '+'

    if depends.isspace():
        return None

    depends_name: str = ""
    stack: list[Depends] = list()
    current: Depends = Depends([], DependsOperation.NONE)
    for character in depends:
        if character == OR_CHAR:
            if current.operation == DependsOperation.AND:
                # error
                logging.error(f"depends contains AND \'{AND_CHAR}\' and OR \'{OR_CHAR}\' characters in the same sequence: \n\tin: {depends}")
                return None
            
            current.operation = DependsOperation.OR
            if not depends_name.isspace() and len(depends_name) > 0:
                current.sub_depends.append(depends_name)
            depends_name = ""
            
        elif character == AND_CHAR:
            if current.operation == DependsOperation.OR:
                # error
                logging.error(f"depends contains AND \'{AND_CHAR}\' and OR \'{OR_CHAR}\' characters in the same sequence\n\tin: {depends}")
                return None

            current.operation = DependsOperation.AND
            if not depends_name.isspace() and len(depends_name) > 0:
                current.sub_depends.append(depends_name)
            depends_name = ""
                
        elif character == OPEN_PAREN_CHAR:
            stack.append(current)
            current = Depends([], DependsOperation.NONE)
        elif character == CLOSE_PAREN_CHAR:
            if not depends_name.isspace() and len(depends_name) > 0:
                current.sub_depends.append(depends_name)
            depends_name = ""

            if current.operation == DependsOperation.NONE:
                current.operation = DependsOperation.OR
            
            previous = stack.pop()
            previous.sub_depends.append(current)
            current = previous
        else:
            depends_name += character
    
    if current.operation == DependsOperation.NONE:
        current.operation = DependsOperation.OR
        # logging.error(f"depends contains a sequence with no operation characters (\'{AND_CHAR}\',\'{OR_CHAR}\')\n\tin: {depends}")
    
    return current

def print_depends(depends: Depends, depth = 0) -> None:
    """
    recursively prints a depends statement
    """
    if depends is None:
        return
    TAB = "  "
    tabs = depth * TAB

    print(f"{tabs}(")
    for index,sub in enumerate(depends.sub_depends):
        if isinstance(sub, str):
            print(f"{(depth + 1) * TAB}{sub}")
        else:
            print_depends(sub, depth + 1)

        if index < len(depends.sub_depends) - 1:
            if depends.operation == DependsOperation.OR:
                print(f"{tabs}OR")
            elif depends.operation == DependsOperation.AND:
                print(f"{tabs}AND")
            elif depends.operation == DependsOperation.NONE:
                print(f"{tabs}NONE")
            else:
                print(f"{tabs}ERROR: unknown depends operation: {depends.operation}")
    print(f"{tabs})")
    