#include "TestScene.h"

TestScene::TestScene(){}

void TestScene::OnCreate()
{
	std::cout << "window created inside on created in testscene";
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    m_Camera = new Camera();
    m_Camera->Update();

    glCreateVertexArrays(1, &m_QuadVA);
    glBindVertexArray(m_QuadVA);
    
    // vertex buffer generation
    float positions[] = {
       -0.5f , -0.5f , 0.0f,
        0.5f , -0.5f , 0.0f,
        0.5f ,  0.5f , 0.0f,
       -0.5f ,  0.5f , 0.0f
    };

    glGenBuffers(1, &m_VertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);

    // index buffer generation
    unsigned int indeces[] = {
        0, 1, 2,
        2, 3, 0
    };

    glGenBuffers(1, &IndexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indeces), indeces, GL_STATIC_DRAW);

    // shader loading
    m_shader = std::make_unique<Shader>("res/shaders/Basic.shader");
}

void TestScene::OnUpdate() 
{
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    int location = glGetUniformLocation(m_shader->m_RendererID, "u_MVP");
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(m_Camera->getViewProjection()));
    
    glUseProgram(m_shader->m_RendererID);
    
    glBindVertexArray(m_QuadVA);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
}

void TestScene::OnImGuiRender()
{

}

TestScene::~TestScene(){}