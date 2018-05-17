#include "cMesh.h"

Mesh::Mesh()
{
}


Mesh::Mesh(Vertex* vertices, unsigned int numVertices)
{
	m_drawCount = numVertices;

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);


	glGenBuffers(NUM_BUFFERS, VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO[POSITION_VB]);
	glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(vertices[0]), vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

}

//void Mesh::drawSquare(Vertex* vertices, unsigned int numVertices)
//{
//
//	glEnableClientState(GL_VERTEX_ARRAY);
//	glVertexPointer(3, GL_FLOAT, 0, vertices);
//	glDrawArrays(GL_QUADS, 0, 4);
//	glDisableClientState(GL_VERTEX_ARRAY);
//
//	//glGenVertexArrays(1, &VAO);
//	//glBindVertexArray(VAO);
//
//
//	//glGenBuffers(NUM_BUFFERS, VBO);
//
//	//glBindBuffer(GL_ARRAY_BUFFER, VBO[POSITION_VB]);
//	//glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(vertices[0]), vertices, GL_STATIC_DRAW);
//
//	//glEnableVertexAttribArray(0);
//
//	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
//
//	//glBindBuffer(GL_ARRAY_BUFFER, 0);
//
//	//glBindVertexArray(0);
//
//
//}

void Mesh::drawTriangle(Vertex* vertices, unsigned int numVertices)
{
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);


	glGenBuffers(NUM_BUFFERS, VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO[POSITION_VB]);
	glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(vertices[0]), vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);

	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

}




void Mesh::Draw()
{
	glBindVertexArray(VAO);
	//glDrawArrays(GL_TRIANGLES, 0, m_drawCount);
	//glDrawArrays(GL_QUADS, 0, m_drawCount);

	glDrawArrays(GL_POLYGON, 0, m_drawCount);

	glBindVertexArray(0);
}

Mesh:: ~Mesh()
{
	glDeleteVertexArrays(1, &VAO);
}