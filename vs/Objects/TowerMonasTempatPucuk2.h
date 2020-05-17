#pragma once
#include "../Headers/Mesh2.h"
#include <iostream>

static Mesh2* TowerMonasTempatPucuk2()
{
	const GLfloat x1 = 1;
	const GLfloat x2 = 1.1;

	const GLfloat y1 = 20.5;
	const GLfloat y2 = 20.7;

	const GLfloat z1 = 1;
	const GLfloat z2 = 1.1;

	Vertex2 vertices[] = {
		// format position, tex coords
		// front
		Vertex2(glm::vec3(x2,  20.7, 1.1), glm::vec3(0, 0, x2)),   // 2
		Vertex2(glm::vec3(-x2,  20.7, 1.1), glm::vec3(x2, 0, x2)),  // 3
		Vertex2(glm::vec3(-x1, 20.5, 1), glm::vec3(x1, x1, x1)),  // 0
		Vertex2(glm::vec3(x1, 20.5, 1), glm::vec3(0, x1, x1)),   // 1


		// right
		Vertex2(glm::vec3(x2,  20.7,  1.1), glm::vec3(0, 0, x2)),  // 4
		Vertex2(glm::vec3(x2,  20.7, -1.1), glm::vec3(x2, 0, x2)),  // 5
		Vertex2(glm::vec3(x1, 20.5, -1), glm::vec3(x1, x1, x1)),  // 6
		Vertex2(glm::vec3(x1, 20.5,  1), glm::vec3(0, x1, x1)),  // 7


		// back

		Vertex2(glm::vec3(x2,   20.7, -1.1), glm::vec3(0, 0, x2)), // 10
		Vertex2(glm::vec3(-x2,  20.7, -1.1), glm::vec3(x2, 0, x2)), // 11
		Vertex2(glm::vec3(-x1, 20.5, -1), glm::vec3(x1, x1, x1)), // 8 
		Vertex2(glm::vec3(x1,  20.5, -1), glm::vec3(0, x1, x1)), // 9

		// left
		Vertex2(glm::vec3(-x2,  20.7,  1.1), glm::vec3(0, 0, x2)), // 14
		Vertex2(glm::vec3(-x2,  20.7, -1.1), glm::vec3(x2, 0, x2)), // 15
		Vertex2(glm::vec3(-x1, 20.5, -1), glm::vec3(x1, x1, x1)), // 12
		Vertex2(glm::vec3(-x1, 20.5,  1), glm::vec3(0, x1, x1)), // 13


		// upper
		Vertex2(glm::vec3(x2, 20.7,  1.1), glm::vec3(0, 0, x2)),   // 16
		Vertex2(glm::vec3(-x2, 20.7,  1.1), glm::vec3(x2, 0, x2)),  // 17
		Vertex2(glm::vec3(-x2, 20.7, -1.1), glm::vec3(x2, x2, x2)),  // 18
		Vertex2(glm::vec3(x2, 20.7, -1.1), glm::vec3(0, x2, x2)),   // 19

		// bottom
		Vertex2(glm::vec3(0, 0, 0), glm::vec3(0, 0, x1)), // 20
		Vertex2(glm::vec3(x1, 0, 0), glm::vec3(x1, 0, x1)),  // 21
		Vertex2(glm::vec3(x1, 0,  1), glm::vec3(x1, x1, x1)),  // 22
		Vertex2(glm::vec3(0, 0,  1), glm::vec3(0, x1, x1)) // 23

	};

	unsigned int indices[] = {
		8,  10,  9, 8,  11, 10,  // back
		20, 21, 22, 20, 22, 23,   // bottom
		4,  6,  5,  4,  7,  6,   // right
		12, 14, 13, 12, 15, 14,  // left
		16, 18, 17, 16, 19, 18,  // upper
		0,  2,  1,  0, 3,  2   // front

	};

	return new Mesh2(vertices, sizeof(vertices) / sizeof(vertices[0]), indices, sizeof(indices) / sizeof(indices[0]));
}