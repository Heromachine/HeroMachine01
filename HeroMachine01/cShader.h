#ifndef SHADER_H
#define SHADER_H
#include <iostream>
#include <fstream>
#include<string>
#include <vector>
#include<GL\glew.h>

using namespace std;
class Shader
{
private:
	Shader(const Shader& other);
	void operator =(const Shader& other) {}

	static const unsigned int NUM_SHADERS = 2;
	//static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const string& errorMessage);
	void LinkShader();

	GLuint glProgram;
	vector <GLuint> glShaders;
	vector <string> fileNames; 

public:

	Shader(string fileNames);
	void Bind();

	//Shader();
	GLuint CreateShader(const string & text, GLenum shaderType);

	//CHECKS	
	static string LoadShader(const string& fileName);

	virtual ~Shader()
	{
		for (unsigned int i = 0; i < NUM_SHADERS; i++)
		{
			glDetachShader(glProgram, glShaders[i]);
			glDeleteShader(glShaders[i]);
		}
		glDeleteProgram(glProgram);
	}	;


};
#endif 

