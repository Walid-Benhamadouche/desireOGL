#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "core/Desire.h"

static Scene* m_Scene = nullptr;

class Application
{
public:
	Application(const char* name);
	~Application();
	static void setScene(Scene* sc);
	void Run();
private:
	void processInput();
	GLFWwindow* m_Window;
	const float cameraSpeed = 0.05f;
};