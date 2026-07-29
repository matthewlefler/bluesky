#include <stdlib.h>

#include <vulkan/vulkan.h>

#include "physical_devices.h"

#include "logical_devices.h"

VkResult create_logical_device(VkPhysicalDevice physical_device, uint32_t queue_count, VkQueueFlagBits* queue_flags, uint32_t* queue_indices, VkDevice* out_logical_device) {
    if(physical_device == NULL) {
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    float queuePriority = 0.5f;
    VkDeviceQueueCreateInfo* queue_create_infos = malloc(sizeof(VkDeviceQueueCreateInfo) * queue_count);
    for(uint32_t i = 0; i < queue_count; ++i) {
        queue_create_infos[i] = (VkDeviceQueueCreateInfo) {
            .queueFamilyIndex = queue_indices[i],
            .flags = queue_flags[i],

            .queueCount = 1,
            .pQueuePriorities = &queuePriority,

            .sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO,
            .pNext = NULL
        };
    } 

    VkDeviceCreateInfo device_create_info = {
        .queueCreateInfoCount = queue_count,
        .pQueueCreateInfos = queue_create_infos,

        .enabledExtensionCount = 0,
        .ppEnabledExtensionNames = NULL,

        .enabledLayerCount = 0,
        .ppEnabledLayerNames = NULL,

        .pEnabledFeatures = NULL,

        .flags = 0,

        .sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO,
        .pNext = NULL
    };

    VkResult result = vkCreateDevice(physical_device, &device_create_info, NULL, out_logical_device);

    free(queue_create_infos);

    return result;
}