#ifndef RENDER_H
#define RENDER_H

#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>

#include "window.h"
#include "devices/devices.h"

typedef struct Renderer {
    Window window;
    VkInstance vk_instance;
    VkDebugUtilsMessengerEXT debug_messenger;

    Device* devices;
} Renderer;

VkResult vulkan_renderer_init(
    Renderer* renderer, 
    uint32_t (*physical_device_score_function)(VkPhysicalDeviceProperties2), 
    VkPhysicalDeviceFeatures2 *device_feature_requirements, 
    uint32_t queue_flags_count, 
    VkQueueFlagBits *queue_flags
);

VkResult vulkan_renderer_run(Renderer* renderer);

VkResult vulkan_renderer_cleanup(Renderer* renderer);

#endif