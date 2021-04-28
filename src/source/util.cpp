#include "util.h"
#include <iostream>

void Util::errorCallback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

void  Util::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}