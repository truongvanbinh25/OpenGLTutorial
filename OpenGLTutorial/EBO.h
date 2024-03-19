#ifndef EBO_H
#define EBO_H


#include <glad/glad.h>

class EBO //Vertex buffer
{
public:
	GLuint ID;
	EBO(GLfloat* indices, GLsizeiptr size);

	void Bind();
	void Unbind();
	void Delete();
};

#endif // !EBO_H

