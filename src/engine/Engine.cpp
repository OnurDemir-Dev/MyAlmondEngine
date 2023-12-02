#include "Engine.h"

#include "model/Mesh.h"

Engine* Engine::CurrentEngine = nullptr;
Level* Engine::CurrentLevel = nullptr;

Engine::Engine()
{
    CurrentEngine = this;
}

int Engine::StartEngine(Level* startLevel, int width, int height, const char* windowName, GLFWmonitor* monitor, GLFWwindow* share)
{
    CurrentLevel = startLevel;
    if(!glfwInit())
    {
        std::cout << "GLFW Init not working!!!";
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    m_mainWindow = glfwCreateWindow(width, height, windowName, monitor, share);

    if (m_mainWindow == NULL)
    {
        std::cout << "Window Create Problem not working!!!";
        return -1;
    }
    
    glfwMakeContextCurrent(m_mainWindow);
    glfwSetWindowAspectRatio(m_mainWindow, GLFW_DONT_CARE, GLFW_DONT_CARE);

    gladLoadGL();

    startLevel->Start();


    Shader currentShader("src\\resources\\shaders\\default.vert", "src\\resources\\shaders\\default.frag");

    

    while (!glfwWindowShouldClose(m_mainWindow))
    {
        currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        Update(deltaTime);

        currentShader.useShader();

        Draw();

        glfwSwapBuffers(m_mainWindow);
        glfwPollEvents();
    }
    

    glfwTerminate();

    return 0;
}

void Engine::Start()
{
    CurrentLevel->baseStart();
}

void Engine::Update(float deltaTime)
{
    CurrentLevel->baseUpdate(deltaTime);
}

void Engine::Draw()
{
    CurrentLevel->baseDraw();
}