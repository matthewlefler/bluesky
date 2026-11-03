#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "../../utilities/logger/logger.h"
#include "../vulkan_xml/vulkan_structure.h"
#include "../log_utilities.h"

#include "physical_devices.h"

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
uint32_t* physical_device_queue_families_supports(const VkPhysicalDevice device, const uint32_t flags_count, const VkQueueFlagBits* flags, const char* device_name) {
    uint32_t queue_family_properties_count;
    vkGetPhysicalDeviceQueueFamilyProperties(device, &queue_family_properties_count, NULL);

    VkQueueFamilyProperties* queue_family_properties = malloc(sizeof(VkQueueFamilyProperties) * queue_family_properties_count);
    vkGetPhysicalDeviceQueueFamilyProperties(device, &queue_family_properties_count, queue_family_properties);

    uint32_t* queue_indices = malloc(sizeof(uint32_t) * flags_count);

    for(uint32_t i = 0; i < flags_count; ++i) {
        VkQueueFlagBits flag = flags[i];

        int support = 0;
        for(uint32_t j = 0; j < queue_family_properties_count; ++j) {
            VkQueueFamilyProperties queue_family_property = queue_family_properties[j];
    
            if((queue_family_property.queueFlags & flag) == flag) {
                support = 1;
                queue_indices[i] = j;
            }
        }
    
        if(!support) {
            char* flags_string = to_string_VkQueueFlagBits(*flags);
            log_message(LOG_LEVEL_DEBUG, "%s does not support %s", device_name, flags_string);
            free(flags_string);

            free(queue_family_properties);
            free(queue_indices);
            return NULL;
        }
    }

    free(queue_family_properties);
    return queue_indices;
}

bool physical_device_supports_features(const VkPhysicalDevice physical_device, const VkPhysicalDeviceFeatures2* device_feature_requirements) {
    VkPhysicalDeviceFeatures2* actual = copy_struct_chain(device_feature_requirements);

    vkGetPhysicalDeviceFeatures2(physical_device, actual);

    bool return_val = compare_VkPhysicalDeviceFeatures2_chain(actual, device_feature_requirements);

    free_struct_chain(actual);

    return return_val;
}

bool physical_device_supports_extensions(VkPhysicalDevice physical_device, uint32_t extension_count, const char *const *extension_names) {
    uint32_t property_count = 0;
    vkEnumerateDeviceExtensionProperties(physical_device, NULL, &property_count, NULL);
    VkExtensionProperties *physical_device_properties = malloc(sizeof(VkExtensionProperties) * property_count);
    vkEnumerateDeviceExtensionProperties(physical_device, NULL, &property_count, physical_device_properties);

    bool *exists = calloc(extension_count, sizeof(bool));
    for(uint32_t i = 0; i < extension_count; ++i) {
        for(uint32_t j = 0; j < property_count; ++j) {
            if(strcmp(extension_names[i], physical_device_properties[j].extensionName) == 0) {
                exists[i] = true;
            }
        }
    }
    
    bool worked = true;
    for(uint32_t i = 0; i < extension_count; ++i) {
        if(!exists[i]) {
            log_message(LOG_LEVEL_DEBUG, "\textension not found in physical device %s\n", extension_names[i]);
            worked = false;
        }
    }

    return worked;
}

// for choosing a swapchain such as defined get:
// - Surface format (color depth)
// - Presentation mode (conditions for "swapping" images to the screen)
// - Swap extent (resolution of images in the theoretical swapchain)
// https://docs.vulkan.org/tutorial/latest/03_Drawing_a_triangle/01_Presentation/01_Swap_chain.html
VkResult query_physical_device_surface_formats(const VkPhysicalDevice physical_device, const VkSurfaceKHR surface, uint32_t *out_surface_format_count, VkSurfaceFormat2KHR **out_surface_formats) {
    VkPhysicalDeviceSurfaceInfo2KHR surfaceInfo = {
        .sType   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR,
        .surface = surface
    };

    *out_surface_format_count = 0;
    VkResult result;
    if((result = vkGetPhysicalDeviceSurfaceFormats2KHR(physical_device, &surfaceInfo, out_surface_format_count, NULL)) != VK_SUCCESS) {
        return result;
    }
    *out_surface_formats = calloc(*out_surface_format_count, sizeof(VkSurfaceFormat2KHR));
    for (size_t i = 0; i < *out_surface_format_count; i++) {
        (*out_surface_formats)[i].sType = VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR;
    }
    
    result = vkGetPhysicalDeviceSurfaceFormats2KHR(physical_device, &surfaceInfo, out_surface_format_count, *out_surface_formats);
    if(result != VK_SUCCESS) {
        free(*out_surface_formats);
        *out_surface_formats = NULL;
    }

    return result;
}

VkResult query_physical_device_presentation_modes(const VkPhysicalDevice physical_device, const VkSurfaceKHR surface, uint32_t *out_surface_presentation_modes_count, VkPresentModeKHR **out_surface_presentation_modes) {
    *out_surface_presentation_modes_count = 0;
    VkResult result;
    if((result = vkGetPhysicalDeviceSurfacePresentModesKHR(physical_device, surface, out_surface_presentation_modes_count, NULL)) != VK_SUCCESS) {
        return result;
    }
    *out_surface_presentation_modes = calloc(*out_surface_presentation_modes_count, sizeof(VkPresentModeKHR));
    
    result = vkGetPhysicalDeviceSurfacePresentModesKHR(physical_device, surface, out_surface_presentation_modes_count, *out_surface_presentation_modes);
    if(result != VK_SUCCESS) {
        free(*out_surface_presentation_modes);
        *out_surface_presentation_modes = NULL;
    }
    return result;
}
