#pragma once

#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera
{
public:
	Camera();
	~Camera();
	glm::mat4 getViewProjection();
	glm::vec3 getcameraPos();
	glm::vec3 getcameraFront();
	glm::vec3 getcameraUp();
	void setcameraPos(glm::vec3 pos);
	void setcameraFont(glm::vec3 pos);
	void Update();
private:
	glm::mat4 m_View;
	glm::mat4 m_Projection;
	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
	glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
};