#include "Shader.h"

string GetFileContents(const char* filename)
{
	ifstream in (filename, ios::binary);
	if (in)
	{
		string contents;
		in.seekg(0, ios::end);
		contents.resize(in.tellg());
		in.seekg(0, ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return contents;
	}
	throw(errno);

	
}

Shader::Shader(const char* vertexFile, const char* fragmentFile)
{
	string vertexCode = GetFileContents(vertexFile);
	string fragmentCode = GetFileContents(fragmentFile);

	const char* vertexSource = vertexCode.c_str();
	const char* fragmentSource = fragmentCode.c_str();

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER); //đỉnh
	glShaderSource(vertexShader, 1, &vertexSource, NULL); //paramater(GLunit shader, Glsizei count, const GLchar **string,lenght) 
	glCompileShader(vertexShader); //biên dịch thành mã máy

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER); // manh
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL); //paramater(GLunit shader, Glsizei count, const GLchar **string,lenght) 
	glCompileShader(fragmentShader); //biên dịch thành mã máy

	//Tổng hợp 2 trình đổ bóng
	ID = glCreateProgram();
	//Đính kèm tệp đổ bóng vào chương trình
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	//Sau khi đính kèm sẽ kết thúc trình đổ bóng
	glLinkProgram(ID);

	//xóa các trính đổ bóng vì đã có trong chương trình
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::Activate()
{
	glUseProgram(ID);
}

void Shader::Delete()
{
	glDeleteProgram(ID);
}