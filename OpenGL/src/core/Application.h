#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "core/Desire.h"

static Scene* m_Scene = nullptr;
static const float cameraSpeed = 0.05f, sensitivity = 0.1f;
static double lastX = 640, lastY = 360, yaw = -90.0f, pitch = 0.0f;
static bool firstMouse = true;

class Application
{
public:
	Application(const char* name);
	~Application();
	static void setScene(Scene* sc);
	void Run();
private:
	void processInput();
	static void mouse_callback(GLFWwindow* window, double xpos, double ypos);
	GLFWwindow* m_Window;
};