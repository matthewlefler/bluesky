#ifndef WINDOW_C
#define WINDOW_C

#include "window.h"

int window_create(int width, int height, Window* window, char* name) {
    if(glfwInit() == GLFW_FALSE) {
        return 0;
    }

    // window hints
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // don't create the opengl context
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); // make window not able to be re-sized

    window->name = name;
    window->width = width;
    window->height = height;
    window->window_ptr = glfwCreateWindow(width, height, "Vulkan", NULL, NULL);

    return 1;
}

int window_cleanup(Window* window) {
    glfwDestroyWindow(window->window_ptr);
    window->window_ptr = NULL;

    glfwTerminate();

    return 1;
}

#endif
