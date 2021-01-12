#include "Camera.h"

Camera::Camera()
	:m_View(glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp)), 
	m_Projection(glm::perspective(glm::radians(45.0f), (float)1280/(float)720, 0.1f, 100.0f))
{
}

Camera::~Camera()
{
}

glm::mat4 Camera::getViewProjection()
{
	return m_Projection * m_View;
}

glm::vec3 Camera::getcameraPos()
{
	return cameraPos;
}
glm::vec3 Camera::getcameraFront()
{
	return cameraFront;
}
glm::vec3 Camera::getcameraUp()
{
	return cameraUp;
}

void Camera::setcameraPos(glm::vec3 pos)
{
	cameraPos = pos;
}

void Camera::Update()
{
	m_View = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
}