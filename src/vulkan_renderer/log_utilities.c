#include <stdlib.h>
#include <string.h>

#include <vulkan/vulkan.h>

#include "../utilities/logger/logger.h"

#include "log_utilities.h"

/**
 * Converts a `VkQueueFlagBits` flag to a human readable string, returned pointer must be freed
 * 
 * @param flags The flags to get the name(s) of
 * 
 * @return  A human readable string representation of a VkQueueFlagBits, 
 *          return pointer must be freed
 */
char* to_string_VkQueueFlagBits(VkQueueFlagBits flags) {
    char* buf = malloc(sizeof(char) * 256);
    buf[0] = '\0';

    if(flags & VK_QUEUE_GRAPHICS_BIT)         { strcat(buf, "VK_QUEUE_GRAPHICS_BIT "); }
    if(flags & VK_QUEUE_COMPUTE_BIT)          { strcat(buf, "VK_QUEUE_COMPUTE_BIT "); }
    if(flags & VK_QUEUE_TRANSFER_BIT)         { strcat(buf, "VK_QUEUE_TRANSFER_BIT "); }
    if(flags & VK_QUEUE_SPARSE_BINDING_BIT)   { strcat(buf, "VK_QUEUE_SPARSE_BINDING_BIT "); }
    if(flags & VK_QUEUE_PROTECTED_BIT)        { strcat(buf, "VK_QUEUE_PROTECTED_BIT "); }
    if(flags & VK_QUEUE_VIDEO_DECODE_BIT_KHR) { strcat(buf, "VK_QUEUE_VIDEO_DECODE_BIT_KHR "); }
    if(flags & VK_QUEUE_VIDEO_ENCODE_BIT_KHR) { strcat(buf, "VK_QUEUE_VIDEO_ENCODE_BIT_KHR "); }
    if(flags & VK_QUEUE_OPTICAL_FLOW_BIT_NV)  { strcat(buf, "VK_QUEUE_OPTICAL_FLOW_BIT_NV "); }
    if(flags & VK_QUEUE_DATA_GRAPH_BIT_ARM)   { strcat(buf, "VK_QUEUE_DATA_GRAPH_BIT_ARM "); }

    if(buf[0] != '\0') {
        strcat(buf, "unknown VkQueueFlagBits flag");
    }

    return buf;
}

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
VkBool32 physical_device_require_log(const VkBool32 feature, const char* feature_name, const char* device_name) {
    if(!feature) {
        log_message(LOG_LEVEL_DEBUG, "%s does not support %s", device_name, feature_name);
    }

    return feature;
}