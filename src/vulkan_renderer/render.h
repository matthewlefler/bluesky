#ifndef RENDER_H
#define RENDER_H

#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>

#include "window/window.h"
#include "devices/devices.h"
#include "extensions.h"

typedef struct Renderer {
    Window window;
    VkInstance vk_instance;
    VkDebugUtilsMessengerEXT debug_messenger;

    size_t num_devices;
    Device* devices;
} Renderer;

// add/free device
// add/free queues
// add/free/re-create pipelines

VkResult vulkan_renderer_init(
    const ExtensionList instance_extensions,
    uint32_t (*physical_device_score_function)(VkPhysicalDeviceProperties2), 
    const VkPhysicalDeviceFeatures2 *device_feature_requirements, 
    const uint32_t device_extension_count, const char* const *device_extension_requirements, 
    const uint32_t queue_flags_count, const VkQueueFlagBits *queue_flags,

    uint32_t (*score_surface_format)(VkSurfaceFormat2KHR),
    uint32_t (*score_presentation_mode)(VkPresentModeKHR),
    VkExtent2D (*get_window_extent)(VkSurfaceCapabilities2KHR),
    uint32_t (*get_min_image_count)(VkSurfaceCapabilities2KHR),

    Renderer* out_renderer
);

VkResult vulkan_renderer_run(Renderer* renderer);

VkResult vulkan_renderer_cleanup(Renderer* renderer);

#endif