#ifndef VBO_H
#define VBO_H


#include <glad/glad.h>

class VBO //Vertex buffer
{
	public:
		//Tham chiếu đến ID của vertex buffer
		GLuint ID;

		//Hàm khởi tạo
		VBO(GLfloat* vertices, GLsizeiptr size);

		void Bind();
		void Unbind();
		void Delete();
};

#endif // !VBO_H
