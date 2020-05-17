#pragma once
#include "../Headers/Mesh2.h"
static Mesh2* Pucuk()
{
	const GLfloat x1 = 0.9 - 0.85;
	const GLfloat x2 = 1.1 - 0.7;
	const GLfloat z1 = 0.1;
	const GLfloat z2 =0.5;
	const GLfloat y = 2.f;

	Vertex2 vertices[] = {
		// format position, tex coords
		// front
		Vertex2(glm::vec3(x1,  20.9 + y, z1), glm::vec3(0, 0, x1)),   // 2
		Vertex2(glm::vec3(-x1,  20.9 + y, z1), glm::vec3(x1, 0, x1)),  // 3
		Vertex2(glm::vec3(-x2, 20.9,z2), glm::vec3(x2, x2, x2)),  // 0
		Vertex2(glm::vec3(x2, 20.9 ,z2), glm::vec3(0, x2, x2)),   // 1


		// right
		Vertex2(glm::vec3(x1,  20.9 + y,  z1), glm::vec3(0, 0, x1)),  // 4
		Vertex2(glm::vec3(x1,  20.9 + y, -z1), glm::vec3(x1, 0, x1)),  // 5
		Vertex2(glm::vec3(x2, 20.9, -z2), glm::vec3(x2, x2, x2)),  // 6
		Vertex2(glm::vec3(x2, 20.9, z2), glm::vec3(0, x2, x2)),  // 7


		// back
		Vertex2(glm::vec3(x1,   20.9 + y, -z1), glm::vec3(0, 0, x1)), // 10
		Vertex2(glm::vec3(-x1,  20.9 + y, -z1), glm::vec3(x1, 0, x1)), // 11
		Vertex2(glm::vec3(-x2, 20.9, -z2), glm::vec3(x2, x2, x2)), // 8 
		Vertex2(glm::vec3(x2,  20.9, -z2), glm::vec3(0, x2, x2)), // 9


		// left
		Vertex2(glm::vec3(-x1,  20.9 + y,  z1), glm::vec3(0, 0, x1)), // 14
		Vertex2(glm::vec3(-x1,  20.9 + y, -z1), glm::vec3(x1, 0, x1)), // 15
		Vertex2(glm::vec3(-x2, 20.9, -z2), glm::vec3(x2, x2, x2)), // 12
		Vertex2(glm::vec3(-x2, 20.9, z2), glm::vec3(0, x2, x2)), // 13


		// upper
		Vertex2(glm::vec3(0, 0 + 0,  0), glm::vec3(0, 0, x1)),   // 16
		Vertex2(glm::vec3(0, 0 + 0,  0), glm::vec3(x1, 0, x1)),  // 17
		Vertex2(glm::vec3(0, 0 + 0, -0), glm::vec3(x1, x1, x1)),  // 18
		Vertex2(glm::vec3(0, 0 + 0, -0), glm::vec3(0, x1, x1)),   // 19

		// bottom
		Vertex2(glm::vec3(0, 0, 0), glm::vec3(0, 0, x1)), // 20
		Vertex2(glm::vec3(1, 0, 0), glm::vec3(x1, 0, x1)),  // 21
		Vertex2(glm::vec3(1, 0,  1), glm::vec3(x2, x2, x2)),  // 22
		Vertex2(glm::vec3(0, 0,  1), glm::vec3(0, x2, x2)) // 23

	};

	unsigned int indices[] = {
		8,  9,  10, 8,  10, 11,  // back
		20, 22, 21, 20, 23, 22,   // bottom
		4,  5,  6,  4,  6,  7,   // right
		12, 14, 13, 12, 15, 14,  // left
		16, 18, 17, 16, 19, 18,  // upper
		0,  1,  2,  0,  2,  3   // front

	};

	return new Mesh2(vertices, sizeof(vertices) / sizeof(vertices[0]), indices, sizeof(indices) / sizeof(indices[0]));
}