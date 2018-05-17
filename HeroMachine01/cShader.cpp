#include "cShader.h"

using namespace std;
void Shader::Bind()
{

	glUseProgram(glProgram);

}
void Shader:: LinkShader()
{
	GLint success;
	GLchar infolog[512];

	glProgram = glCreateProgram();

	for (unsigned int i = 0; i < glShaders.size(); i++)
	{
		glAttachShader(glProgram, glShaders[i]);
	}

	glLinkProgram(glProgram);
	glGetProgramiv(glProgram, GL_LINK_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(glProgram, 512, NULL, infolog);
		cout << "ERROR: SHADER PROGRAM FAILURE\n" << infolog << endl;
	}

	for (unsigned int i = 0; i < glShaders.size(); i++)
	{
		glDeleteShader(glShaders[i]);
	}
}




Shader::Shader(string fileName)
{
	glShaders.push_back(CreateShader(LoadShader(fileName + ".vs"), GL_VERTEX_SHADER));
	glShaders.push_back(CreateShader(LoadShader(fileName + ".fs"), GL_FRAGMENT_SHADER));
	LinkShader();
}

GLuint Shader::CreateShader(const string & text, GLenum shaderType)
{
	GLint success;
	GLchar infolog[512];
	GLuint Shader = glCreateShader(shaderType);

	const GLchar* shaderSourceString[1];
	shaderSourceString[0] = text.c_str();
	GLint shaderSourceStringLengths[1];	
	shaderSourceStringLengths[0] = text.length();

	glShaderSource(Shader, 1, shaderSourceString, NULL);
	glCompileShader(Shader);
	glGetShaderiv(Shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(Shader, 512, NULL, infolog);
		cout << "ERROR:  SHADER: ["<< shaderType <<"] COMILIE FAILURE\n" << infolog << endl;
	}

	return Shader;
}

string Shader::LoadShader(const string & fileName)
{
	ifstream file;
	file.open((fileName).c_str());

	string output;
	string line;

	if (file.is_open())
	{
		cout << "\nFILE " << fileName << " is open" << endl;
		while (file.good())
		{
			getline(file, line);
			output.append(line + "\n");
			cout << "\n " << line << " \n";
		}
	}
	else
	{
		cerr << "\nUNABLE TO LAOD SHADER" << fileName << endl;
	}



	return output;
}
