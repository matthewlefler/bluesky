#ifndef DEVICES_H
#define DEVICES_H

#include <vulkan/vulkan.h>

typedef struct Device {
    VkPhysicalDevice physical_device;
    VkDevice logical_device;

    VkPhysicalDeviceProperties2 physical_device_properties;
} Device;

/**
 * @brief 
 * 
 * @param instance Vulkan instance
 * @param score_func Function to score devices based on it's `VkPhysicalDeviceProperties2`, pass NULL to use the default
 * @param device_feature_requirements `VkPhysicalDeviceFeatures2` structure chain of required features
 * @param device_extension_count Number of `device_extension_requirements`
 * @param device_extension_requirements An array of required extension names, null-terminated strings
 * @param queue_flags_count Number of `queue_flags`
 * @param queue_flags Required queues and their required flags, such as `VK_QUEUE_GRAPHICS_BIT`
 * @param out_device The returned device, must be a valid pointer as it is not allocated within the function
 *  
 * @return The result of the operation, `VK_SUCCESS` (`0`) on success, another value on failure.
 */
VkResult device_get(
    const VkInstance instance, 
    const uint32_t (*score_func)(VkPhysicalDeviceProperties2), 
    const VkPhysicalDeviceFeatures2* device_feature_requirements, 
    const uint32_t device_extension_count, const char* const *device_extension_requirements,
    const uint32_t queue_flags_count, const VkQueueFlagBits* queue_flags, 
    Device* out_device
);

#endif