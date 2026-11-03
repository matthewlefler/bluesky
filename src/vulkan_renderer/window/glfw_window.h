#ifndef GLFW_WINDOW_H
#define GLFW_WINDOW_H

#include <GLFW/glfw3.h>

#include "window.h"

bool glfw_window_create(int width, int height, Window* window, char* name);

void glfw_window_free(Window* window);

#endif // GLFW_WINDOW_H
