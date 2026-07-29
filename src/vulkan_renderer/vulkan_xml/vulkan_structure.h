#ifndef VULKAN_STRUCTURE_H
#define VULKAN_STRUCTURE_H

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
 * compares two structure chain and checks if a, meet the requirements b
 * 
 * @return `true` if the requirements are met, `false` otherwise
 */
bool compare_struct_chain(void* a, void* b);

#endif