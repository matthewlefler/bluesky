import xml.etree.ElementTree as ET

from vulkan_objects_dir import vulkan_objects

def parse_handle(element: ET.Element[str], defined_from: vulkan_objects.VkFeature | vulkan_objects.VkExtension) -> vulkan_objects.VkHandle | None:
    objtypeenum = element.get("objtypeenum")
    parent = element.get("parent")
    name = element.find("name")
    if name is not None:
        name = name.text

    if objtypeenum is None or name is None:
        return None

    return vulkan_objects.VkHandle(
        vulkan_objects.VkType(
            vulkan_objects.VkElement(
                element,
                name,
                vulkan_objects.ElementValid.VALID
            ),
            defined_from,
            vulkan_objects.types.Category.CATEGORY_HANDLE
        ),
        parent,
        objtypeenum
    )
