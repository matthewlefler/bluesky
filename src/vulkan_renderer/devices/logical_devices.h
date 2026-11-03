#ifndef LOGICAL_DEVICES_H
#define LOGICAL_DEVICES_H

#include <vulkan/vulkan.h>

VkResult create_logical_device(
    VkPhysicalDevice physical_device, 
    const uint32_t queue_count, const VkQueueFlagBits* queue_flags, const uint32_t* queue_indices, 
    const uint32_t enabledExtensionCount, const char* const *ppEnabledExtensionNames,
    VkDevice* out_logical_device
);

#endif