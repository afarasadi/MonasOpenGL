#pragma once
#include "../Headers/Mesh2.h"

static Mesh2* RumputKanan()
{
	const GLfloat x1 = 15.2;
	const GLfloat x2 = 30.2;
	const int multiplier = 8;

	Vertex2 vertices[] = {
		// format position, tex coords

		// upper
				Vertex2(glm::vec3(15.2, 0.05,  15.2), glm::vec3(0, 0, x1 / multiplier)),   // 16
				Vertex2(glm::vec3(15.2, 0.05, -15.2), glm::vec3(x1, 0, x1 / multiplier)),   // 19
				Vertex2(glm::vec3(30.2, 0.05, -30.2), glm::vec3(x2, x2, x2 / multiplier)),  // 18
				Vertex2(glm::vec3(30.2, 0.05,  30.2), glm::vec3(0, x2, x2 / multiplier)),  // 17


	};

	unsigned int indices[] = {

		//16, 18, 17, 16, 19, 18,  // upper
		0,  2,  1,
		0,  3,  2,
	};

	return new Mesh2(vertices, sizeof(vertices) / sizeof(vertices[0]), indices, sizeof(indices) / sizeof(indices[0]));
}