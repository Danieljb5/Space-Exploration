#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include "renderer.h"
#include "util.h"
#include <iostream>

int width, height;

static const struct Vertex
{
	float x, y;
	float r, g, b;
}vertices[3] = 
{
	{ -0.6f, -0.4f, 1.f, 0.f, 0.f },
	{  0.6f, -0.4f, 0.f, 1.f, 0.f },
	{   0.f,  0.6f, 0.f, 0.f, 1.f }
};
static const char* vertex_shader_text = 
	"#version 110\n"
    "uniform mat4 MVP;\n"
    "attribute vec3 vCol;\n"
    "attribute vec2 vPos;\n"
    "varying vec3 color;\n"
    "void main()\n"
    "{\n"
    "    gl_Position = MVP * vec4(vPos, 0.0, 1.0);\n"
    "    color = vCol;\n"
    "}\n";
static const char* fragment_shader_text =
	"#version 110\n"
    "varying vec3 color;\n"
    "void main()\n"
    "{\n"
    "    gl_FragColor = vec4(color, 1.0);\n"
    "}\n";

int main()
{
	GLFWwindow* window;
	GLuint vertexBuffer, vertexShader, fragmentShader, program;
	GLint mvpLocation, vposLocation, vcolLocation;

	if(!glfwInit())
	{
		std::cout << "Failed to initialise glfw" << std::endl;
		return -1;
	}
	glfwSetErrorCallback(Util::errorCallback);

	width = 1920;
	height = 1080;

	glfwDefaultWindowHints();
	window = glfwCreateWindow(width, height, "Space Exploration", glfwGetPrimaryMonitor(), NULL);
	if(!window)
	{
		std::cout << "Failed to initialise window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwSetKeyCallback(window, Util::key_callback);
	glfwMakeContextCurrent(window);
	gladLoadGL();
	glfwSwapInterval(1);

	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertex_shader_text, NULL);
	glCompileShader(vertexShader);

	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragment_shader_text, NULL);
	glCompileShader(fragmentShader);

	program = glCreateProgram();
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);
	glLinkProgram(program);

	mvpLocation = glGetUniformLocation(program, "MVP");
	vposLocation = glGetAttribLocation(program, "vPos");
	vcolLocation = glGetAttribLocation(program, "vCol");

	glEnableVertexAttribArray(vposLocation);
	glVertexAttribPointer(vposLocation, 2, GL_FLOAT, GL_FALSE, sizeof(vertices[0]), (void*) 0);
	glEnableVertexAttribArray(vcolLocation);
	glVertexAttribPointer(vcolLocation, 3, GL_FLOAT, GL_FALSE, sizeof(vertices[0]), (void*) (sizeof(float) * 2));
	

	Renderer renderer = {window, program, mvpLocation};


	double time = glfwGetTime();
	double lastTime = 0;

	while(!glfwWindowShouldClose(window))
	{
		time = glfwGetTime();
		double dt = time - lastTime;
		lastTime = time;

		renderer.render();
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}