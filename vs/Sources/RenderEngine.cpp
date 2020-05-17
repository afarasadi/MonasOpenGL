#pragma once
#include "../Headers/Engine.h"
#include "../Headers/Shader.h"
#include "../Headers/Texture.h"
#include "../Headers/Transform.h"
#include "../Headers/Camera.h"
#include "../Objects/LantaiTingkatSatu.h"
#include "../Objects/LantaiTingkatDua.h"
#include "../Objects/LantaiTingkatTiga.h"
#include "../Objects/TempatTowerBawah.h"
#include "../Objects/TempatTowerBawah2.h"
#include "../Objects/TempatTowerTengah.h"
#include "../Objects/TempatTowerAtas.h"
#include "../Objects/TowerMonasTengah.h"
#include "../Objects/TowerMonasAtas.h"
#include "../Objects/TowerMonasAtas2.h"
#include "../Objects/TowerMonasTempatPucuk.h"
#include "../Objects/TowerMonasTempatPucuk2.h"
#include "../Objects/TowerMonasKotakPucuk.h"
#include "../Objects/TowerMonasKotakPucuk2.h"
#include "../Objects/TowerMonasPucuk.h"
#include "../Objects/Plane.h"
#include "../Objects/RumputTengah.h"
#include "../Objects/RumputBawah.h"
#include "../Objects/RumputAtas.h"
#include "../Objects/RumputKanan.h"
#include "../Objects/RumputKiri.h"
#include "../Objects/BisBody.h"
#include "../Objects/Pucuk.h"

#include "../Headers/Mesh2.h"
#include "../Objects/TowerMonasTengah2.h"
#include "../Objects/TempatTowerTengah2.h"

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

Mesh2* lantaiTingkatDua;
Shader* lantaiTingkatDuaShader;
Texture* lantaiTingkatDuaTexture;
Transform* lantaiTingkatDuaTransform;

Mesh* lantaiTingkatTiga;
Shader* lantaiTingkatTigaShader;
Texture* lantaiTingkatTigaTexture;
Transform* lantaiTingkatTigaTransform;

Mesh2* tempatTowerBawah;
Shader* tempatTowerBawahShader;
Texture* tempatTowerBawahTexture;
Transform* tempatTowerBawahTransform;

Mesh2* tempatTowerBawah_Upper;
Shader* tempatTowerBawahShader_Upper;
Texture* tempatTowerBawahTexture_Upper;
Transform* tempatTowerBawahTransform_Upper;

Mesh2* tempatTowerTengah;
Shader* tempatTowerTengahShader;
Texture* tempatTowerTengahTexture;
Transform* tempatTowerTengahTransform;


Mesh* tempatTowerAtas;
Shader* tempatTowerAtasShader;
Texture* tempatTowerAtasTexture;
Transform* tempatTowerAtasTransform;

Mesh2* towerMonasTengah;
Shader* towerMonasTengahShader;
Texture* towerMonasTengahTexture;
Transform* towerMonasTengahTransform;

Mesh* towerMonasAtas;
Shader* towerMonasAtasShader;
Texture* towerMonasAtasTexture;
Transform* towerMonasAtasTransform;

Mesh2* towerMonasTempatPucuk;
Shader* towerMonasTempatPucukShader;
Texture* towerMonasTempatPucukTexture;
Transform* towerMonasTempatPucukTransform;


Mesh2* towerMonasKotakPucuk;
Shader* towerMonasKotakPucukShader;
Texture* towerMonasKotakPucukTexture;
Transform* towerMonasKotakPucukTransform;

Mesh* towerMonasPucuk;
Shader* towerMonasPucukShader;
Texture* towerMonasPucukTexture;
Transform* towerMonasPucukTransform;

Mesh* lantai;
Shader* lantaiShader;
Texture* lantaiTexture;
Transform* lantaiTransform;

Mesh* rumputTengah;
Shader* rumputTengahShader;
Texture* rumputTengahTexture;
Transform* rumputTengahTransform;

Mesh2* rumputBawah;
Shader* rumputBawahShader;
Texture* rumputBawahTexture;
Transform* rumputBawahTransform;

Mesh2* rumputAtas;
Shader* rumputAtasShader;
Texture* rumputAtasTexture;
Transform* rumputAtasTransform;

Mesh2* rumputKanan;
Shader* rumputKananShader;
Texture* rumputKananTexture;
Transform* rumputKananTransform;

Mesh2* rumputKiri;
Shader* rumputKiriShader;
Texture* rumputKiriTexture;
Transform* rumputKiriTransform;

Mesh2* pucuk;
Shader* pucukShader;
Texture* pucukTexture;
Transform* pucukTransform;

Camera* camera;

Light* light;

float posCamX = 0;
float posCamY = 3;
float posCamZ = 5;

