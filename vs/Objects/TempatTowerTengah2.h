#pragma once
#include "../Headers/Mesh2.h"
#include <iostream>

static Mesh2* TempatTowerTengah2()
{
	
	const GLfloat x1 = 1;
	const GLfloat x2 = 3;

	const GLfloat y1 = 1.3;
	const GLfloat y2 = 3;

	const GLfloat z1 = 1;
	const GLfloat z2 = 3;

	const GLfloat multiplier = 4;

	Vertex2 vertices[] = {
		// format position, tex coords
		// front
		Vertex2(glm::vec3(x2,  3, 3), glm::vec3(0, 0, x2 / multiplier)),   // 2
		Vertex2(glm::vec3(-x2,  3, 3), glm::vec3(x2, 0, x2 / multiplier)),  // 3
		Vertex2(glm::vec3(-x1, 1.3, 1), glm::vec3(x1, x1, x1 / multiplier)),  // 0
		Vertex2(glm::vec3(x1, 1.3, 1), glm::vec3(0, x1, x1 / multiplier)),   // 1


		// right
		Vertex2(glm::vec3(x2,  3,  3), glm::vec3(0, 0, x2 / multiplier)),  // 4
		Vertex2(glm::vec3(x2,  3, -3), glm::vec3(x2, 0, x2 / multiplier)),  // 5
		Vertex2(glm::vec3(x1, 1.3, -1), glm::vec3(x1, x1, x1 / multiplier)),  // 6
		Vertex2(glm::vec3(x1, 1.3,  1), glm::vec3(0, x1, x1 / multiplier)),  // 7


		// back
		Vertex2(glm::vec3(x2,   3, -3), glm::vec3(0, 0, x2 / multiplier)), // 10
		Vertex2(glm::vec3(-x2,  3, -3), glm::vec3(x2, 0, x2 / multiplier)), // 11
		Vertex2(glm::vec3(-x1, 1.3, -1), glm::vec3(x1, x1, x1 / multiplier)), // 8 
		Vertex2(glm::vec3(x1,  1.3, -1), glm::vec3(0, x1, x1 / multiplier)), // 9


		// left
		Vertex2(glm::vec3(-x2,  3,  3), glm::vec3(0, 0, x2 / multiplier)), // 14
		Vertex2(glm::vec3(-x2,  3, -3), glm::vec3(x2, 0, x2 / multiplier)), // 15
		Vertex2(glm::vec3(-x1, 1.3, -1), glm::vec3(x1, x1, x1 / multiplier)), // 12
		Vertex2(glm::vec3(-x1, 1.3,  1), glm::vec3(0, x1, x1 / multiplier)), // 13


		// upper
		Vertex2(glm::vec3(x2, 3,  3), glm::vec3(0, 0,1)),   // 16
		Vertex2(glm::vec3(-x2, 3,  3), glm::vec3(0, 0,1)),  // 17
		Vertex2(glm::vec3(-x2, 3, -3), glm::vec3(0, 0,1)),  // 18
		Vertex2(glm::vec3(x2, 3, -3), glm::vec3(0, 0,1)),   // 19

		// bottom
		Vertex2(glm::vec3(0, 0, 0), glm::vec3(0, 0,1)), // 20
		Vertex2(glm::vec3(x1, 0, 0), glm::vec3(0, 0,1)),  // 21
		Vertex2(glm::vec3(x1, 0,  1), glm::vec3(0, 0,1)),  // 22
		Vertex2(glm::vec3(0, 0,  1), glm::vec3(0, 0,1)) // 23


	};

	unsigned int indices[] = {
		8,  10,  9, 8,  11, 10,  // back
		20, 21, 22, 20, 22, 23,   // bottom
		4,  6, 5,  4, 7,  6,   // right
		12, 14, 13, 12, 15, 14,  // left
		16, 18, 17, 16, 19, 18,  // upper
		0,  2, 1,  0,  3,  2   // front

	};

	return new Mesh2(vertices, sizeof(vertices) / sizeof(vertices[0]), indices, sizeof(indices) / sizeof(indices[0]));
}