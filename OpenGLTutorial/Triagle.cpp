#include <iostream>
#include <GLFW/glfw3.h>

using namespace std;

int main()
{
	glfwInit();

	//C?u hình OpenGL
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//C?u hình profile (? ?ây là CORE)
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//Kh?i t?o c?a s? window
	GLFWwindow* window = glfwCreateWindow(800, 800, "First day in OpenGL", NULL, NULL);
	if (window == NULL)
	{
		cout << "Failed to create GLFW window" << endl;
	}

	//Nói v?i opengl r?ng ?ã t?o c?a s?, bi?n c?a s? thành ng? c?nh
	glfwMakeContextCurrent(window);

	//Ch? ??nh viewport c?a window
	glViewport(0, 0, 800, 800);
	//Ch? ??nh màu cho n?n
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	//Xóa n?n hi?n t?i và thay b?ng màu m?i
	glClear(GL_COLOR_BUFFER_BIT);
	//??i buffer sau b?ng buffer tr??c
	glfwSwapBuffers(window);

	//??m b?o c?a s? luôn m?
	while (!glfwWindowShouldClose(window))
	{
		//B?t các s? ki?n GLFW
		glfwPollEvents();
	}

	//H?y c?a s?
	glfwDestroyWindow(window);
	glfwTerminate();
}