float viewCamX = 0.0f, viewCamY = 0.0f, viewCamZ = 1.0f;
float speed = 0.05f;

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

	camera = new Camera(glm::vec3(0, 20, 50), 70.0f, (GLfloat)this->screenWidth / (GLfloat)this->screenHeight, .1f, 250.0f);


	light = new Light();
	light->x = 0.5f;
	light->y = -0.6f;
	light->z = -0.2f;

	lantaiShader = new Shader("Shaders/Triangle");
	lantaiTexture = new Texture("res/green_dot.png", GL_LINEAR_MIPMAP_NEAREST);
	lantaiTransform = new Transform();
	lantai = Plane();
	
	lantaiTingkatSatuShader = new Shader("Shaders/Texture");
	lantaiTingkatSatuTexture = new Texture("res/cream_dot.png", GL_LINEAR_MIPMAP_NEAREST);
	lantaiTingkatSatuTransform = new Transform();
	lantaiTingkatSatu = LantaiTingkatSatu();

	lantaiTingkatDuaShader = new Shader("Shaders/Triangle4v"); //stpq
	lantaiTingkatDuaTexture = new Texture("res/white-cream.png", GL_LINEAR_MIPMAP_NEAREST);
	lantaiTingkatDuaTransform = new Transform();
	lantaiTingkatDua = LantaiTingkatDua2();

	lantaiTingkatTigaShader = new Shader("Shaders/Triangle");
	lantaiTingkatTigaTexture = new Texture("res/cream_dot.png", GL_LINEAR_MIPMAP_NEAREST);
	lantaiTingkatTigaTransform = new Transform();
	lantaiTingkatTiga = LantaiTingkatTiga();
	
	
	tempatTowerBawahShader = new Shader("Shaders/Triangle");
	tempatTowerBawahTexture = new Texture("res/brown_dot.png", GL_LINEAR_MIPMAP_NEAREST);
	tempatTowerBawahTransform = new Transform();
	tempatTowerBawah = TempatTowerBawah2();
	
	tempatTowerBawahShader_Upper = new Shader("Shaders/Triangle4v");
	tempatTowerBawahTexture_Upper = new Texture("res/red.png", GL_LINEAR_MIPMAP_NEAREST);
	tempatTowerBawahTransform_Upper = new Transform();
	tempatTowerBawah_Upper = TempatTowerBawah2_Upper();
	
	tempatTowerTengahShader = new Shader("Shaders/Triangle4v");
	tempatTowerTengahTexture = new Texture("res/white-cream.png", GL_LINEAR_MIPMAP_NEAREST);
	tempatTowerTengahTransform = new Transform();
	tempatTowerTengah = TempatTowerTengah2();


	tempatTowerAtasShader = new Shader("Shaders/Triangle");
	tempatTowerAtasTexture = new Texture("res/white-cream_dot.png", GL_LINEAR_MIPMAP_NEAREST);
	tempatTowerAtasTransform = new Transform();
	tempatTowerAtas = TempatTowerAtas();

	towerMonasTengahShader = new Shader("Shaders/Triangle4v");
	towerMonasTengahTexture = new Texture("res/white.png", GL_LINEAR_MIPMAP_NEAREST);
	towerMonasTengahTransform = new Transform();
	towerMonasTengah = TowerMonasTengah2();
	
	towerMonasAtasShader = new Shader("Shaders/Triangle");
	towerMonasAtasTexture = new Texture("res/white-cream.png", GL_LINEAR_MIPMAP_NEAREST);
	towerMonasAtasTransform = new Transform();
	towerMonasAtas = TowerMonasAtas();
	
	towerMonasTempatPucukShader = new Shader("Shaders/Triangle4v");
	towerMonasTempatPucukTexture = new Texture("res/white-cream.png", GL_LINEAR_MIPMAP_NEAREST);
	towerMonasTempatPucukTransform = new Transform();
	towerMonasTempatPucuk = TowerMonasTempatPucuk2();
	
	
	towerMonasKotakPucukShader = new Shader("Shaders/Triangle4v");
	towerMonasKotakPucukTexture = new Texture("res/white-cream.png", GL_LINEAR_MIPMAP_NEAREST);
	towerMonasKotakPucukTransform = new Transform();
	towerMonasKotakPucuk = TowerMonasKotakPucuk2();	

	pucukShader = new Shader("Shaders/Triangle4v");
	pucukTexture = new Texture("res/gold.png", GL_LINEAR_MIPMAP_NEAREST);
	pucukTransform = new Transform();
	pucuk = Pucuk();

	rumputTengahShader = new Shader("Shaders/Triangle");
	rumputTengahTexture = new Texture("res/black_dot.png", GL_LINEAR_MIPMAP_NEAREST);
	rumputTengahTransform = new Transform();
	rumputTengah = RumputTengah();

	rumputBawahShader = new Shader("Shaders/Triangle4v");
	rumputBawahTexture = new Texture("res/grey_dot.png", GL_LINEAR_MIPMAP_NEAREST);
	rumputBawahTransform = new Transform();
	rumputBawah = RumputBawah();

	rumputAtasShader = new Shader("Shaders/Triangle4v");
	rumputAtasTexture = new Texture("res/grey_dot.png", GL_LINEAR_MIPMAP_NEAREST);
	rumputAtasTransform = new Transform();
	rumputAtas = RumputAtas();

	rumputKananShader = new Shader("Shaders/Triangle4v");
	rumputKananTexture = new Texture("res/grey_dot.png", GL_LINEAR_MIPMAP_NEAREST);
	rumputKananTransform = new Transform();
	rumputKanan = RumputKanan();

	rumputKiriShader = new Shader("Shaders/Triangle4v");
	rumputKiriTexture = new Texture("res/grey_dot.png", GL_LINEAR_MIPMAP_NEAREST);
	rumputKiriTransform = new Transform();
	rumputKiri = RumputKiri();

	bisBodyShader = new Shader("Shaders/Texture");
	bisBodyTexture = new Texture("res/blue1.png", GL_LINEAR_MIPMAP_NEAREST);
	bisBodyTransform = new Transform();
	bisBodyTransform->pos.x = 15 + 7.5f;
	bisBody = BisBody();
	
}

