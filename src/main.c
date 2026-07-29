#include <stdio.h>
#include <stdlib.h>

#include <vulkan/vk_enum_string_helper.h>
#include <vulkan/vulkan.h>

#include "utilities/logger/logger.h"

#include "vulkan_renderer/render.h"
#include "vulkan_renderer/log_utilities.h"

uint32_t score_physical_device(VkPhysicalDeviceProperties2 device_properties_2) {
    return 1 + \
        (device_properties_2.properties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU) * 0b100;
}

int main(int argc, char** argv)
{
    set_log_level(LOG_LEVEL_VERBOSE);

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

        VkQueueFlagBits flagbits = VK_QUEUE_GRAPHICS_BIT;

    Renderer renderer;
    result = vulkan_renderer_init(&renderer, &score_physical_device, &device_features_2, 1, &flagbits);
    log_message(LOG_LEVEL_DEBUG, "init result: %s", string_VkResult(result));

    result = vulkan_renderer_run(&renderer);
    log_message(LOG_LEVEL_DEBUG, "run result: %s", string_VkResult(result));

    result = vulkan_renderer_cleanup(&renderer);
    log_message(LOG_LEVEL_DEBUG, "cleanup result: %s", string_VkResult(result));

    return EXIT_SUCCESS;
}
