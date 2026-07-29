#include <stdlib.h>
#include <string.h>

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
uint32_t* physical_device_queue_families_supports(VkPhysicalDevice device, uint32_t flags_count, VkQueueFlagBits* flags, const char* device_name) {
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
    
            if((queue_family_properties->queueFlags & flag) == flag) {
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

bool physical_device_supports_features(VkPhysicalDevice physical_device, VkPhysicalDeviceFeatures2* device_feature_requirements) {
    VkPhysicalDeviceFeatures2* actual = copy_struct_chain(device_feature_requirements);

    vkGetPhysicalDeviceFeatures2(physical_device, actual);

    bool return_val = compare_struct_chain(actual, device_feature_requirements);

    free_struct_chain(actual);

    return return_val;
}
