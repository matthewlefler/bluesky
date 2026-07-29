#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW/glfw3.h>

typedef struct Window {
    int width;
    int height;
    GLFWwindow* window_ptr;
    char* name;
} Window;

int window_create(int width, int height, Window* window, char* name);

int window_cleanup(Window* window);

#endif
