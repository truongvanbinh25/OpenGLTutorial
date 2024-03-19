//#include <iostream>
//#include <GLFW/glfw3.h>
//
//using namespace std;
//
//int main()
//{
//	glfwInit();
//
//	//Cấu hình OpenGL
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	//Cấu hình profile (ở đây là CORE)
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	//Khởi tạo cửa sổ window
//	GLFWwindow* window = glfwCreateWindow(800, 800, "First day in OpenGL", NULL, NULL);
//	if (window == NULL)
//	{
//		cout << "Failed to create GLFW window" << endl;
//	}
//
//	//Nói với opengl rằng đã tạo cữa sổ, biến cửa sổ thành ngữ cảnh
//	glfwMakeContextCurrent(window);
//	
//	//Chỉ định viewport của window
//	glViewport(0, 0, 800, 800);
//	//Chỉ định màu cho nền
//	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
//	//Xóa nền hiện tại và thay bằng màu mới
//	glClear(GL_COLOR_BUFFER_BIT);
//	//Đổi buffer sau bằng buffer trước
//	glfwSwapBuffers(window);
//
//	//Đảm bảo cửa sổ luôn mở
//	while (!glfwWindowShouldClose(window))
//	{
//		//Bắt các sự kiện GLFW
//		glfwPollEvents();
//	}
//
//	//Hủy cửa sổ
//	glfwDestroyWindow(window);
//	glfwTerminate();
//}