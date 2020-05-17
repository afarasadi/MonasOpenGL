#pragma once
#include "../Headers/Mesh2.h"
#include <iostream>

static Mesh2* TempatTowerBawah2()
{

	const GLfloat x1 = 0.5;
	const GLfloat x2 = 1;

	const GLfloat y1 = 1.2;
	const GLfloat y2 = 1.3;

	const GLfloat z1 = 0.5;
	const GLfloat z2 = 1;

	const GLfloat multiplier = 4;

	Vertex2 vertices[] = {
		// format position, tex coords
		// front
				Vertex2(glm::vec3(x2,  y2, 1), glm::vec3(0, 0, x2 * multiplier)),   // 2
				Vertex2(glm::vec3(-x2,  y2, 1), glm::vec3(x2, 0, x2 * multiplier)),  // 3
				Vertex2(glm::vec3(x2, y1, 1), glm::vec3(x2, x2, x2 * multiplier)),   // 1
				Vertex2(glm::vec3(-x2, y1, 1), glm::vec3(0, x2, x2 * multiplier)),  // 0


		// right
				Vertex2(glm::vec3(x2,  y2,  1), glm::vec3(0, 0, x2 * multiplier)),  // 4
				Vertex2(glm::vec3(x2,  y2, -1), glm::vec3(x2, 0, x2 * multiplier)),  // 5
				Vertex2(glm::vec3(x2, y1, -1), glm::vec3(x2, x2, x2 * multiplier)),  // 6
				Vertex2(glm::vec3(x2, y1,  1), glm::vec3(0, x2, x2 * multiplier)),  // 7


		// back
				Vertex2(glm::vec3(x2,   y2, -1), glm::vec3(0, 0, x2 * multiplier)), // 10
				Vertex2(glm::vec3(-x2,  y2, -1), glm::vec3(x2, 0, x2 * multiplier)), // 11
				Vertex2(glm::vec3(-x2, y1, -1), glm::vec3(x2, x2, x2 * multiplier)), // 8 
				Vertex2(glm::vec3(x2,  y1, -1), glm::vec3(0, x2, x2 * multiplier)), // 9

		// left
				Vertex2(glm::vec3(-x2,  y2,  1), glm::vec3(0, 0, x2 * multiplier)), // 14
				Vertex2(glm::vec3(-x2,  y2, -1), glm::vec3(x2, 0, x2 * multiplier)), // 15
				Vertex2(glm::vec3(-x2, y1, -1), glm::vec3(x2, x2, x2 * multiplier)), // 12
				Vertex2(glm::vec3(-x2, y1,  1), glm::vec3(0, x2, x2 * multiplier)), // 13

				
		// upper
				Vertex2(glm::vec3(x2, y2,  1), glm::vec3(0, 0, x2 * multiplier)),   // 16
				Vertex2(glm::vec3(-x2, y2,  1), glm::vec3(x2, 0, x2 * multiplier)),  // 17
				Vertex2(glm::vec3(-x2, y2, -1), glm::vec3(x2, x2, x2 * multiplier)),  // 18
				Vertex2(glm::vec3(x2, y2, -1), glm::vec3(0, x2, x2 * multiplier)),   // 19

		// bottom
				Vertex2(glm::vec3(-0.5, -0.5, -0.5), glm::vec3(0, 0, x2 * multiplier)), // 20
				Vertex2(glm::vec3(0.5, -0.5, -0.5), glm::vec3(x2, 0, x2 * multiplier)),  // 21
				Vertex2(glm::vec3(0.5, -0.5,  0.5), glm::vec3(x2, x2, x2 * multiplier)),  // 22
				Vertex2(glm::vec3(-0.5, -0.5,  0.5), glm::vec3(0, x2, x2 * multiplier)) // 23
				

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

static Mesh2* TempatTowerBawah2_Upper()
{

	const GLfloat x1 = 0.5;
	const GLfloat x2 = 1;

	const GLfloat y1 = 1.2;
	const GLfloat y2 = 1.3;

	Vertex2 vertices[] = {
	Vertex2(glm::vec3(x2, y2,  1), glm::vec3(0, 0, x2)),   // 16
	Vertex2(glm::vec3(-x2, y2,  1), glm::vec3(x2, 0, x2)),  // 17
	Vertex2(glm::vec3(-x2, y2, -1), glm::vec3(x2, x2, x2)),  // 18
	Vertex2(glm::vec3(x2, y2, -1), glm::vec3(0, x2, x2))   // 19
	};
	unsigned int indices[] = {0, 2, 1, 0, 3, 2};
	return new Mesh2(vertices, sizeof(vertices) / sizeof(vertices[0]), indices, sizeof(indices) / sizeof(indices[0]));
}