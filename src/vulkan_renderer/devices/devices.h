#ifndef DEVICES_H
#define DEVICES_H

#include <vulkan/vulkan.h>

typedef struct Device {
    VkPhysicalDevice physical_device;
    VkDevice logical_device;

    VkPhysicalDeviceProperties2 physical_device_properties;
} Device;

VkResult device_get(
    VkInstance instance, 
    uint32_t (*score_func)(VkPhysicalDeviceProperties2), 
    VkPhysicalDeviceFeatures2* device_feature_requirements, 
    uint32_t queue_flags_count, 
    VkQueueFlagBits* queue_flags, 
    Device* out_device
);

#endif