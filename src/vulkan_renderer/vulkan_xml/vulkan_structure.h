#ifndef VULKAN_STRUCTURE_H
#define VULKAN_STRUCTURE_H

#include <vulkan/vulkan.h>

/**
 * copies a chain of structures with internals:
 * struct {
 *     VkStructureType sType;
 *     void* pNext;
 *     ...
 * }
 * 
 * @param start The first structure in the chain to copy
 * 
 * @return A heap allocated chain of structures
 */
void* copy_struct_chain(void* start);

/**
 * Frees a chain of structures with internals:
 * struct {
 *     VkStructureType sType;
 *     void* pNext;
 *     ...
 * }
 * 
 * @param start The beginning of the chain of structures to free
 */
void free_struct_chain(void* start);

/**
 * compares two structure chain and checks if the `actual`, meet the `requirements`
 * 
 * @return `true` if the requirements are met, `false` otherwise
 */
bool compare_VkPhysicalDeviceFeatures2_chain(VkPhysicalDeviceFeatures2* actual, VkPhysicalDeviceFeatures2* requirements);

#endif