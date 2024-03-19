#include <iostream>
#include <GLFW/glfw3.h>

using namespace std;

int main()
{
	glfwInit();

	//C?u h�nh OpenGL
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//C?u h�nh profile (? ?�y l� CORE)
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//Kh?i t?o c?a s? window
	GLFWwindow* window = glfwCreateWindow(800, 800, "First day in OpenGL", NULL, NULL);
	if (window == NULL)
	{
		cout << "Failed to create GLFW window" << endl;
	}

	//N�i v?i opengl r?ng ?� t?o c?a s?, bi?n c?a s? th�nh ng? c?nh
	glfwMakeContextCurrent(window);

	//Ch? ??nh viewport c?a window
	glViewport(0, 0, 800, 800);
	//Ch? ??nh m�u cho n?n
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	//X�a n?n hi?n t?i v� thay b?ng m�u m?i
	glClear(GL_COLOR_BUFFER_BIT);
	//??i buffer sau b?ng buffer tr??c
	glfwSwapBuffers(window);

	//??m b?o c?a s? lu�n m?
	while (!glfwWindowShouldClose(window))
	{
		//B?t c�c s? ki?n GLFW
		glfwPollEvents();
	}

	//H?y c?a s?
	glfwDestroyWindow(window);
	glfwTerminate();
}