#pragma once
#include <GLAD/glad.h>
#include "glm/glm.hpp"

struct Vertex2
{
public:
	Vertex2(const glm::vec3& pos, const glm::vec3& texCoord = glm::vec3(0, 0, 0), const glm::vec3& normal = glm::vec3())
	{
		this->pos = pos;
		this->texCoord = texCoord;
		this->normal = normal;
	}

	glm::vec3 pos;
	glm::vec3 texCoord;
	glm::vec3 normal;
};

enum MeshBufferPositions2
{
	POSITION_VB2,
	TEXCOORD_VB2,
	NORMAL_VB2,
	INDEX_VB2,

	NUM_BUFFERS2
};

class Mesh2
{
public:
	Mesh2(Vertex2* vertices, unsigned int numVertices, unsigned int* indices, unsigned int numIndices, bool generateNormal = true);
	~Mesh2();
	void Draw();

private:
	GLuint VAO;
	GLuint VBO[NUM_BUFFERS2];
	unsigned int drawCount;
	glm::vec3 calcNormal(const glm::vec3& p1, const glm::vec3& p2, const glm::vec3& p3);
};

