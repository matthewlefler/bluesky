#ifndef WINDOW_H
#define WINDOW_H

#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>

typedef struct Window {
    int width;
    int height;
    GLFWwindow* window_ptr;
    VkSurfaceKHR surface;
    char* name;
} Window;

VkResult window_create(VkInstance instance, int width, int height, char* name, Window* out_window);

void window_free(VkInstance instance, Window window);

#endif // WINDOW_H