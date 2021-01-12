#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "util/Camera.h"

class Scene
{
public:
	inline Scene() {};
	virtual ~Scene() = default;

	virtual void OnCreate() {}
	virtual void OnUpdate() {}
	virtual void OnImGuiRender() {}

	Camera* m_Camera = nullptr;
};