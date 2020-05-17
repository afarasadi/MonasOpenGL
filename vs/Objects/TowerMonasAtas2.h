#pragma once
#include "../Headers/Mesh2.h"
#include <iostream>

static Mesh2* TowerMonasAtas2()
{
	const GLfloat x1 = 0.5;
	const GLfloat x2 = 1;
	Vertex2 vertices[] = {
		// format position, tex coords
		// front
		Vertex2(glm::vec3(x1, 20.1, 0.5), glm::vec3(0, 0, x1)),   // 1
		Vertex2(glm::vec3(-x1, 20.1, 0.5), glm::vec3(x1, 0, x1)),  // 0
		Vertex2(glm::vec3(-x2,  20.5, 1), glm::vec3(x2, x2, x2)),  // 3
		Vertex2(glm::vec3(x2,  20.5, 1), glm::vec3(0, x2, x2)),   // 2



		// right
		Vertex2(glm::vec3(x1, 20.1,  0.5), glm::vec3(0, 0, x1)),  // 7
		Vertex2(glm::vec3(x1, 20.1, -0.5), glm::vec3(x1, 0, x1)),  // 6
		Vertex2(glm::vec3(x2,  20.5, -1), glm::vec3(x2, x2, x2)),  // 5
		Vertex2(glm::vec3(x2,  20.5,  1), glm::vec3(0, x2, x2)),  // 4



		// back
		Vertex2(glm::vec3(x1,  20.1, -0.5), glm::vec3(0, 0, x1)), // 9
		Vertex2(glm::vec3(-x1, 20.1, -0.5), glm::vec3(x1, 0, x1)), // 8 
		Vertex2(glm::vec3(-x2,  20.5, -1), glm::vec3(x2, x2, x2)), // 11
		Vertex2(glm::vec3(x2,   20.5, -1), glm::vec3(0, x2, x2)), // 10


		// left
		Vertex2(glm::vec3(-x2,  20.5,  1), glm::vec3(0, 0, x2)), // 14
		Vertex2(glm::vec3(-x2,  20.5, -1), glm::vec3(x2, 0, x2)), // 15
		Vertex2(glm::vec3(-x1, 20.1, -0.5), glm::vec3(x1, x1, x1)), // 12
		Vertex2(glm::vec3(-x1, 20.1,  0.5), glm::vec3(0, x1, x1)), // 13


		// upper
		Vertex2(glm::vec3(x2, 20.5,  1), glm::vec3(0, 0, x2)),   // 16
		Vertex2(glm::vec3(-x2, 20.5,  1), glm::vec3(x2, 0, x2)),  // 17
		Vertex2(glm::vec3(-x2, 20.5, -1), glm::vec3(x2, x2, x2)),  // 18
		Vertex2(glm::vec3(x2, 20.5, -1), glm::vec3(0, x2, x2)),   // 19

		// bottom
		Vertex2(glm::vec3(x2, 20.1,  1), glm::vec3(0, 0, x2)),   // 16
		Vertex2(glm::vec3(-x2, 20.1,  1), glm::vec3(x2, 0, x2)),  // 17
		Vertex2(glm::vec3(-x2, 20.1, -1), glm::vec3(x2, x2, x2)),  // 18
		Vertex2(glm::vec3(x2, 20.1, -1), glm::vec3(0, x2, x2)),   // 19

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