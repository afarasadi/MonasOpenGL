#pragma once
#include "../Headers/Display.h"

class RenderEngine :
	public Display
{
public:
	RenderEngine(int width, int height, const char* title, bool vsync, bool fullscreen);

private:
	virtual void Init();
	virtual void DeInit();
	virtual void ProcessInput(GLFWwindow* window);
	virtual void Update(double deltaTime);
	virtual void Render();

};

struct Light {
	float x;
	float y;
	float z;
};
