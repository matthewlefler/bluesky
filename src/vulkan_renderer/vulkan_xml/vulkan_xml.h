#ifndef VULKAN_XML_H
#define VULKAN_XML_H

#include <vulkan/vulkan.h>

/**
 * copies a structure and returns a pointer to it, 
 * must be a valid structure that has a "VkStructureType" as the first parameter
 * 
 * @param structure the structure to copy
 * 
 * @return the heap allocated structure with the .sType filled out
 */
void* malloc_structure(const VkBaseInStructure *structure);

/**
 * Compares a structure, a, to another structure, b
 * 
 * @param a The first structure
 * @param b The second structure
 * 
 * @return `true` if the structure, a, meets the requirements set in structure, b. `false` otherwise
 */
bool compare_struct_extends_from_VkPhysicalDeviceFeatures2(void* a, void* b);
#endif