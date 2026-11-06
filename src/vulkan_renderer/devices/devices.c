#include <stdlib.h>

#include "../../utilities/logger/logger.h"

#include "devices.h"

#include "physical_devices.h"
#include "logical_devices.h"

uint32_t default_score_func(VkPhysicalDeviceProperties2 device_properties) {
    uint32_t score = 1;
    uint32_t driver_version = device_properties.properties.driverVersion;

    if(driver_version >= VK_API_VERSION_1_4) {
        score++;
    }

    // VK_PHYSICAL_DEVICE_TYPE_OTHER = 0,
    // VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU = 1,
    // VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU = 2,
    // VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU = 3,
    // VK_PHYSICAL_DEVICE_TYPE_CPU = 4,
    score += device_properties.properties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU;

    return score;
}

VkResult device_get(
    const VkInstance instance, 
    uint32_t (*score_func)(VkPhysicalDeviceProperties2), 
    const VkPhysicalDeviceFeatures2* device_feature_requirements, 
    const uint32_t device_extension_count, const char* const *device_extension_requirements,
    const uint32_t queue_flags_count, const VkQueueFlagBits* queue_flags, 
    Device* out_device
) {
    if(instance == NULL) {
        log_message(LOG_LEVEL_ERROR, "device_get -> instance is null");
        return VK_ERROR_INITIALIZATION_FAILED;
    }
    
    if(score_func == NULL) {
        score_func = &default_score_func;
    }

    Device device = {0};

    // get physical devices
    uint32_t physical_devices_count = 0;
    vkEnumeratePhysicalDevices(instance, &physical_devices_count, NULL);
    VkPhysicalDevice* physical_devices = malloc(sizeof(VkPhysicalDevice) * physical_devices_count);
    vkEnumeratePhysicalDevices(instance, &physical_devices_count, physical_devices);

    uint32_t max_score = 0;
    VkPhysicalDevice current_best_physical_device;
    VkPhysicalDeviceProperties2 current_best_physical_device_properties;
    uint32_t* current_best_physical_device_queue_indices = NULL;
    
    // iterate over physical devices to pick "best" one
    for(uint32_t i = 0; i < physical_devices_count; ++i) {
        VkPhysicalDevice physical_device = physical_devices[i];

        VkPhysicalDeviceProperties2 physical_device_properties = {
            .sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2,
            .pNext = NULL
        };
        vkGetPhysicalDeviceProperties2(physical_device, &physical_device_properties);

        log_message(LOG_LEVEL_DEBUG, "device selection, device: %s", physical_device_properties.properties.deviceName);

        uint32_t score = score_func(physical_device_properties);
        
        // get indices of the required queues
        uint32_t* queue_indices = physical_device_queue_families_supports(physical_device, queue_flags_count, queue_flags, physical_device_properties.properties.deviceName);
        bool has_requried_properties = physical_device_supports_features(physical_device, device_feature_requirements);
        bool has_required_extensions = physical_device_supports_extensions(physical_device, device_extension_count, device_extension_requirements);

        log_message(LOG_LEVEL_DEBUG, "device selection, score: %d", score);
        log_message(LOG_LEVEL_DEBUG, "device selection, queue_indices: %p", queue_indices);
        log_message(LOG_LEVEL_DEBUG, "device selection, has_requried_properties: %s", has_requried_properties ? "true" : "false");

        if(
            score > max_score && 
            queue_indices != NULL && 
            has_requried_properties && 
            has_required_extensions
        ) {
            max_score = score;

            current_best_physical_device = physical_device;
            current_best_physical_device_properties = physical_device_properties;
            current_best_physical_device_queue_indices = queue_indices;
        } else {
            free(queue_indices);
        }
    }

    if(current_best_physical_device_queue_indices == NULL) {
        log_message(LOG_LEVEL_FATAL, "no device found");
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    device.physical_device = current_best_physical_device;
    device.physical_device_properties = current_best_physical_device_properties;
    device.queue_indices = current_best_physical_device_queue_indices;
    device.queue_count = queue_flags_count;

    create_logical_device(
        current_best_physical_device, 
        queue_flags_count, queue_flags, current_best_physical_device_queue_indices, 
        device_extension_count, device_extension_requirements,
        &device.logical_device
    );

    *out_device = device;

    return VK_SUCCESS;
}

void device_free(Device device) {
    free(device.queue_indices);
}