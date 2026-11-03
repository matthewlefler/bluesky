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

/**
 * Converts a `VkResult` enum to a human readable string
 * 
 * @param result The result to get the name of
 * 
 * @return  A human readable string representation of a `VkResult`, 
 */
char* to_string_VkResult(VkResult result) {
    switch(result) {
        case VK_SUCCESS:
            return "VK_SUCCESS";
        case VK_NOT_READY:
            return "VK_NOT_READY";
        case VK_TIMEOUT:
            return "VK_TIMEOUT";
        case VK_EVENT_SET:
            return "VK_EVENT_SET";
        case VK_EVENT_RESET:
            return "VK_EVENT_RESET";
        case VK_INCOMPLETE:
            return "VK_INCOMPLETE";
        case VK_ERROR_OUT_OF_HOST_MEMORY:
            return "VK_ERROR_OUT_OF_HOST_MEMORY";
        case VK_ERROR_OUT_OF_DEVICE_MEMORY:
            return "VK_ERROR_OUT_OF_DEVICE_MEMORY";
        case VK_ERROR_INITIALIZATION_FAILED:
            return "VK_ERROR_INITIALIZATION_FAILED";
        case VK_ERROR_DEVICE_LOST:
            return "VK_ERROR_DEVICE_LOST";
        case VK_ERROR_MEMORY_MAP_FAILED:
            return "VK_ERROR_MEMORY_MAP_FAILED";
        case VK_ERROR_LAYER_NOT_PRESENT:
            return "VK_ERROR_LAYER_NOT_PRESENT";
        case VK_ERROR_EXTENSION_NOT_PRESENT:
            return "VK_ERROR_EXTENSION_NOT_PRESENT";
        case VK_ERROR_FEATURE_NOT_PRESENT:
            return "VK_ERROR_FEATURE_NOT_PRESENT";
        case VK_ERROR_INCOMPATIBLE_DRIVER:
            return "VK_ERROR_INCOMPATIBLE_DRIVER";
        case VK_ERROR_TOO_MANY_OBJECTS:
            return "VK_ERROR_TOO_MANY_OBJECTS";
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            return "VK_ERROR_FORMAT_NOT_SUPPORTED";
        case VK_ERROR_FRAGMENTED_POOL:
            return "VK_ERROR_FRAGMENTED_POOL";
        case VK_ERROR_UNKNOWN:
            return "VK_ERROR_UNKNOWN";
        case VK_ERROR_VALIDATION_FAILED:
            return "VK_ERROR_VALIDATION_FAILED";
        case VK_ERROR_OUT_OF_POOL_MEMORY:
            return "VK_ERROR_OUT_OF_POOL_MEMORY";
        case VK_ERROR_INVALID_EXTERNAL_HANDLE:
            return "VK_ERROR_INVALID_EXTERNAL_HANDLE";
        case VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS:
            return "VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS";
        case VK_ERROR_FRAGMENTATION:
            return "VK_ERROR_FRAGMENTATION";
        case VK_PIPELINE_COMPILE_REQUIRED:
            return "VK_PIPELINE_COMPILE_REQUIRED";
        case VK_ERROR_NOT_PERMITTED:
            return "VK_ERROR_NOT_PERMITTED";
        case VK_ERROR_SURFACE_LOST_KHR:
            return "VK_ERROR_SURFACE_LOST_KHR";
        case VK_ERROR_NATIVE_WINDOW_IN_USE_KHR:
            return "VK_ERROR_NATIVE_WINDOW_IN_USE_KHR";
        case VK_SUBOPTIMAL_KHR:
            return "VK_SUBOPTIMAL_KHR";
        case VK_ERROR_OUT_OF_DATE_KHR:
            return "VK_ERROR_OUT_OF_DATE_KHR";
        case VK_ERROR_INCOMPATIBLE_DISPLAY_KHR:
            return "VK_ERROR_INCOMPATIBLE_DISPLAY_KHR";
        case VK_ERROR_INVALID_SHADER_NV:
            return "VK_ERROR_INVALID_SHADER_NV";
        case VK_ERROR_IMAGE_USAGE_NOT_SUPPORTED_KHR:
            return "VK_ERROR_IMAGE_USAGE_NOT_SUPPORTED_KHR";
        case VK_ERROR_VIDEO_PICTURE_LAYOUT_NOT_SUPPORTED_KHR:
            return "VK_ERROR_VIDEO_PICTURE_LAYOUT_NOT_SUPPORTED_KHR";
        case VK_ERROR_VIDEO_PROFILE_OPERATION_NOT_SUPPORTED_KHR:
            return "VK_ERROR_VIDEO_PROFILE_OPERATION_NOT_SUPPORTED_KHR";
        case VK_ERROR_VIDEO_PROFILE_FORMAT_NOT_SUPPORTED_KHR:
            return "VK_ERROR_VIDEO_PROFILE_FORMAT_NOT_SUPPORTED_KHR";
        case VK_ERROR_VIDEO_PROFILE_CODEC_NOT_SUPPORTED_KHR:
            return "VK_ERROR_VIDEO_PROFILE_CODEC_NOT_SUPPORTED_KHR";
        case VK_ERROR_VIDEO_STD_VERSION_NOT_SUPPORTED_KHR:
            return "VK_ERROR_VIDEO_STD_VERSION_NOT_SUPPORTED_KHR";
        case VK_ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT:
            return "VK_ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT";
        case VK_ERROR_PRESENT_TIMING_QUEUE_FULL_EXT:
            return "VK_ERROR_PRESENT_TIMING_QUEUE_FULL_EXT";
        case VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT:
            return "VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT";
        case VK_THREAD_IDLE_KHR:
            return "VK_THREAD_IDLE_KHR";
        case VK_THREAD_DONE_KHR:
            return "VK_THREAD_DONE_KHR";
        case VK_OPERATION_DEFERRED_KHR:
            return "VK_OPERATION_DEFERRED_KHR";
        case VK_OPERATION_NOT_DEFERRED_KHR:
            return "VK_OPERATION_NOT_DEFERRED_KHR";
        case VK_ERROR_INVALID_VIDEO_STD_PARAMETERS_KHR:
            return "VK_ERROR_INVALID_VIDEO_STD_PARAMETERS_KHR";
        case VK_ERROR_COMPRESSION_EXHAUSTED_EXT:
            return "VK_ERROR_COMPRESSION_EXHAUSTED_EXT";
        case VK_INCOMPATIBLE_SHADER_BINARY_EXT:
            return "VK_INCOMPATIBLE_SHADER_BINARY_EXT";
        case VK_PIPELINE_BINARY_MISSING_KHR:
            return "VK_PIPELINE_BINARY_MISSING_KHR";
        case VK_ERROR_NOT_ENOUGH_SPACE_KHR:
            return "VK_ERROR_NOT_ENOUGH_SPACE_KHR";
        case VK_RESULT_MAX_ENUM:
            return "VK_RESULT_MAX_ENUM";
    }
}

const char* get_debug_message_type_string(VkDebugUtilsMessageTypeFlagsEXT flags) {
    char* buffer = malloc(sizeof(char) * 256);
    buffer[0] = '\0'; // "Clear" the buffer

    if (flags & VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT) {
        strcat(buffer, "General ");
    }
    if (flags & VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT) {
        strcat(buffer, "Validation ");
    }
    if (flags & VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT) {
        strcat(buffer, "Performance ");
    }
    if (flags & VK_DEBUG_UTILS_MESSAGE_TYPE_DEVICE_ADDRESS_BINDING_BIT_EXT) {
        strcat(buffer, "DeviceAddressBinding ");
    }

    // Remove the trailing space if at least one type was added
    size_t len = strlen(buffer);
    if (len > 0) {
        buffer[len - 1] = '\0';
    } else {
        strcpy(buffer, "Unknown");
    }

    return buffer;
}