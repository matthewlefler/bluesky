#include <GLFW/glfw3.h>

#include "logger.h"
#include "glfw_window.h"

bool glfw_window_create(int width, int height, Window* window, char* name) {
    // window hints
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // don't create the opengl context
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); // make window not able to be re-sized

    window->name = name;
    window->width = width;
    window->height = height;
    window->window_ptr = glfwCreateWindow(width, height, name, NULL, NULL);

    if(window->window_ptr == NULL) {
        log_message(LOG_LEVEL_FATAL, "glfw_window_create -> GLFW window could not be created");
        return false;
    }

    log_message(LOG_LEVEL_VERBOSE, "glfw_window_create -> GLFW window created");
    return true;
}

void glfw_window_free(Window* window) {
    glfwDestroyWindow(window->window_ptr);
    window->window_ptr = NULL;

    glfwTerminate();
}
