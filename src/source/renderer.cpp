#include <linmath.h>
#include "renderer.h"
#include <iostream>

int minLayer = -1;
int maxLayer = 8;

Renderer::Renderer(GLFWwindow* window, GLuint program, GLint mvpLocation)
{
    this->window = window;
    this->program = program;
    this->mvpLocation = mvpLocation;
}

Renderer::~Renderer()
{

}

void Renderer::render()
{
    float ratio;
    int width, height;
    mat4x4 m, p, mvp;
    glfwGetFramebufferSize(window, &width, &height);
    ratio = width / (float) height;

    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT);

    mat4x4_identity(m);
    mat4x4_rotate_Z(m, m, (float) glfwGetTime());
    mat4x4_ortho(p, -ratio, ratio, -1.f, 1.f, 1.f, -1.f);
    mat4x4_mul(mvp, p, m);

    glUseProgram(program);
    glUniformMatrix4fv(mvpLocation, 1, GL_FALSE, (const GLfloat*)mvp);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glfwSwapBuffers(window);
}