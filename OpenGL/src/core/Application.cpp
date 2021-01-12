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
            m_Scene->OnUpdate();
        }

        glfwSwapBuffers(m_Window);
        glfwPollEvents();
    }
}

void Application::processInput()
{
    if (glfwGetKey(m_Window, GLFW_KEY_W) == GLFW_PRESS && m_Scene->m_Camera!=nullptr)
    {
        auto pos = m_Scene->m_Camera->getcameraPos();
        auto front = m_Scene->m_Camera->getcameraFront();
        m_Scene->m_Camera->setcameraPos((pos + (cameraSpeed * front)));
        m_Scene->m_Camera->Update();
    }
    if (glfwGetKey(m_Window, GLFW_KEY_S) == GLFW_PRESS && m_Scene->m_Camera != nullptr)
    {
        auto pos = m_Scene->m_Camera->getcameraPos();
        auto front = m_Scene->m_Camera->getcameraFront();
        m_Scene->m_Camera->setcameraPos((pos - (cameraSpeed * front)));
        m_Scene->m_Camera->Update();
    }
    if (glfwGetKey(m_Window, GLFW_KEY_A) == GLFW_PRESS && m_Scene->m_Camera != nullptr)
    {
        auto pos = m_Scene->m_Camera->getcameraPos();
        auto front = m_Scene->m_Camera->getcameraFront();
        auto up = m_Scene->m_Camera->getcameraUp();
        m_Scene->m_Camera->setcameraPos(pos - (glm::normalize(glm::cross(front, up)) * cameraSpeed));
        m_Scene->m_Camera->Update();
    }
    if (glfwGetKey(m_Window, GLFW_KEY_D) == GLFW_PRESS && m_Scene->m_Camera != nullptr)
    {
        auto pos = m_Scene->m_Camera->getcameraPos();
        auto front = m_Scene->m_Camera->getcameraFront();
        auto up = m_Scene->m_Camera->getcameraUp();
        m_Scene->m_Camera->setcameraPos(pos + (glm::normalize(glm::cross(front, up)) * cameraSpeed));
        m_Scene->m_Camera->Update();
    }
}

Application::~Application()
{
    glfwTerminate();
}