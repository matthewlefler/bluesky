#ifndef LOGICAL_DEVICES_H
#define LOGICAL_DEVICES_H

#include <vulkan/vulkan.h>

VkResult create_logical_device(VkPhysicalDevice physical_device, uint32_t queue_count, VkQueueFlagBits* queue_flags, uint32_t* queue_indices, VkDevice* out_logical_device);

#endif