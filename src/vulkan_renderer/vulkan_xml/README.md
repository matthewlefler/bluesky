## This folder is for parsing the vulkan xml file to enable faster engine development 

dependent on [Vulkan-Docs](https://github.com/KhronosGroup/Vulkan-Docs/) for its written parsing 
of the vk.xml file specification. see `/include/Vulkan-Docs` for its source code

## Features
current features include:
- parsing of `vk.xml` into
  - internal classes of
    - features
    - extensions
    - platforms
    - type categories
      - basetype
      - bitmasks
      - ~~defines~~
      - enumerations 
      - function pointers
      - handles
      - includes
      - structures
      - ~~unions~~ (paritally works)
- parse.py
  - downloading of given version of vulkan `vk.xml`
  - outputs the following files:
    - bluesky_vulkan_xml_struct_copy(.h/.c)
      - alloc struct file
      - returns `calloc` allocated structure based on a given structure's sType parameter
    - bluesky_vulkan_xml_struct_copy(.h/.c) and bluesky_vulkan_xml_struct_compare_functions(.h/.c)
      - compare functions and compare switch files on structures that extends `VkPhysicalDeviceFeatures2`
      - returns whether a structure that extends `VkPhysicalDeviceFeatures2` meet a requirements structure of the same type
    - bluesky_vulkan_xml_helper_print_VkStructureType(.h/.c)
      - a helper file that returns the human readable name of a `VkStructureType` enum value