#pragma once
#include "Engine.h"
#include "Shader.h"
#include "Texture.h"
#include "Transform.h"
#include "Camera.h"
#include "Object\LantaiTingkatSatu.h"
#include "Object\LantaiTingkatDua.h"
#include "Object\LantaiTingkatTiga.h"
#include "Object\TempatTowerBawah.h"
#include "Object\TempatTowerTengah.h"
#include "Object\TempatTowerAtas.h"
#include "Object\TowerMonasTengah.h"
#include "Object\TowerMonasAtas.h"
#include "Object\TowerMonasTempatPucuk.h"
#include "Object\TowerMonasKotakPucuk.h"
#include "Object\TowerMonasPucuk.h"
#include "Object\Plane.h"


#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>


Mesh* lantaiTingkatSatu;
Shader* lantaiTingkatSatuShader;
Texture* lantaiTingkatSatuTexture;
Transform* lantaiTingkatSatuTransform;

Mesh* lantaiTingkatDua;
Shader* lantaiTingkatDuaShader;
Texture* lantaiTingkatDuaTexture;
Transform* lantaiTingkatDuaTransform;

Mesh* lantaiTingkatTiga;
Shader* lantaiTingkatTigaShader;
Texture* lantaiTingkatTigaTexture;
Transform* lantaiTingkatTigaTransform;

Mesh* tempatTowerBawah;
Shader* tempatTowerBawahShader;
Texture* tempatTowerBawahTexture;
Transform* tempatTowerBawahTransform;

Mesh* tempatTowerTengah;
Shader* tempatTowerTengahShader;
Texture* tempatTowerTengahTexture;
Transform* tempatTowerTengahTransform;


Mesh* tempatTowerAtas;
Shader* tempatTowerAtasShader;
Texture* tempatTowerAtasTexture;
Transform* tempatTowerAtasTransform;

Mesh* towerMonasTengah;
Shader* towerMonasTengahShader;
Texture* towerMonasTengahTexture;
Transform* towerMonasTengahTransform;


Mesh* towerMonasKotakPucuk;
Shader* towerMonasKotakPucukShader;
Texture* towerMonasKotakPucukTexture;
Transform* towerMonasKotakPucukTextureTransform;

Mesh* towerMonasPucuk;
Shader* towerMonasPucukShader;
Texture* towerMonasPucukTexture;
Transform* towerMonasPucukTransform;

Mesh* plane;
Shader* planeShader;
Texture* planeTexture;
Transform* planeTransform;


Camera* camera;

Light* light;

float posCamX = 0;
float posCamY = 2;
float posCamZ = 5;

float viewCamX = 0.0f, viewCamY = 0.0f, viewCamZ = 1.0f;
float speed = 0.02f;

RenderEngine::RenderEngine(int width, int height, const char* title, bool vsync, bool fullscreen) {
	Start(width, height, title, vsync, fullscreen);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ENTER && action == GLFW_PRESS) {
	}
}

