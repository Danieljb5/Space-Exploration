#ifndef UTIL_H
#define UTIL_H

#include <GLFW/glfw3.h>

class Util
{
public:
    static void errorCallback(int error, const char* description);
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
};

#endif