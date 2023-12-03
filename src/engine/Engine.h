#ifndef ENGINE_H
#define ENGINE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <objects/Object.h>
#include "levels/Level.h"
#include "shader/Shader.h"

#include <iostream>
#include <vector>

class Engine
{
public:
    static Engine* CurrentEngine;
    static Level* CurrentLevel;
    static Shader* CurrentShader;

    Engine();

    int StartEngine(Level* startLevel, int width = 800, int height = 800, const char* windowName = "OpenGL", GLFWmonitor* monitor = NULL, GLFWwindow* share = NULL);

private:
    GLFWwindow* m_mainWindow;

    float currentFrame, lastFrame;
    float deltaTime;

    void Start();
    void Update(float deltaTime);
    void Draw();
};

#endif