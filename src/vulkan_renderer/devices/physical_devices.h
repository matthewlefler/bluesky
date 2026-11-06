#ifndef PHYSICAL_DEVICES_H
#define PHYSICAL_DEVICES_H

#include <vulkan/vulkan.h>

/**
 * checks for the required queues families on a device, 
 * and returns the array of indices of the queues families requested
 * 
 * @param device The device to check for queue families on
 * @param flags_count The length of the queue family flags array
 * @param flags The array of queue family flags
 * @param device_name The name of the device, for debugging purposes
 * 
 * @return `NULL` if any requested flag is unsupported, otherwise the array of indices of the queue families
 */
uint32_t* physical_device_queue_families_supports(const VkPhysicalDevice device, const uint32_t flags_count, const VkQueueFlagBits* flags, const char* device_name);

/**
 * checks if the physical device, `device`, meets the requirements specificed in `requirements`
 * 
 * @param device The device to check for support of the requirements on
 * @param requirements the features required for the physical device
 * 
 * @return `true` if the requirements are met, `false` otherwise
 */
bool physical_device_supports_features(const VkPhysicalDevice physical_device, const VkPhysicalDeviceFeatures2* device_feature_requirements);

/**
 * checks if the physical device, `device`, has the extensions specificed in `extension_names`
 * 
 * @param device The device to check for support of the requirements on
 * @param extension_count the number of extensions to check for
 * @param extension_names the extensions required for the physical device
 * 
 * @return `true` if the extensions are found, `false` otherwise
 */
bool physical_device_supports_extensions(const VkPhysicalDevice physical_device, const uint32_t extension_count, const char *const *extension_names);

#endif