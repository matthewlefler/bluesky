#include <vulkan/vulkan.h>

/**
 * Converts a `VkQueueFlagBits` flag to a human readable string, returned pointer must be freed
 * 
 * @param flags The flags to get the name(s) of
 * 
 * @return  A human readable string representation of a VkQueueFlagBits, 
 *          return pointer must be freed
 */
char* to_string_VkQueueFlagBits(VkQueueFlagBits flags);

/**
 * A wrapper method to create a `LOG_LEVEL_DEBUG` message if the feature is not supported, 
 * passes the state of `feature` through
 * 
 * @param feature The feature being tested
 * @param feature_name The name of the feature
 * @param device_name The name of the device
 * 
 * @return value of `feature`
 */
VkBool32 physical_device_require_log(const VkBool32 feature, const char* feature_name, const char* device_name);