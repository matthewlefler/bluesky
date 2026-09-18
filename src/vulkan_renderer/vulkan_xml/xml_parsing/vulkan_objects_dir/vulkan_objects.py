from dataclasses import dataclass
from enum import Enum

import xml.etree.ElementTree as ET

import dependencies

class ElementValid(Enum):
    VALID = 1,
    INVALID = 0,
    UNKNOWN = -1

@dataclass
class VkElement:
    element: ET.Element[str]
    name: str
    protect: str | None
    valid: bool

@dataclass
class VkStructure:
    base: VkElement

    # The string for the `sType` structure member if it exists, `None` otherwise
    sType: str | None 

@dataclass
class VkEnum:
    base: VkElement

@dataclass
class VkPlatform:
    base: VkElement

@dataclass
class VkExtension:
    base: VkElement
    supported_apis: list[str]
    version_number: str
    ext_type: str
    depends: dependencies.Depends | None
    promoted_to: str | None
    depreciated_by: str | None
    obsoleted_by: str | None
    provisional: bool | None

@dataclass
class VkFeature:
    base: VkElement
    supported_apis: list[str]
    version_number: str
    depends: dependencies.Depends | None

@dataclass
class VulkanObject:
    version: int
    readable_version_name: str
    supported_apis: list[str]
    extensions: list[VkExtension]
    features: list[VkFeature]
    structures: list[VkStructure]
    enums: list[VkEnum]
    platforms: list[VkPlatform]
