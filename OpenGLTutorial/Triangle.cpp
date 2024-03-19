#include <iostream>
#include <glad\glad.h>
#include <GLFW\glfw3.h>
#include "Shader.h"
#include"VBO.h"
#include"VAO.h"
#include"EBO.h"

using namespace std;

int main()
{
	glfwInit();

	//Cấu hình OpenGL
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//Cấu hình profile (ở đây là CORE)
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLfloat vertices[] =
	{
		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
		0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
		0.0f, 0.5f * float(sqrt(3)) / 3, 0.0f
	};

	//Khởi tạo cửa sổ window
	GLFWwindow* window = glfwCreateWindow(800, 800, "Triangle in OpenGL", NULL, NULL);
	if (window == NULL)
	{
		cout << "Failed to create GLFW window" << endl;
		glfwTerminate();
		return 0;
	}

	//Nói với opengl rằng đã tạo cữa sổ, biến cửa sổ thành ngữ cảnh
	glfwMakeContextCurrent(window);

	//Tải glad để cấu hình OpenGL
	gladLoadGL();

	//Chỉ định viewport của window
	glViewport(0, 0, 800, 800);

	//Tạo trình đổ bóng (Create shader)
	Shader shaderProgram("default.frag", "default.vert");


	//Gửi nội dung đến CPU và GPU theo lô lớn
	//vao: là mảng chứa các vbo, vbo chữa các đỉnh của hình cần vẽ
	VAO vao1;
	vao1.Bind();

	VBO vbo(vertices, sizeof(vertices));

	vao1.LinkVBO(vbo, 0);
	vao1.Unbind();
	vbo.Unbind();

	//Đảm bảo cửa sổ luôn mở
	while (!glfwWindowShouldClose(window))
	{
		//Chỉ định màu cho nền
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		//Xóa nền hiện tại và thay bằng màu mới
		glClear(GL_COLOR_BUFFER_BIT);

		shaderProgram.Activate(); //Sử dụng trình đổ bóng
		vao1.Bind();
		glDrawArrays(GL_TRIANGLES, 0, 3);
		//Đổi buffer sau bằng buffer trước
		glfwSwapBuffers(window);

		//Bắt các sự kiện GLFW
		glfwPollEvents();
	}

	//Hủy
	vao1.Delete();
	vbo.Delete();
	shaderProgram.Delete(); //Hủy chương trình

	//Hủy cửa sổ
	glfwDestroyWindow(window);
	glfwTerminate();
}