#include <vulkan/vulkan.h>
#include <stdlib.h>

#include "logger.h"

#include "window.h"

#include "glfw_window.h"
#include "vulkan_window.h"

VkResult window_create(VkInstance instance, int width, int height, char* name, Window* out_window) {
    if(!glfw_window_create(width, height, out_window, name)) {
        log_message(LOG_LEVEL_ERROR, "window_create -> unable to create display");
        return VK_ERROR_INCOMPATIBLE_DISPLAY_KHR;
    }

    return create_surface(instance, out_window->window_ptr, &out_window->surface);
}

void window_free(VkInstance instance, Window window) {
    vkDestroySurfaceKHR(instance, window.surface, NULL);

    glfw_window_free(&window);
}