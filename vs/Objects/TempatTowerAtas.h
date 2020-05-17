#pragma once
#include "../Headers/Mesh.h"
#include <iostream>

static Mesh* TempatTowerAtas()
{
	
	int multiplier = 4;

	Vertex vertices[] = {
		// format position, tex coords
		// front
				Vertex(glm::vec3(-3, 3, 3), glm::vec2(0, 0)),  // 0
				Vertex(glm::vec3(3, 3, 3), glm::vec2(1 * multiplier, 0)),   // 1
				Vertex(glm::vec3(3,  3.1, 3), glm::vec2(1 * multiplier, 1 * multiplier)),   // 2
				Vertex(glm::vec3(-3,  3.1, 3), glm::vec2(0, 1 * multiplier)),  // 3

		// right
				Vertex(glm::vec3(3,  3.1,  3), glm::vec2(0, 0)),  // 4
				Vertex(glm::vec3(3,  3.1, -3), glm::vec2(1 * multiplier, 0)),  // 5
				Vertex(glm::vec3(3, 3, -3), glm::vec2(1 * multiplier, 1 * multiplier)),  // 6
				Vertex(glm::vec3(3, 3,  3), glm::vec2(0, 1 * multiplier)),  // 7


		// back
				Vertex(glm::vec3(-3, 3, -3), glm::vec2(0, 0)), // 8 
				Vertex(glm::vec3(3,  3, -3), glm::vec2(1 * multiplier, 0)), // 9
				Vertex(glm::vec3(3,   3.1, -3), glm::vec2(1 * multiplier, 1 * multiplier)), // 10
				Vertex(glm::vec3(-3,  3.1, -3), glm::vec2(0, 1 * multiplier)), // 11

		// left
				Vertex(glm::vec3(-3, 3, -3), glm::vec2(0, 0)), // 12
				Vertex(glm::vec3(-3, 3,  3), glm::vec2(1 * multiplier, 0)), // 13
				Vertex(glm::vec3(-3,  3.1,  3), glm::vec2(1 * multiplier, 1 * multiplier)), // 14
				Vertex(glm::vec3(-3,  3.1, -3), glm::vec2(0, 1 * multiplier)), // 15

		// upper
				Vertex(glm::vec3(3, 3.1,  3), glm::vec2(0, 0)),   // 16
				Vertex(glm::vec3(-3, 3.1,  3), glm::vec2(1 * multiplier, 0)),  // 17
				Vertex(glm::vec3(-3, 3.1, -3), glm::vec2(1 * multiplier, 1 * multiplier)),  // 18
				Vertex(glm::vec3(3, 3.1, -3), glm::vec2(0, 1 * multiplier)),   // 19

		// bottom
				Vertex(glm::vec3(-0.5, -0.5, -0.5), glm::vec2(0, 0)), // 20
				Vertex(glm::vec3(0.5, -0.5, -0.5), glm::vec2(1 * multiplier, 0)),  // 21
				Vertex(glm::vec3(0.5, -0.5,  0.5), glm::vec2(1 * multiplier, 1 * multiplier)),  // 22
				Vertex(glm::vec3(-0.5, -0.5,  0.5), glm::vec2(0, 1 * multiplier)) // 23

	};

	unsigned int indices[] = {
		8,  9,  10, 8,  10, 11,  // back
		20, 22, 21, 20, 23, 22,   // bottom
		4,  6,  5,  4,  7,  6,   // right
		12, 14, 13, 12, 15, 14,  // left
		16, 18, 17, 16, 19, 18,  // upper
		0,  1,  2,  0,  2,  3   // front

	};

	return new Mesh(vertices, sizeof(vertices) / sizeof(vertices[0]), indices, sizeof(indices) / sizeof(indices[0]));
}