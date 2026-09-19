from dataclasses import dataclass
from enum import Enum

import xml.etree.ElementTree as ET

import dependencies

@dataclass
class VkVersion:
    Major: int
    Minor: int
    Patch: int

    def get_name(self) -> str:
        return f"{self.Major}.{self.Minor}.{self.Patch}"

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
    id_number: int
    ext_type: str
    platform: VkPlatform | None
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
    version: VkVersion
    readable_version_name: str
    supported_apis: list[str]
    extensions: dict[str, VkExtension]
    features:   dict[str, VkFeature]
    structures: dict[str, VkStructure]
    enums:      dict[str, VkEnum]
    platforms:  dict[str, VkPlatform]
