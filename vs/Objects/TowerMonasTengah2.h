#pragma once
#include "../Headers/Mesh2.h"
#include <iostream>

static Mesh2* TowerMonasTengah2()
{
	const GLfloat x1 = 1;
	const GLfloat x2 = 0.5;

	const GLfloat y1 = 3.1;
	const GLfloat y2 = 20.1;

	const GLfloat z1 = 1;
	const GLfloat z2 = 0.5;

	int multiplier = 4;
	Vertex2 vertices[] = {
		
		// front
		
		Vertex2(glm::vec3(x2, y2, z2), glm::vec3(0 , 0  , x2 / multiplier)),   // 0
		Vertex2(glm::vec3(-x2, y2, z2), glm::vec3(x2 , 0, x2 / multiplier)),  // 1
		Vertex2(glm::vec3(-x1, y1, z1), glm::vec3(x1 , x1, x1 / multiplier)),  // 2
		Vertex2(glm::vec3(x1, y1, z1), glm::vec3(0 , x1, x1 / multiplier)),   // 3

		// right
		Vertex2(glm::vec3(x2,  y2,  z2), glm::vec3(0 , 0, z2 / multiplier)),  // 4
		Vertex2(glm::vec3(x2,  y2, -z2), glm::vec3(z2 , 0, z2 / multiplier)),  // 5
		Vertex2(glm::vec3(x1, y1, -z1), glm::vec3(z1 , z1, z1 / multiplier)),  // 6
		Vertex2(glm::vec3(x1, y1,  z1), glm::vec3(0 , z1, z1 / multiplier)),  // 7


		// back
		Vertex2(glm::vec3(x2,   y2, -z2), glm::vec3(0 , 0  , x2 / multiplier)), // 10
		Vertex2(glm::vec3(-x2,  y2, -z2), glm::vec3(x2 , 0, x2 / multiplier)), // 11
		Vertex2(glm::vec3(-x1, y1, -z1), glm::vec3(x1 , x1, x1 / multiplier)), // 8 
		Vertex2(glm::vec3(x1,  y1, -z1), glm::vec3(0 , x1, x1 / multiplier)), // 9


		// left
		Vertex2(glm::vec3(-x2,  y2,  z2), glm::vec3(0 , 0  , x2 / multiplier)), // 14
		Vertex2(glm::vec3(-x2,  y2, -z2), glm::vec3(x2 , 0, x2 / multiplier)), // 15
		Vertex2(glm::vec3(-x1, y1, -z1), glm::vec3(x1 , x1, x1 / multiplier)), // 12
		Vertex2(glm::vec3(-x1, y1,  z1), glm::vec3(0 , x1, x1 / multiplier)), // 13


		// upper
		Vertex2(glm::vec3(x2, y2,  z2), glm::vec3(0 , 0, x2 / multiplier)),   // 16
		Vertex2(glm::vec3(-x2, y2,  z2), glm::vec3(x2 , 0, x2 / multiplier)),  // 17
		Vertex2(glm::vec3(-x2, y2, -z2), glm::vec3(x2 , x2, x2 / multiplier)),  // 18
		Vertex2(glm::vec3(x2, y2, -z2), glm::vec3(0 , x2, x2 / multiplier)),   // 19

		// bottom
		Vertex2(glm::vec3(x1, y1,  z1), glm::vec3(0 , 0, x2 / multiplier)),   // 16
		Vertex2(glm::vec3(-x1, y1,  z1), glm::vec3(x2 , 0, x2 / multiplier)),  // 17
		Vertex2(glm::vec3(-x1, y1, -z1), glm::vec3(x2 , x2, x2 / multiplier)),  // 18
		Vertex2(glm::vec3(x1, y1, -z1), glm::vec3(0 , x2, x2 / multiplier)),   // 19

		
	};

	unsigned int indices[] = {

		0,  1, 2,
		0,  2,  3,   // front

		4,  6,  5,
		4,  7,  6,   // right
		
		8,  10,  9,
		8,  11, 10,  // back

		20, 22, 21,
		20, 23, 22,   // bottom


		12, 14, 13,
		12, 15, 14,  // left

		16, 18, 17,
		16, 19, 18  // upper

		

		//0,1,2,
		//3,4,5
	};

	return new Mesh2(vertices, sizeof(vertices) / sizeof(vertices[0]), indices, sizeof(indices) / sizeof(indices[0]));
}