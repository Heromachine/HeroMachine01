#ifndef MESH_H
#define MESH_H
#include <vector>
#include <glm\glm.hpp>
#include <GL\glew.h>
#include "cVertex.h"


class Mesh
{
private:
	
	enum { POSITION_VB, NUM_BUFFERS };
	GLuint VAO;
	GLuint VBO [NUM_BUFFERS];
	unsigned int m_drawCount;

	void  operator=(const Mesh& rhs);
	Mesh(const Mesh& other);


public:
	Mesh();
	Mesh(Vertex* vertices, unsigned int numVertices);
	void drawSquare(Vertex* vertices, unsigned int numVertices);
	void drawTriangle(Vertex* vertices, unsigned int numVertices);
	virtual  ~Mesh();
	void Draw();

};
#endif // !MESH_H
