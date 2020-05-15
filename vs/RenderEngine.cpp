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
#include "Object\RumputTengah.h"
#include "Object\RumputBawah.h"
#include "Object\RumputAtas.h"
#include "Object\RumputKanan.h"
#include "Object\RumputKiri.h"
#include "Object\BisBody.h"



#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>

Mesh* bisBody;
Shader* bisBodyShader;
Texture* bisBodyTexture;
Transform* bisBodyTransform;

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

Mesh* towerMonasAtas;
Shader* towerMonasAtasShader;
Texture* towerMonasAtasTexture;
Transform* towerMonasAtasTransform;

Mesh* towerMonasTempatPucuk;
Shader* towerMonasTempatPucukShader;
Texture* towerMonasTempatPucukTexture;
Transform* towerMonasTempatPucukTransform;


Mesh* towerMonasKotakPucuk;
Shader* towerMonasKotakPucukShader;
Texture* towerMonasKotakPucukTexture;
Transform* towerMonasKotakPucukTransform;

Mesh* towerMonasPucuk;
Shader* towerMonasPucukShader;
Texture* towerMonasPucukTexture;
Transform* towerMonasPucukTransform;

Mesh* plane;
Shader* planeShader;
Texture* planeTexture;
Transform* planeTransform;

Mesh* rumputTengah;
Shader* rumputTengahShader;
Texture* rumputTengahTexture;
Transform* rumputTengahTransform;

Mesh* rumputBawah;
Shader* rumputBawahShader;
Texture* rumputBawahTexture;
Transform* rumputBawahTransform;

Mesh* rumputAtas;
Shader* rumputAtasShader;
Texture* rumputAtasTexture;
Transform* rumputAtasTransform;

Mesh* rumputKanan;
Shader* rumputKananShader;
Texture* rumputKananTexture;
Transform* rumputKananTransform;

