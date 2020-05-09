#pragma once
#include "Mesh.h"
#include <iostream>

static Mesh* LantaiTingkatDua()
{
	Vertex vertices[] = {
		// format position, tex coords
		// front
				Vertex(glm::vec3(-0.5, -0.5, 0.5), glm::vec2(0, 0)),  // 0
				Vertex(glm::vec3(0.5, -0.5, 0.5), glm::vec2(1, 0)),   // 1
				Vertex(glm::vec3(0.5,  0.5, 0.5), glm::vec2(1, 1)),   // 2
				Vertex(glm::vec3 (-0.5,  0.5, 0.5), glm::vec2(0, 1)),  // 3

		// right
				Vertex(glm::vec3(0.5,  0.5,  0.5), glm::vec2(0, 0)),  // 4
				Vertex(glm::vec3(0.5,  0.5, -0.5), glm::vec2(1, 0)),  // 5
				Vertex(glm::vec3(0.5, -0.5, -0.5), glm::vec2(1, 1)),  // 6
				Vertex(glm::vec3(0.5, -0.5,  0.5), glm::vec2(0, 1)),  // 7


		// back
				Vertex(glm::vec3(-0.5, -0.5, -0.5), glm::vec2(0, 0)), // 8 
				Vertex(glm::vec3(0.5,  -0.5, -0.5), glm::vec2(1, 0)), // 9
				Vertex(glm::vec3(0.5,   0.5, -0.5), glm::vec2(1, 1)), // 10
				Vertex(glm::vec3(-0.5,  0.5, -0.5), glm::vec2(0, 1)), // 11

		// left
				Vertex(glm::vec3(-0.5, -0.5, -0.5), glm::vec2(0, 0)), // 12
				Vertex(glm::vec3(-0.5, -0.5,  0.5), glm::vec2(1, 0)), // 13
				Vertex(glm::vec3(-0.5,  0.5,  0.5), glm::vec2(1, 1)), // 14
				Vertex(glm::vec3(-0.5,  0.5, -0.5), glm::vec2(0, 1)), // 15

		// upper
				Vertex(glm::vec3(0.5, 0.5,  0.5), glm::vec2(0, 0)),   // 16
				Vertex(glm::vec3(-0.5, 0.5,  0.5), glm::vec2(1, 0)),  // 17
				Vertex(glm::vec3(-0.5, 0.5, -0.5), glm::vec2(1, 1)),  // 18
				Vertex(glm::vec3(0.5, 0.5, -0.5), glm::vec2(0, 0)),   // 19

		// bottom
				Vertex(glm::vec3(-0.5, -0.5, -0.5), glm::vec2(0, 0)), // 20
				Vertex(glm::vec3(0.5, -0.5, -0.5), glm::vec2(1, 0)),  // 21
				Vertex(glm::vec3(0.5, -0.5,  0.5), glm::vec2(1, 1)),  // 22
				Vertex(glm::vec3(-0.5, -0.5,  0.5), glm::vec2(0, 1)) // 23

	};

	unsigned int indices[] = {
		8,  9,  10, // segitiga pertama
		8,  10, 11, //segitiga kedua
					// back

		20, 22, 21,
		20, 23, 22,   // bottom

		4,  5,  6,  
		4,  6,  7,   // right

		12, 14, 13, 
		12, 15, 14,  // left

		16, 18, 17, 
		16, 19, 18,  // upper

		0,  1,  2,  
		0,  2,  3   // front


	};

	return new Mesh(vertices, sizeof(vertices) / sizeof(vertices[0]), indices, sizeof(indices) / sizeof(indices[0]));
}