from dataclasses import dataclass
import xml.etree.ElementTree as ET

import depends as depends_py

# name="VK_KHR_android_surface" 
# number="9" 
# type="instance" 
# depends="VK_KHR_surface" 
# platform="android" 
# author="KHR" 
# contact="Jesse Hall @critsec" 
# supported="vulkan" 
# ratified="vulkan" 
# nofeatures="true"
@dataclass
class extension:
    element: ET.Element[str]
    name: str
    platform: str | None
    ext_type: str | None
    depends: str | None
    supported: str | None
    nofeatures: bool | None
    deprecatedby: str | None

def parse_extension(element: ET.Element[str]) -> extension | None:
    name = element.get("name")
    platform = element.get("platform")
    ext_type = element.get("ext_type")
    depends = element.get("depends")
    supported = element.get("supported")
    nofeatures = element.get("nofeatures")
    deprecatedby = element.get("deprecatedby")
    api = element.get("api")

    if api is not None and "vulkan" not in api.split(","):
        return None

    if name is None:
        return None

    if nofeatures is not None:
        nofeatures = bool(nofeatures)

    return extension(element, name, platform, ext_type, depends, supported, nofeatures, deprecatedby)

extension_name_valid: dict[str, int] = dict()
def collect_valid_extensions(element: ET.Element[str]) -> list[ET.Element[str]]:
    extensions = list(element.iter("extension"))
    print(f"collected {len(extensions)} extensions")

    extension_list: list[tuple[str, ET.Element[str]]] = []
    extension_indices = dict()
    for index, extension in enumerate(extensions):
        name = extension.get("name")
        if name is not None:
            extension_list.append((name, extension))
            extension_name_valid[name] = -1
            extension_indices[name] = index

    return_array = []

    i = 0
    while i < len(extension_list):
        name = extension_list[i][0]
        extension = extension_list[i][1]

        supported = extension.get("supported")
        if supported is not None and "vulkan" not in supported.split(","):
            extension_name_valid[name] = 0
            i += 1
            continue

        depends = extension.get("depends")
        if depends is not None:
            depends = depends_py.parse_depends(depends)
            if depends is not None:
                return_val = depends_py.calc_depends_struct(depends, extension_name_valid, dict())
                if isinstance(return_val, list):
                    for index, dependincy_name in enumerate(return_val):
                        first_index = i + index
                        second_index = extension_indices[dependincy_name]
                        if second_index == None:
                            print(f"for {name}, index of {dependincy_name} not found")
                            extension_name_valid[dependincy_name] = 0
                            i += 1 
                            continue
                        temp = extension_list[first_index] # swap first and second indices
                        extension_list[first_index] = extension_list[second_index]
                        extension_list[second_index] = temp
                        continue
                else:
                    if return_val == 0:
                        print(f"{name} not vaild")
                        extension_name_valid[name] = 0
                        i += 1
                        continue

        extension_name_valid[name] = 1
        return_array.append(extension)
        i += 1

    return return_array