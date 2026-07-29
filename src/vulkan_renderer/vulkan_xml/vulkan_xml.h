#ifndef VULKAN_XML_H
#define VULKAN_XML_H

/**
 * copies a structure and returns a pointer to it, 
 * must be a valid structure that has a "VkStructureType" as the first parameter
 * 
 * @param structure the structure to copy
 * 
 * @return the heap allocated structure with the .sType filled out
 */
void* copy_structure(void* structure);

/**
 * Compares a structure, a, to another structure, b
 * 
 * @param a The first structure
 * @param b The second structure
 * 
 * @return `true` if the structure, a, meets the requirements set in structure, b. `false` otherwise
 */
bool compare_structure(void* a, void* b);
#endif