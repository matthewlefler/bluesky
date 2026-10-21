import unittest
import logging
import xml.etree.ElementTree as ET

from vulkan_objects_dir.vulkan_objects_types_dir import basetypes, bitmasks, defines, enumerations, function_pointers, handles, includes, structures, types, unions
from vulkan_objects_dir import features, extensions, vulkan_objects

def element_from_str(input_str: str) -> ET.Element[str] | None:
    return ET.ElementTree(ET.fromstring(input_str)).getroot()

test_vk_element = vulkan_objects.VkElement(ET.Element("test", {}), "test", vulkan_objects.ElementValid.VALID)
test_vk_version = vulkan_objects.VkVersion(0, 0, 0)
test_vk_feature = vulkan_objects.VkFeature(test_vk_element, [], test_vk_version, None, [], [], [])
class TestParsing(unittest.TestCase):

    def test_bitmask_parsing(self):
        valid_test_cases: list[str] = [
            "<type category=\"basetype\">typedef <type>uint32_t</type> <name>VkBool32</name>;</type>",
        ]
        invalid_test_cases: list[str] = [
            "<name>hi</name>",
            # "<type category=\"handle\">typedef <type>uint32_t</type> <name>VkBool32</name>;</type>"
        ]

        for test_case in valid_test_cases:
            element = element_from_str(test_case)
            self.assertIsNotNone(element)

            self.assertIsNotNone(basetypes.parse_basetype(element, test_vk_feature)) # type: ignore

        for test_case in invalid_test_cases:
            element = element_from_str(test_case)
            self.assertIsNotNone(element)

            self.assertIsNone(basetypes.parse_basetype(element, test_vk_feature)) # type: ignore


if __name__ == '__main__':
    unittest.main()