#include <iostream>
#define GLEW_BUILD
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main() {
	GLFWwindow* window;
	
	if (glfwInit() != GLFW_TRUE) {
		std::cout << "[ERROR] Unable to initlilaze GLFW\n";
		glfwTerminate();
		return -1;
	}

	window = glfwCreateWindow(640, 480, "Hello world", NULL, NULL);
	
	if (!window) {
		std::cout << "[ERROR] Unable to create GLFW window\n";
		glfwTerminate();
		return -2;
	}

	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK) {
		std::cout << "[ERROR] Unable to initliaze OpenGL\n";
		glfwTerminate();
		return -3;
	}

	std::cout << glGetString(GL_VERSION) << std::endl;

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_TRIANGLES);
		glVertex2d( 0.5, -0.5);
		glVertex2d(-0.5, -0.5);
		glVertex2d( 0.0,  0.5);
		glEnd();

		glfwSwapBuffers(window);

		glfwPollEvents();
	}


}