void RenderEngine::Init() {
	glViewport(0, 0, this->screenWidth, this->screenHeight);
	glfwSetInputMode(this->window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetKeyCallback(window, key_callback);

	camera = new Camera(glm::vec3(posCamX, 0, posCamZ), 70.0f, (GLfloat)this->screenWidth / (GLfloat)this->screenHeight, 0.1f, 100.0f);


	light = new Light();
	light->x = 0.5f;
	light->y = -0.6f;
	light->z = -0.2f;

	planeShader = new Shader("res/Triangle");
	planeTexture = new Texture("res/lego_mix.png", GL_LINEAR_MIPMAP_NEAREST);
	planeTransform = new Transform();
	plane = Plane();

	/*
	TODO()
	Tempat init objek => shader& texture
	*/
	lantaiTingkatSatuShader = new Shader("res/Triangle");
	lantaiTingkatSatuTexture = new Texture("res/marble.png", GL_LINEAR_MIPMAP_NEAREST);
	lantaiTingkatSatuTransform = new Transform();
	lantaiTingkatSatu = LantaiTingkatSatu();



	
}

void RenderEngine::DeInit() {
	camera->~Camera();
	planeShader->~Shader();
	plane->~Mesh();
}

void MoveCameraY(float speed)
{
	speed *= 2;
	float y = std::abs(viewCamY - posCamY);
	// forward positive cameraspeed and backward negative -cameraspeed.
	posCamY = posCamY + speed;
	viewCamY = viewCamY + speed;
}

void MoveCameraXZ(float speed)
{
	float x = viewCamX - posCamX;
	float z = viewCamZ - posCamZ;
	// forward positive cameraspeed and backward negative -cameraspeed.
	posCamX = posCamX + x * speed;
	posCamZ = posCamZ + z * speed;
	viewCamX = viewCamX + x * speed;
	viewCamZ = viewCamZ + z * speed;
}

void StrafeCamera(float speed)
{
	float x = viewCamX - posCamX;
	float z = viewCamZ - posCamZ;
	float orthoX = -z;
	float orthoZ = x;

	// left positive cameraspeed and right negative -cameraspeed.
	posCamX = posCamX + orthoX * speed;
	posCamZ = posCamZ + orthoZ * speed;
	viewCamX = viewCamX + orthoX * speed;
	viewCamZ = viewCamZ + orthoZ * speed;
}

void RotateCamera(float speed)
{
	float x = viewCamX - posCamX;
	float z = viewCamZ - posCamZ;
	viewCamZ = (float)(posCamZ + glm::sin(speed) * x + glm::cos(speed) * z);
	viewCamX = (float)(posCamX + glm::cos(speed) * x - glm::sin(speed) * z);
}

void RenderEngine::ProcessInput(GLFWwindow* window) {

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
		MoveCameraY(speed);
	}

	if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS) {
		MoveCameraY(-speed);
	}

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		MoveCameraXZ(speed);
	}

	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		MoveCameraXZ(-speed);
	}

	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		StrafeCamera(-speed);
	}

	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		StrafeCamera(speed);
	}

	double mouseX, mouseY;
	double midX = screenWidth / 2;
	double midY = screenHeight / 2;
	float angleY = 0.0f;
	float angleZ = 0.0f;

	glfwGetCursorPos(window, &mouseX, &mouseY);
	if ((mouseX != midX) && (mouseY != midY)) {
		// Set mouse position
		glfwSetCursorPos(window, midX, midY);

		// Get the direction from the mouse cursor, set a resonable maneuvering speed
		angleY = (float)((midX - mouseX)) / 1000;
		angleZ = (float)((midY - mouseY)) / 1000;

		// The higher the value is the faster the camera looks around.
		viewCamY += angleZ * 2;

		// limit the rotation around the y-axis
		if ((viewCamY - posCamY) > 8) {
			viewCamY = posCamY + 8;
		}
		if ((viewCamY - posCamY) < -8) {
			viewCamY = posCamY - 8;
		}

		float x = viewCamX - posCamX;
		float z = viewCamZ - posCamZ;
		viewCamZ = (float)(posCamZ + glm::sin(-angleY) * x + glm::cos(-angleY) * z);
		viewCamX = (float)(posCamX + glm::cos(-angleY) * x - glm::sin(-angleY) * z);
	}
}

void RenderEngine::Update(double deltaTime) {




}

void RenderEngine::Render() {
	Clear(0.35f, 0.87f, 0.92f, 0.0f);

	camera->position.x = posCamX;
	camera->position.y = posCamY;
	camera->position.z = posCamZ;

	camera->forward.x = viewCamX;
	camera->forward.y = viewCamY;
	camera->forward.z = viewCamZ;

	/*
		TODO()
		panggil di tiap objek
	*/
	planeTexture->Bind();
	planeShader->Bind();
	planeShader->Update(*planeTransform, *camera, glm::vec3(light->x, light->y, light->z));
	plane->Draw();


	lantaiTingkatSatuTexture->Bind();
	lantaiTingkatSatuShader->Bind();
	lantaiTingkatSatuShader->Update(*lantaiTingkatSatuTransform, *camera, glm::vec3(light->x, light->y, light->z), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));

	lantaiTingkatSatu->Draw();

}
