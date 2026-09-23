"""
See: https://deepwiki.com/KhronosGroup/Vulkan-Docs/2.1-registry-format-and-structure
"""

from dataclasses import dataclass
from enum import Enum

import xml.etree.ElementTree as ET

from vulkan_objects_dir import dependencies
from vulkan_objects_dir.vulkan_objects_types_dir import types

@dataclass
class VkVersion:
    Major: int
    Minor: int
    # note while the patch version is here for completeness's sake it is unused, 
    # because the vulkan xml does not specify patch versions, 
    # and it is highly unlikely that the patch version should change the specification anyways
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
    valid: ElementValid

# VkTypeSubElements:
#  - INCLUDE
#  - DEFINE
#  - BASETYPE
#  - BITMASK
#  - HANDLE
#  - ENUMERATION
#  - FUNCTION_POINTER
#  - STRUCTURE
#  - UNION

@dataclass
class VkType:
    base: VkElement
    catagory: types.Category

@dataclass
class VkInclude:
    base_type: VkType

@dataclass
class VkDefine:
    base_type: VkType

@dataclass
class VkBasetype:
    base_type: VkType
    # i.e. VkBool32 may be typedef'ed to a uint32_t
    underlying_type: str

@dataclass
class VkBitMask:
    base_type: VkType
    bit_width: int # 32 or 64
    bitvalues: VkEnum

@dataclass
class VkHandle:
    base_type: VkType
    parent: VkHandle | None
    # VkObjectType enum value
    object_type_enum: VkEnumValue # objtypeenum

@dataclass
class VkEnum:
    base_type: VkType
    values: list[VkEnumValue]

@dataclass
class VkEnumValue:
    name: str
    parent_enum: VkEnum
    value: int

@dataclass
class VkFunctionPointer:
    base_type: VkType

@dataclass
class VkStructureMember:
    name: str
    array_lens: list[int | str]
    # if is some then `array_length` is a LaTeX expression
    # useful for code generation
    alternate_lengths: list[str | None]
    optional: list[bool] | None
    external_sync_required: bool
    allowed_values: str
    limit_type: str
    # number of pointer *'s
    pointer_depth: int
    
@dataclass
class VkStructure:
    base_type: VkType
    # The string for the `sType` structure member if it exists, `None` otherwise
    sType: str | None
    # list of other structures this can extend via a pNext field, or None otherwise
    extends: list[str] | None
    # if this structure is only returned, i.e. internals are filled by external functions
    returned_only: bool
    # multiple copies allowed in a structure/pNext chain 
    allow_duplicate: bool
    alias: str
    required_limit_type: str
    members: list[VkStructureMember]

@dataclass
class VkUnionMember:
    name: str
    array_length: str | None
    # if is some then `array_length` is a LaTeX expression
    # useful for code generation
    alternate_length: str | None 
    optional: list[bool] | None
    external_sync_required: bool
    allowed_values: list[str]
    limit_type: str
    # number of pointer *'s
    pointer_depth: int

@dataclass
class VkUnion:
    base: VkType
    members: list[VkUnionMember]

@dataclass
class VkPlatform:
    base: VkElement

@dataclass
class VkDefinedElementList:
    """
    used in the requires, depreciates, obsoletes tags in extensions and features
    """
    depends: dependencies.Depends | None
    valid: ElementValid
    supported_apis: list[str] | None

    enumerations: list[str]
    commands:     list[str]
    types:        list[str]
    features:     list[str]

@dataclass
class VkExtension:
    base:           VkElement
    supported_apis: list[str]
    id_number:      int
    ext_type:       str
    platform:       VkPlatform | None
    depends:        dependencies.Depends | None
    promoted_to:    str | None
    depreciated_by: str | None
    obsoleted_by:   str | None
    provisional:    bool | None

    requires:    list[VkDefinedElementList]
    depreciates: list[VkDefinedElementList]
    obsoletes:   list[VkDefinedElementList]

@dataclass
class VkFeature:
    base: VkElement
    supported_apis: list[str]
    version_number: VkVersion
    depends: dependencies.Depends | None

    requires:    list[VkDefinedElementList]
    depreciates: list[VkDefinedElementList]
    obsoletes:   list[VkDefinedElementList]

@dataclass
class VulkanObject:
    version: VkVersion
    readable_version_name: str
    supported_apis: list[str]

    platforms:         dict[str, VkPlatform]
    extensions:        dict[str, VkExtension]
    features:          dict[str, VkFeature]
    includes:          dict[str, VkInclude]
    defines:           dict[str, VkDefine]
    basetypes:         dict[str, VkBasetype]
    bitmasks:          dict[str, VkBitMask]
    handles:           dict[str, VkHandle]
    enumerations:      dict[str, VkEnum]
    function_pointers: dict[str, VkFunctionPointer]
    structures:        dict[str, VkStructure]
    unions:            dict[str, VkUnion]
