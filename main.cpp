#include <iostream>
#include <cmath>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "header/shaderClass.h"
#include "header/VAO.h"
#include "header/VBO.h"
#include "header/EBO.h"

GLfloat vertices[] =
	{
		-0.50000000f,
		-0.28867513f,
		0.0f, // v0
		-0.25000000f,
		-0.28867513f,
		0.0f, // v1
		-0.37500000f,
		-0.07216878f,
		0.0f, // v2
		0.00000000f,
		-0.28867513f,
		0.0f, // v3
		-0.12500000f,
		-0.07216878f,
		0.0f, // v4
		-0.25000000f,
		0.14433757f,
		0.0f, // v5
		0.25000000f,
		-0.28867513f,
		0.0f, // v6
		0.12500000f,
		-0.07216878f,
		0.0f, // v7
		0.50000000f,
		-0.28867513f,
		0.0f, // v8
		0.37500000f,
		-0.07216878f,
		0.0f, // v9
		0.25000000f,
		0.14433757f,
		0.0f, // v10
		0.00000000f,
		0.14433757f,
		0.0f, // v11
		-0.12500000f,
		0.36084392f,
		0.0f, // v12
		0.12500000f,
		0.36084392f,
		0.0f, // v13
		0.00000000f,
		0.57735027f,
		0.0f, // v14
};

GLuint indices[] =
	{
		0,
		1,
		2, // triangle 0 (왼쪽 아래 - 왼쪽)
		1,
		3,
		4, // triangle 1 (왼쪽 아래 - 아래)
		2,
		4,
		5, // triangle 2 (왼쪽 아래 - 위)
		3,
		6,
		7, // triangle 3 (오른쪽 아래 - 왼쪽)
		6,
		8,
		9, // triangle 4 (오른쪽 아래 - 아래)
		7,
		9,
		10, // triangle 5 (오른쪽 아래 - 위)
		5,
		11,
		12, // triangle 6 (위 - 왼쪽)
		11,
		10,
		13, // triangle 7 (위 - 아래)
		12,
		13,
		14, // triangle 8 (위 - 위)
};

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow *window = glfwCreateWindow(800, 800, "OpenGL Study", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	gladLoadGL();
	glViewport(0, 0, 800, 800);

	Shader shaderProgram("shaders/default.vert", "shaders/default.frag");

	VAO VAO1;
	VAO1.Bind();
	VBO VBO1(vertices, sizeof(vertices));
	EBO EBO1(indices, sizeof(indices));
	VAO1.LinkVBO(VBO1, 0);
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		shaderProgram.Activate();
		VAO1.Bind();
		glDrawElements(GL_TRIANGLES, 27, GL_UNSIGNED_INT, 0);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	shaderProgram.Delete();
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}