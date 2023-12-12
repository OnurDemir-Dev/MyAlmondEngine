#include "Engine.h"

#include "model/Mesh.h"

Engine* Engine::CurrentEngine = nullptr;
Level* Engine::CurrentLevel = nullptr;
Shader* Engine::CurrentShader = nullptr;
int Engine::ScreenWidth = 1920;
int Engine::ScreenHeight = 1080;

float lastX = Engine::ScreenWidth / 2.0f;
float lastY = Engine::ScreenHeight / 2.0f;
bool firstMouse = true;

void mouse_callback(GLFWwindow* window, double xposIn, double yposIn);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

Engine::Engine()
{
    CurrentEngine = this;
}

int Engine::StartEngine(Level* startLevel, int width, int height, const char* windowName, GLFWmonitor* monitor, GLFWwindow* share)
{
    CurrentLevel = startLevel;

    Engine::ScreenWidth = width;
    Engine::ScreenHeight = height;

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
    glfwSetCursorPosCallback(m_mainWindow, mouse_callback);
    glfwSetFramebufferSizeCallback(m_mainWindow, framebuffer_size_callback);

     // tell GLFW to capture our mouse
    glfwSetInputMode(m_mainWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    gladLoadGL();

    startLevel->Start();


    CurrentShader = new Shader("src\\resources\\shaders\\default.vert", "src\\resources\\shaders\\default.frag");
    

    while (!glfwWindowShouldClose(m_mainWindow))
    {
        currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        Update(deltaTime);
        processInput(m_mainWindow);

        glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        CurrentShader->useShader();

        Draw();

        glfwSwapBuffers(m_mainWindow);
        glfwPollEvents();
    }
    

    glfwTerminate();

    return 0;
}

//TODO: Will change
void Engine::processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_F11) == GLFW_PRESS)
    {
        // Get the primary monitor
            
        GLFWmonitor* monitor = glfwGetWindowMonitor(window);
        if(monitor == nullptr)
        {
            monitor = glfwGetPrimaryMonitor();
            // Get the video mode of the primary monitor
            const GLFWvidmode* mode = glfwGetVideoMode(monitor);

            // Switch the window to fullscreen mode
            glfwSetWindowMonitor(window, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
        }
        else
        {
            glfwSetWindowMonitor(window, NULL, 100, 100, ScreenWidth, ScreenHeight, GLFW_DONT_CARE);
        }
    }
    

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		CurrentLevel->GetLevelCamera()->ProcessKeyboard(FORWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		CurrentLevel->GetLevelCamera()->ProcessKeyboard(BACKWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		CurrentLevel->GetLevelCamera()->ProcessKeyboard(LEFT, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		CurrentLevel->GetLevelCamera()->ProcessKeyboard(RIGHT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        CurrentLevel->GetLevelCamera()->ProcessKeyboard(UP, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
        CurrentLevel->GetLevelCamera()->ProcessKeyboard(DOWN, deltaTime);  
}

void mouse_callback(GLFWwindow *window, double xposIn, double yposIn)
{
    float xpos = static_cast<float>(xposIn);
	float ypos = static_cast<float>(yposIn);

	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

	lastX = xpos;
	lastY = ypos;

	Engine::CurrentLevel->GetLevelCamera()->ProcessMouseMovement(xoffset, yoffset);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    Engine::CurrentLevel->GetLevelCamera()->projection = glm::perspective(glm::radians(Engine::CurrentLevel->GetLevelCamera()->Zoom), (float)width / (float)height, 0.1f, 100.0f);
	glViewport(0, 0, width, height);
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