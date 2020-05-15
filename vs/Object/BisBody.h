#pragma once
#include "../Mesh.h"

static Mesh* BisBody()
{
	Vertex vertices[] = {
		// format position, tex coords
		// front
				Vertex(glm::vec3(-0.511, 0.3, -11.92), glm::vec2(0, 0)),  // 0
				Vertex(glm::vec3(0.511, 0.3, -11.92), glm::vec2(1, 0)),   // 1
				Vertex(glm::vec3(0.511,  1.10, -12.22), glm::vec2(1, 1)),   // 2
				Vertex(glm::vec3(-0.511,  1.10, -12.22), glm::vec2(0, 1)),  // 3

		// right
				Vertex(glm::vec3(0.511,  1.10,  -12.22), glm::vec2(0, 0)),  // 4
				Vertex(glm::vec3(0.511,  1.10, -15.11), glm::vec2(1, 0)),  // 5
				Vertex(glm::vec3(0.511, 0.3, -15.11), glm::vec2(1, 1)),  // 6
				Vertex(glm::vec3(0.511, 0.3,  -11.92), glm::vec2(0, 1)),  // 7


		// back
				Vertex(glm::vec3(-0.511, 0.11, -15.11), glm::vec2(0, 0)), // 8 
				Vertex(glm::vec3(0.511,  0.11, -15.11), glm::vec2(1, 0)), // 9
				Vertex(glm::vec3(0.511,   1.10, -15.11), glm::vec2(1, 1)), // 10
				Vertex(glm::vec3(-0.511,  1.10, -15.11), glm::vec2(0, 1)), // 11

		// left
				Vertex(glm::vec3(-0.511, 0.3, -15.11), glm::vec2(0, 0)), // 12
				Vertex(glm::vec3(-0.511, 0.3,  -11.92), glm::vec2(1, 0)), // 13
				Vertex(glm::vec3(-0.511,  1.10,  -12.22), glm::vec2(1, 1)), // 14
				Vertex(glm::vec3(-0.511,  1.10, -15.11), glm::vec2(0, 1)), // 15

		// upper
				Vertex(glm::vec3(0.511, 1.10,  -12.22), glm::vec2(0, 0)),   // 16
				Vertex(glm::vec3(-0.511, 1.10,  -12.22), glm::vec2(1, 0)),  // 17
				Vertex(glm::vec3(-0.511, 1.10, -15.11), glm::vec2(1, 1)),  // 18
				Vertex(glm::vec3(0.511, 1.10, -15.11), glm::vec2(0, 1)),   // 19

		// bottom
				Vertex(glm::vec3(-0.511, 0.11, -11.92), glm::vec2(0, 0)),  // 20
				Vertex(glm::vec3(0.511, 0.11, -11.92), glm::vec2(1, 0)),   // 21
				Vertex(glm::vec3(0.511,  0.3, -11.92), glm::vec2(1, 1)),   // 22
				Vertex(glm::vec3(-0.511,  0.3, -11.92), glm::vec2(0, 1)),  // 23

				// Bagasi Right
				Vertex(glm::vec3(0.511,  0.3,  -11.92), glm::vec2(0, 0)),  // 24
				Vertex(glm::vec3(0.511,  0.3, -15.11), glm::vec2(1, 0)),  // 25
				Vertex(glm::vec3(0.511, 0.11, -15.11), glm::vec2(1, 1)),  // 26
				Vertex(glm::vec3(0.511, 0.11,  -11.92), glm::vec2(0, 1)),  // 27

				// Bagasi Left
				Vertex(glm::vec3(-0.511,  0.3,  -11.92), glm::vec2(0, 0)),  // 28
				Vertex(glm::vec3(-0.511,  0.3, -15.11), glm::vec2(1, 0)),  // 29
				Vertex(glm::vec3(-0.511, 0.11, -15.11), glm::vec2(1, 1)),  // 30
				Vertex(glm::vec3(-0.511, 0.11,  -11.92), glm::vec2(0, 1)),  // 31

				// Roda Left 1
				Vertex(glm::vec3(-0.521,  0.45,  -12.72), glm::vec2(0, 0)),  // 32
				Vertex(glm::vec3(-0.521,  0.45, -12.32), glm::vec2(1, 0)),  // 33
				Vertex(glm::vec3(-0.521, 0.05, -12.32), glm::vec2(1, 1)),  // 34
				Vertex(glm::vec3(-0.521, 0.05,  -12.72), glm::vec2(0, 1)),  // 35

				// Roda Left 2
				Vertex(glm::vec3(-0.521,  0.45,  -14.52), glm::vec2(0, 0)),  // 36
				Vertex(glm::vec3(-0.521,  0.45, -14.12), glm::vec2(1, 0)),  // 37
				Vertex(glm::vec3(-0.521, 0.05, -14.12), glm::vec2(1, 1)),  // 38
				Vertex(glm::vec3(-0.521, 0.05,  -14.52), glm::vec2(0, 1)),  // 39

				// Roda Right 1
				Vertex(glm::vec3(0.521,  0.45,  -12.72), glm::vec2(0, 0)),  // 40
				Vertex(glm::vec3(0.521,  0.45, -12.32), glm::vec2(1, 0)),  // 41
				Vertex(glm::vec3(0.521, 0.05, -12.32), glm::vec2(1, 1)),  // 42
				Vertex(glm::vec3(0.521, 0.05,  -12.72), glm::vec2(0, 1)),  // 43

				// Roda Right 2
				Vertex(glm::vec3(0.521,  0.45,  -14.52), glm::vec2(0, 0)),  // 44
				Vertex(glm::vec3(0.521,  0.45, -14.12), glm::vec2(1, 0)),  // 45
				Vertex(glm::vec3(0.521, 0.05, -14.12), glm::vec2(1, 1)),  // 46
				Vertex(glm::vec3(0.521, 0.05,  -14.52), glm::vec2(0, 1)),  // 47

	};

	unsigned int indices[] = {
		8,  9,  10, 8,  10, 11,  // back
		20, 21, 22, 20, 22, 23,   // bottom
		4,  5,  6,  4,  6,  7,   // right
		12, 14, 13, 12, 15, 14,  // left
		16, 18, 17, 16, 19, 18,  // upper
		0,  1,  2,  0,  2,  3,   // front
		24, 25, 26, 24, 26, 27,   // bagsi l
		28, 29, 30, 28, 30, 31,   // bagasi r
		32,33, 34, 32, 34, 35,   // Roda Left 1
		36,37, 38, 36, 38, 39,   // Roda Left 2
		40,41, 42, 40, 42, 43,   // Roda R 1
		44,45, 46, 44, 46, 47   // Roda R 2

	};

	return new Mesh(vertices, sizeof(vertices) / sizeof(vertices[0]), indices, sizeof(indices) / sizeof(indices[0]));
}