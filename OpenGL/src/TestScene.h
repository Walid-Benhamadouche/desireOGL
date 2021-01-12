#pragma once

#include "core/Desire.h"

class TestScene : public Scene
{
public:
	TestScene();
	virtual ~TestScene();

	virtual void OnCreate() override;
	virtual void OnUpdate() override;
	virtual void OnImGuiRender() override;
	//Camera* m_Camera = nullptr;
private:
	GLuint IndexBuffer, m_VertexBuffer, m_QuadVA;
	std::unique_ptr<Shader> m_shader;
};