void RenderEngine::DeInit() {
	camera->~Camera();
	lantaiShader->~Shader();
	lantai->~Mesh();
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
int counter = 50;
void RenderEngine::Update(double deltaTime) {
	if (bisBodyTransform->pos.z >= 37.2 ) {
		bisBodyTransform->pos.z = -22.2;
	} else {
		bisBodyTransform->pos.z += 0.05;
	}

}

void UpdateBis() {
	float maxX = 15 + 7.5f;
	float minX = -15 - 7.5f;
	float maxZ = maxX;
	float minZ = minX;

	glm::vec3 pos = bisBodyTransform->pos;
	bisBodyTransform->pos.z += 0.5;
	/*
	if (pos.x == maxX || pos.x == minX) {
		if (pos.z <= maxZ && pos.x == minX) {
			bisBodyTransform->pos.z += 0.5;
		}
		else if (pos.z > minZ && pos.x == maxX) {
			bisBodyTransform->pos.z -= 0.5;
		}
		else if (pos.z == maxZ) {
			bisBodyTransform->pos.z = maxZ;
		}
		else if (pos.z = minZ) {
			bisBodyTransform->pos.z = minZ;
		}
	}
	else if (pos.z == maxZ || pos.z == minZ) {
		if (pos.x <= maxX && pos.z == minZ) {
			bisBodyTransform->pos.x += 0.5;
		}
		else if (pos.x > minX && pos.z == maxZ) {
			bisBodyTransform->pos.x -= 0.5;
		}
		else if (pos.z == maxZ) {
			bisBodyTransform->pos.x = maxX;
		}
		else if (pos.z = minZ) {
			bisBodyTransform->pos.x = minX;
		}
	}
	*/


}

void RenderEngine::Render() {
	Clear(0.992f, 0.604f, 0.451f, 0.0f);

	camera->position.x = posCamX;
	camera->position.y = posCamY;
	camera->position.z = posCamZ;

	camera->forward.x = viewCamX;
	camera->forward.y = viewCamY;
	camera->forward.z = viewCamZ;

	lantaiTexture->Bind();
	lantaiShader->Bind();
	lantaiShader->Update(*lantaiTransform, *camera, glm::vec3(light->x, light->y, light->z));
	lantai->Draw();

	
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
	//tempatTowerBawah->Draw();

	tempatTowerBawahTexture_Upper->Bind();
	tempatTowerBawahShader_Upper->Bind();
	tempatTowerBawahShader_Upper->Update(*tempatTowerBawahTransform, *camera, glm::vec3(light->x, light->y, light->z), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));
	tempatTowerBawah_Upper->Draw();

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
	
	pucukTexture->Bind();
	pucukShader->Bind();
	pucukShader->Update(*towerMonasKotakPucukTransform, *camera, glm::vec3(light->x, light->y, light->z), glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));
	pucuk->Draw();

	rumputTengahTexture->Bind();
	rumputTengahShader->Bind();
	rumputTengahShader->Update(*rumputTengahTransform, *camera, glm::vec3(light->x, light->y, light->z), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));

	rumputTengah->Draw();

	rumputBawahTexture->Bind();
	rumputBawahShader->Bind();
	rumputBawahShader->Update(*rumputBawahTransform, *camera, glm::vec3(light->x, light->y, light->z), glm::vec4(0.0f, 1.0f, 1.0f, 1.0f));

	rumputBawah->Draw();

	rumputAtasTexture->Bind();
	rumputAtasShader->Bind();
	rumputAtasShader->Update(*rumputAtasTransform, *camera, glm::vec3(light->x, light->y, light->z));

	rumputAtas->Draw();
	
	rumputKananTexture->Bind();
	rumputKananShader->Bind();
	rumputKananShader->Update(*rumputKananTransform, *camera, glm::vec3(light->x, light->y, light->z), glm::vec4(1.0f, 1.0f, 1.0f, 0.0f));
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
