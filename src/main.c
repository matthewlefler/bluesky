#include <stdio.h>
#include <stdlib.h>

#include <vulkan/vk_enum_string_helper.h>
#include <vulkan/vulkan.h>

#include <string.h>

#include "logger.h"

#include "vulkan_renderer/render.h"
#include "vulkan_renderer/log_utilities.h"

uint32_t score_physical_device(VkPhysicalDeviceProperties2 device_properties_2) {
    return 1 + \
        (device_properties_2.properties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU) * 0b100;
}

uint32_t score_surface_format(VkSurfaceFormat2KHR surface_format) {
    return (surface_format.surfaceFormat.colorSpace == VK_COLOR_SPACE_SRGB_NONLINEAR_KHR);
}
uint32_t score_presentation_mode(VkPresentModeKHR present_mode) {
    switch (present_mode) {
        case VK_PRESENT_MODE_IMMEDIATE_KHR:
            return 0;
        case VK_PRESENT_MODE_MAILBOX_KHR:
            return 5;
        case VK_PRESENT_MODE_FIFO_KHR:
            return 4;
        case VK_PRESENT_MODE_FIFO_RELAXED_KHR:
            return 0;
        case VK_PRESENT_MODE_SHARED_DEMAND_REFRESH_KHR:
            return 0;
        case VK_PRESENT_MODE_SHARED_CONTINUOUS_REFRESH_KHR:
            return 0;
        case VK_PRESENT_MODE_FIFO_LATEST_READY_KHR:
            return 0;
        default:
            return 0;
    }
}

VkExtent2D get_window_extent(VkSurfaceCapabilities2KHR surface_capabilities) {
    const VkExtent2D min = surface_capabilities.surfaceCapabilities.minImageExtent;
    const VkExtent2D max = surface_capabilities.surfaceCapabilities.maxImageExtent;

    log_message(LOG_LEVEL_DEBUG, "min extent w %ld h %ld, max extent w %ld h %ld", min.width, min.height, max.width, max.height);
    return max;
}

uint32_t get_min_image_count(VkSurfaceCapabilities2KHR surface_capabilities) {
    const uint32_t target_count = 2;
    uint32_t max = surface_capabilities.surfaceCapabilities.maxImageCount;
    const uint32_t min = surface_capabilities.surfaceCapabilities.minImageCount;
    if(max == 0) {
        max = UINT32_MAX;
    }

    log_message(LOG_LEVEL_DEBUG, "min %ld max %ld target %ld, out %ld", min, max, target_count, target_count > max ? max : (target_count < min ? min : target_count));
    
    return target_count > max ? max : (target_count < min ? min : target_count);
}

int main(int argc, char** argv)
{
    set_log_level(LOG_LEVEL_VERBOSE);
    if(glfwInit() == GLFW_FALSE) { // have to init glfw before getting instance extensions
        return VK_NOT_READY;
    }

    VkResult result;

    // requirements
        VkPhysicalDeviceDynamicRenderingFeatures dynamic_rendering = {
            .dynamicRendering = VK_TRUE,
            .sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES,
        };

        VkPhysicalDeviceVulkan11Features vulkan_11 = {
            .shaderDrawParameters = VK_TRUE,
            .sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES,
        };

        VkPhysicalDeviceExtendedDynamicStateFeaturesEXT extended_dynamic_state = {
            .extendedDynamicState = VK_TRUE,
            .sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT,
        };

        VkPhysicalDeviceFeatures2 device_features_2 = {
            .features.geometryShader = VK_TRUE,
            .sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2,
        };
        
        // chain of features to grab
        device_features_2.pNext = &dynamic_rendering;
        dynamic_rendering.pNext = &vulkan_11;
        vulkan_11.pNext = &extended_dynamic_state;
        extended_dynamic_state.pNext = NULL;

        const uint32_t required_device_extensions_count = 1;
        const char *const required_device_extensions[] = {
            "VK_KHR_swapchain"
        };

        ExtensionList required_instance_extensions = {
            .num_extensions = 1,
            .extension_names = malloc(1 * sizeof(char*))
        };
        required_instance_extensions.extension_names[0] = "VK_KHR_get_surface_capabilities2";
                
        VkQueueFlagBits flagbits = VK_QUEUE_GRAPHICS_BIT;
        
        ExtensionList glfw_extensions = {0};
        glfw_extensions.extension_names = glfwGetRequiredInstanceExtensions(&glfw_extensions.num_extensions);

        ExtensionList debug_extensions = {
            .extension_names = NULL,
            .num_extensions = 0
        };
        
        #ifndef NDEBUG
            debug_extensions.num_extensions = 1;
            debug_extensions.extension_names = malloc(sizeof(char*) * debug_extensions.num_extensions);
            debug_extensions.extension_names[0] = VK_EXT_DEBUG_UTILS_EXTENSION_NAME;
        #endif

    ExtensionList instance_extensions = glfw_extensions;
    instance_extensions.p_next = &debug_extensions;
    debug_extensions.p_next = &required_instance_extensions;
    required_instance_extensions.p_next = NULL;

    Renderer renderer = {0};
    result = vulkan_renderer_init(
        instance_extensions,
        &score_physical_device, &device_features_2, 
        required_device_extensions_count, required_device_extensions,
        1, &flagbits,
        &score_surface_format,
        &score_presentation_mode,
        &get_window_extent,
        &get_min_image_count,
        &renderer
    );
    log_message(LOG_LEVEL_INFO, "init result: %s", string_VkResult(result));
    if(result) { return EXIT_FAILURE; }

    result = vulkan_renderer_run(&renderer);
    log_message(LOG_LEVEL_INFO, "run result: %s", string_VkResult(result));
    if(result) { return EXIT_FAILURE; }

    result = vulkan_renderer_cleanup(&renderer);
    log_message(LOG_LEVEL_INFO, "cleanup result: %s", string_VkResult(result));
    if(result) { return EXIT_FAILURE; }

    return EXIT_SUCCESS;
}
