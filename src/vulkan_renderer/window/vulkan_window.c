#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>

#include "vulkan_window.h"

VkResult create_surface(VkInstance instance, GLFWwindow *window, VkSurfaceKHR *surface) {
    return glfwCreateWindowSurface(instance, window, NULL, surface);
}