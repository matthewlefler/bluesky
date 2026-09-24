import logging
from enum import Enum
import xml.etree.ElementTree as ET

from vulkan_objects_dir import vulkan_objects
from vulkan_objects_dir.vulkan_objects_types_dir import structures
from vulkan_objects_dir.vulkan_objects_types_dir import includes
from vulkan_objects_dir.vulkan_objects_types_dir import defines
from vulkan_objects_dir.vulkan_objects_types_dir import unions
from vulkan_objects_dir.vulkan_objects_types_dir import enumerations
from vulkan_objects_dir.vulkan_objects_types_dir import basetypes
from vulkan_objects_dir.vulkan_objects_types_dir import bitmasks
from vulkan_objects_dir.vulkan_objects_types_dir import handles
from vulkan_objects_dir.vulkan_objects_types_dir import function_pointers

TYPES_TAG = "types"

CATAGORY_ATTRIBUTE_NAME = "category"
class Category(Enum):
    # sub catagories
    CATEGORY_INCLUDE          = "include"
    CATEGORY_DEFINE           = "define"
    CATEGORY_BASETYPE         = "basetype"
    CATEGORY_BITMASK          = "bitmask"
    CATEGORY_HANDLE           = "handle"
    CATEGORY_ENUMERATION      = "enum"
    CATEGORY_FUNCTION_POINTER = "funcpointer"
    CATEGORY_STRUCTURE        = "struct"
    CATEGORY_UNION            = "union"

def get_all_types(root: ET.Element[str], elements: vulkan_objects.VkDefinedElementList) -> tuple[
    dict[str, vulkan_objects.VkInclude],
    dict[str, vulkan_objects.VkDefine],
    dict[str, vulkan_objects.VkBasetype],
    dict[str, vulkan_objects.VkBitMask],
    dict[str, vulkan_objects.VkHandle],
    dict[str, vulkan_objects.VkEnum],
    dict[str, vulkan_objects.VkFunctionPointer],
    dict[str, vulkan_objects.VkStructure],
    dict[str, vulkan_objects.VkUnion]
]:
    """
    Note: this function does a lot, but it does revolve around parsing all xml tags that are `TYPE_TAG` aka "type"
    """
    return_include_dict:          dict[str, vulkan_objects.VkInclude]         = dict()
    return_define_dict:           dict[str, vulkan_objects.VkDefine]          = dict()
    return_basetype_dict:         dict[str, vulkan_objects.VkBasetype]        = dict()
    return_bitmask_dict:          dict[str, vulkan_objects.VkBitMask]         = dict()
    return_handle_dict:           dict[str, vulkan_objects.VkHandle]          = dict()
    return_enumeration_dict:      dict[str, vulkan_objects.VkEnum]            = dict()
    return_function_pointer_dict: dict[str, vulkan_objects.VkFunctionPointer] = dict()
    return_structure_dict:        dict[str, vulkan_objects.VkStructure]       = dict()
    return_union_dict:            dict[str, vulkan_objects.VkUnion]           = dict()

    types = root.findall(TYPES_TAG)

    for element in elements.types:
        type_element = None
        for type_elements in types:
            for temp in type_elements:
                if element.name == temp.get("name"):
                    type_element = temp
                name_tag = temp.find("name")
                if name_tag is not None and name_tag.text == element.name:
                    type_element = temp

        if type_element is None:
            logging.error(f"element {element.name} not found in <type>")
            continue
        
        # filter out comments
        if type_element.tag == "comment":
            continue

        category = type_element.get(CATAGORY_ATTRIBUTE_NAME)
        name = type_element.get("name")

        if name is None:
            logging.error(f"no name for type element: {type_element} {type_element.tag} {type_element.text} {type_element.tail}")
            continue
        if category is None:
            logging.error(f"no catagory for type element: {type_element} {type_element.tag} {type_element.text} {type_element.tail}")
            continue

        defined_from = None
        if element.defined_from_name in vulkan_objects.dependencies.feature_dictionary:
            defined_from = vulkan_objects.dependencies.feature_dictionary[element.defined_from_name]
        elif element.defined_from_name in vulkan_objects.dependencies.extension_dictionary:
            defined_from = vulkan_objects.dependencies.extension_dictionary[element.defined_from_name]

        if defined_from is None:
            logging.error("element defined from name is not found in either features or extension dictionaries")
            continue

        if category == Category.CATEGORY_INCLUDE.value:
            include = includes.parse_include(type_element, defined_from)
            if include is not None:
                return_include_dict[name] = include
            else:
                logging.error("parsed and returned include is None")
        elif category == Category.CATEGORY_DEFINE.value:  
            define = defines.parse_define(type_element)
            if define is not None:
                return_define_dict[name] = define
            else:
                logging.error("parsed and returned define is None")

        elif category == Category.CATEGORY_BASETYPE.value:
            basetype = basetypes.parse_basetype(type_element, defined_from)
            if basetype is not None:
                return_basetype_dict[name] = basetype
            else:
                logging.error("parsed and returned basetype is None")

        elif category == Category.CATEGORY_BITMASK.value:
            bitmask = bitmasks.parse_bitmask(type_element)
            if bitmask is not None:
                return_bitmask_dict[name] = bitmask
            else:
                logging.error("parsed and returned bitmask is None")

        elif category == Category.CATEGORY_HANDLE.value:
            handle = handles.parse_handle(type_element, defined_from)
            if handle is not None:
                return_handle_dict[name] = handle
            else:
                logging.error("parsed and returned handle is None")

        elif category == Category.CATEGORY_ENUMERATION.value:
            enumeration = enumerations.parse_enumeration(type_element)
            if enumeration is not None:
                return_enumeration_dict[name] = enumeration
            else:
                logging.error("parsed and returned enumeration is None")

        elif category == Category.CATEGORY_FUNCTION_POINTER.value:
            function_pointer = function_pointers.parse_function_pointer(type_element)
            if function_pointer is not None:
                return_function_pointer_dict[name] = function_pointer
            else:
                logging.error("parsed and returned function_pointer is None")

        elif category == Category.CATEGORY_STRUCTURE.value:
            structure = structures.parse_structure(type_element, defined_from)
            if structure is not None:
                return_structure_dict[name] = structure
            else:
                logging.error("parsed and returned structure is None")

        elif category == Category.CATEGORY_UNION.value:
            union = unions.parse_union(type_element)
            if union is not None:
                return_union_dict[name] = union
            else:
                logging.error("parsed and returned union is None")

        else:
            logging.error(f"Unknown type catagory: \"{category}\"")
            continue

    return (
        return_include_dict,
        return_define_dict,
        return_basetype_dict,
        return_bitmask_dict,
        return_handle_dict,
        return_enumeration_dict,
        return_function_pointer_dict,
        return_structure_dict,
        return_union_dict
    )