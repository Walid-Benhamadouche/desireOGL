#include "Application.h"

Application::Application(const char* name)
{
    if (!glfwInit())
    {
        std::cout << "error initialising glfw";
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_Window = glfwCreateWindow(1280, 720, name, NULL, NULL);
    if (!m_Window)
    {
        glfwTerminate();
    }

    glfwMakeContextCurrent(m_Window);
    glfwSetInputMode(m_Window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    glfwSwapInterval(1);

    if (glewInit() != GLEW_OK)
        std::cout << "glewInit error";

    std::cout << glGetString(GL_VERSION);
}

void Application::setScene(Scene* sc)
{
    m_Scene = sc;
    m_Scene->OnCreate();
}

void Application::Run()
{
    while (!glfwWindowShouldClose(m_Window))
    {
        if (m_Scene != nullptr)
        {
            processInput();
            m_Scene->m_Camera->Update();
            m_Scene->OnUpdate();
        }

        glfwSwapBuffers(m_Window);
        glfwPollEvents();
    }
}

void Application::processInput()
{
    glfwSetCursorPosCallback(m_Window, mouse_callback);
    if (glfwGetKey(m_Window, GLFW_KEY_W) == GLFW_PRESS && m_Scene->m_Camera!=nullptr)
    {
        auto pos = m_Scene->m_Camera->getcameraPos();
        auto front = m_Scene->m_Camera->getcameraFront();
        m_Scene->m_Camera->setcameraPos((pos + (cameraSpeed * front)));
    }
    if (glfwGetKey(m_Window, GLFW_KEY_S) == GLFW_PRESS && m_Scene->m_Camera != nullptr)
    {
        auto pos = m_Scene->m_Camera->getcameraPos();
        auto front = m_Scene->m_Camera->getcameraFront();
        m_Scene->m_Camera->setcameraPos((pos - (cameraSpeed * front)));
    }
    if (glfwGetKey(m_Window, GLFW_KEY_A) == GLFW_PRESS && m_Scene->m_Camera != nullptr)
    {
        auto pos = m_Scene->m_Camera->getcameraPos();
        auto front = m_Scene->m_Camera->getcameraFront();
        auto up = m_Scene->m_Camera->getcameraUp();
        m_Scene->m_Camera->setcameraPos(pos - (glm::normalize(glm::cross(front, up)) * cameraSpeed));
    }
    if (glfwGetKey(m_Window, GLFW_KEY_D) == GLFW_PRESS && m_Scene->m_Camera != nullptr)
    {
        auto pos = m_Scene->m_Camera->getcameraPos();
        auto front = m_Scene->m_Camera->getcameraFront();
        auto up = m_Scene->m_Camera->getcameraUp();
        m_Scene->m_Camera->setcameraPos(pos + (glm::normalize(glm::cross(front, up)) * cameraSpeed));
    }
}

void Application::mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    yaw += (xpos - lastX) * sensitivity;
    pitch += (lastY - ypos) * sensitivity;

    lastX = xpos;
    lastY = ypos;

    if (pitch > 89.0f)
        pitch = 89.0f;
    if (pitch < -89.0f)
        pitch = -89.0f;

    m_Scene->m_Camera->setcameraFont(glm::normalize(glm::vec3(
        cos(glm::radians(yaw)) * cos(glm::radians(pitch)),
        sin(glm::radians(pitch)),
        sin(glm::radians(yaw)) * cos(glm::radians(pitch))
    )));
}

Application::~Application()
{
    glfwTerminate();
}