#ifndef VERTEX_H
#define VERTEX_H
#include <vector>
#include <glm\glm.hpp>

class Vertex
{
private:
	glm::vec3 pos;
	

public:
	Vertex(const glm::vec3& pos)
	{
		this->pos = pos;
	}

	Vertex(float x, float y, float z)
	{		float value[] = { x, y, z };
		this->pos = glm::vec3(value[0], value[1], value[2]);	
	}

	Vertex(double x, double y, double z)
	{
		double value[] = { x, y, z };
		this->pos = glm::vec3(value[0], value[1], value[2]);
	}

};


#endif
