#ifndef VULKAN_WINDOW_H
#define VULKAN_WINDOW_H

#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>

VkResult create_surface(VkInstance instance, GLFWwindow *window, VkSurfaceKHR *surface);

#endif // VULKAN_WINDOW_H