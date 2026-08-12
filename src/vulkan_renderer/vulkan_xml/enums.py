from dataclasses import dataclass
import xml.etree.ElementTree as ET
import structures as structures_py
import depends as depends_py
import extensions as extenstion_py

@dataclass
class vk_enum:
    element: ET.Element[str]
    name: str
    alias: str | None
    deprecated: str | None
    extension_from: extenstion_py.extension 

def collect_vaild_enums(element: ET.Element[str], extension_name_valid: dict[str, int], structures: dict[str, structures_py.vk_structure]) -> list[vk_enum]:
    extensions = list(element.iter("extension"))
    return_array = []

    for extension in extensions:
        ext = extenstion_py.parse_extension(extension)
        if ext is None or "vulkan" not in extension.get("supported", "").split(","):
            continue

        for require in extension:
            if depends_py.eval_depends(require, extension_name_valid, structures) == False:
                continue
            for element in require:
                if element.tag == "enum":
                    name = element.get("name")
                    extnumber = element.get("extnumber") # skip enums defined in other extensions
                    if name is None or extnumber is not None:
                        continue

                    enum = vk_enum(element, name, element.get("alias"), element.get("deprecated"), ext)
                    return_array.append(enum)

    return return_array

def get_enums_that_extend_from(enums: list[vk_enum], extends_from: str) -> list[vk_enum]:
    return_array = []
    for enum in enums:
        extends = enum.element.get("extends")

        if extends is None or extends != extends_from:
            continue
        return_array.append(enum)

    return return_array

# endings_to_captilize = ["Khr", "Ext", "Amd", "Nvx", "Nv", "Google", "Img", "Qcom", "Intel", "Huawei", "Valve"]
# strings_to_captilize = ["Lod", "Astc", "Sm", "Pci", "3d", "Rgba10x6", "Rdma"]
# def convert_enum_name_to_struct_name(name: str) -> str:
#     # VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_NALU_SLICE_SEGMENT_INFO_KHR
#     # to
#     # VkVideoEncodeH265NaluSliceSegmentInfoKHR
#     name = name.removeprefix("VK_STRUCTURE_TYPE_")
#     struct_name = ""
#     capitalize_next = True
#     for char in name:
#         if char == "_":
#             capitalize_next = True
#             continue

#         if capitalize_next: 
#             struct_name += char
#             capitalize_next = False
#         else:
#             struct_name += char.lower()

#     struct_name = "Vk" + struct_name
#     struct_name_len = len(struct_name)

#     for ending in endings_to_captilize:
#         if struct_name.endswith(ending):
#             struct_name = struct_name[:struct_name_len - len(ending)] + struct_name.upper()[struct_name_len - len(ending):]

#     for string in strings_to_captilize:
#         index = struct_name.find(string)
#         if index != -1:
#             struct_name = struct_name[:index] + struct_name.upper()[index:index + len(string)] + struct_name[index + len(string):]

#     return struct_name