Mesh* rumputKiri;
Shader* rumputKiriShader;
Texture* rumputKiriTexture;
Transform* rumputKiriTransform;

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

	lantaiTingkatDuaShader = new Shader("res/Triangle");
	lantaiTingkatDuaTexture = new Texture("res/marble.png", GL_LINEAR_MIPMAP_NEAREST);
	lantaiTingkatDuaTransform = new Transform();
	lantaiTingkatDua = LantaiTingkatDua();

	lantaiTingkatTigaShader = new Shader("res/Triangle");
	lantaiTingkatTigaTexture = new Texture("res/marble.png", GL_LINEAR_MIPMAP_NEAREST);
	lantaiTingkatTigaTransform = new Transform();
	lantaiTingkatTiga = LantaiTingkatTiga();

	tempatTowerBawahShader = new Shader("res/Triangle");
	tempatTowerBawahTexture = new Texture("res/marble.png", GL_LINEAR_MIPMAP_NEAREST);
	tempatTowerBawahTransform = new Transform();
	tempatTowerBawah = TempatTowerBawah();

	tempatTowerTengahShader = new Shader("res/Triangle");
	tempatTowerTengahTexture = new Texture("res/marble.png", GL_LINEAR_MIPMAP_NEAREST);
	tempatTowerTengahTransform = new Transform();
	tempatTowerTengah = TempatTowerTengah();

	tempatTowerAtasShader = new Shader("res/Triangle");
	tempatTowerAtasTexture = new Texture("res/marble.png", GL_LINEAR_MIPMAP_NEAREST);
	tempatTowerAtasTransform = new Transform();
	tempatTowerAtas = TempatTowerAtas();

	towerMonasTengahShader = new Shader("res/Triangle");
	towerMonasTengahTexture = new Texture("res/marble.png", GL_LINEAR_MIPMAP_NEAREST);
	towerMonasTengahTransform = new Transform();
	towerMonasTengah = TowerMonasTengah();

	towerMonasAtasShader = new Shader("res/Triangle");
	towerMonasAtasTexture = new Texture("res/marble.png", GL_LINEAR_MIPMAP_NEAREST);
	towerMonasAtasTransform = new Transform();
	towerMonasAtas = TowerMonasAtas();

	towerMonasTempatPucukShader = new Shader("res/Triangle");
	towerMonasTempatPucukTexture = new Texture("res/marble.png", GL_LINEAR_MIPMAP_NEAREST);
	towerMonasTempatPucukTransform = new Transform();
	towerMonasTempatPucuk = TowerMonasTempatPucuk();

	towerMonasKotakPucukShader = new Shader("res/Triangle");
	towerMonasKotakPucukTexture = new Texture("res/marble.png", GL_LINEAR_MIPMAP_NEAREST);
	towerMonasKotakPucukTransform = new Transform();
	towerMonasKotakPucuk = TowerMonasKotakPucuk();

	rumputTengahShader = new Shader("res/Triangle");
	rumputTengahTexture = new Texture("res/marble.png", GL_LINEAR_MIPMAP_NEAREST);
	rumputTengahTransform = new Transform();
	rumputTengah = RumputTengah();

	rumputBawahShader = new Shader("res/Triangle");
	rumputBawahTexture = new Texture("res/marble.png", GL_LINEAR_MIPMAP_NEAREST);
	rumputBawahTransform = new Transform();
	rumputBawah = RumputBawah();

	rumputAtasShader = new Shader("res/Triangle");
	rumputAtasTexture = new Texture("res/marble.png", GL_LINEAR_MIPMAP_NEAREST);
	rumputAtasTransform = new Transform();
	rumputAtas = RumputAtas();

	rumputKananShader = new Shader("res/Triangle");
	rumputKananTexture = new Texture("res/marble.png", GL_LINEAR_MIPMAP_NEAREST);
	rumputKananTransform = new Transform();
	rumputKanan = RumputKanan();

	rumputKiriShader = new Shader("res/Triangle");
	rumputKiriTexture = new Texture("res/marble.png", GL_LINEAR_MIPMAP_NEAREST);
	rumputKiriTransform = new Transform();
	rumputKiri = RumputKiri();

	bisBodyShader = new Shader("res/Triangle");
	bisBodyTexture = new Texture("res/marble.png", GL_LINEAR_MIPMAP_NEAREST);
	bisBodyTransform = new Transform();
	bisBody = BisBody();
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

	lantaiTingkatDuaTexture->Bind();
	lantaiTingkatDuaShader->Bind();
	lantaiTingkatDuaShader->Update(*lantaiTingkatDuaTransform, *camera, glm::vec3(light->x, light->y, light->z), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));

	lantaiTingkatDua->Draw();

	lantaiTingkatTigaTexture->Bind();
	lantaiTingkatTigaShader->Bind();
	lantaiTingkatTigaShader->Update(*lantaiTingkatTigaTransform, *camera, glm::vec3(light->x, light->y, light->z), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));

	lantaiTingkatTiga->Draw();

	tempatTowerBawahTexture->Bind();
	tempatTowerBawahShader->Bind();
	tempatTowerBawahShader->Update(*tempatTowerBawahTransform, *camera, glm::vec3(light->x, light->y, light->z), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));

	tempatTowerBawah->Draw();

	tempatTowerTengahTexture->Bind();
	tempatTowerTengahShader->Bind();
	tempatTowerTengahShader->Update(*tempatTowerTengahTransform, *camera, glm::vec3(light->x, light->y, light->z), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));

	tempatTowerTengah->Draw();

	tempatTowerAtasTexture->Bind();
	tempatTowerAtasShader->Bind();
	tempatTowerAtasShader->Update(*tempatTowerAtasTransform, *camera, glm::vec3(light->x, light->y, light->z), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));

	tempatTowerAtas->Draw();

	towerMonasTengahTexture->Bind();
	towerMonasTengahShader->Bind();
	towerMonasTengahShader->Update(*towerMonasTengahTransform, *camera, glm::vec3(light->x, light->y, light->z), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));

	towerMonasTengah->Draw();

	towerMonasAtasTexture->Bind();
	towerMonasAtasShader->Bind();
	towerMonasAtasShader->Update(*towerMonasAtasTransform, *camera, glm::vec3(light->x, light->y, light->z), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));

	towerMonasAtas->Draw();

	towerMonasTempatPucukTexture->Bind();
	towerMonasTempatPucukShader->Bind();
	towerMonasTempatPucukShader->Update(*towerMonasTempatPucukTransform, *camera, glm::vec3(light->x, light->y, light->z), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));

	towerMonasTempatPucuk->Draw();

	towerMonasKotakPucukTexture->Bind();
	towerMonasKotakPucukShader->Bind();
	towerMonasKotakPucukShader->Update(*towerMonasKotakPucukTransform, *camera, glm::vec3(light->x, light->y, light->z), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));

	towerMonasKotakPucuk->Draw();

	rumputTengahTexture->Bind();
	rumputTengahShader->Bind();
	rumputTengahShader->Update(*rumputTengahTransform, *camera, glm::vec3(light->x, light->y, light->z), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));

	rumputTengah->Draw();

	rumputBawahTexture->Bind();
	rumputBawahShader->Bind();
	rumputBawahShader->Update(*rumputBawahTransform, *camera, glm::vec3(light->x, light->y, light->z), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));

	rumputBawah->Draw();

	rumputAtasTexture->Bind();
	rumputAtasShader->Bind();
	rumputAtasShader->Update(*rumputAtasTransform, *camera, glm::vec3(light->x, light->y, light->z), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));

	rumputAtas->Draw();

	rumputKananTexture->Bind();
	rumputKananShader->Bind();
	rumputKananShader->Update(*rumputKananTransform, *camera, glm::vec3(light->x, light->y, light->z), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));

	rumputKanan->Draw();

	rumputKiriTexture->Bind();
	rumputKiriShader->Bind();
	rumputKiriShader->Update(*rumputKiriTransform, *camera, glm::vec3(light->x, light->y, light->z), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));

	rumputKiri->Draw();

	bisBodyTexture->Bind();
	bisBodyShader->Bind();
	bisBodyShader->Update(*bisBodyTransform, *camera, glm::vec3(light->x, light->y, light->z), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));

	bisBody->Draw();
}
