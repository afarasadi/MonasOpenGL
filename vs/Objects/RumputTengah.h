#pragma once
#include "../Headers/Mesh.h"

static Mesh* RumputTengah()
{
	int multiplier = 8;
	Vertex vertices[] = {


		// upper
				Vertex(glm::vec3(10.2, 0.05,  10.2), glm::vec2(0, 0)),   // 16
				Vertex(glm::vec3(-10.2, 0.05,  10.2), glm::vec2(1 * multiplier, 0)),  // 17
				Vertex(glm::vec3(-10.2, 0.05, -10.2), glm::vec2(1 * multiplier, 1 * multiplier)),  // 18
				Vertex(glm::vec3(10.2, 0.05, -10.2), glm::vec2(0, 1 * multiplier)),   // 19


	};

	unsigned int indices[] = {
		0, 2, 1, 0, 3, 2,   // bottom


	};

	return new Mesh(vertices, sizeof(vertices) / sizeof(vertices[0]), indices, sizeof(indices) / sizeof(indices[0]));
}