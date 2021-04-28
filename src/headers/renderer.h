
#ifndef RENDERER_H
#define RENDERER_H

#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

class Renderer
{
public:
    Renderer(GLFWwindow* window, GLuint program, GLint mvpLocation);
    ~Renderer();

    void render();

private:
    GLFWwindow* window;
    GLuint program;
    GLint mvpLocation;
};


#endif
