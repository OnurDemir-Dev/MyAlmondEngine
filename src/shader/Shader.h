#ifndef SHADER_H
#define SHADER_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <iostream>

class Shader
{
public:
    Shader(const char* vertexShaderDir, const char* fragmentShaderDir);

    void useShader();
private:
    GLuint m_vertexShader, m_fragmentShader;
    GLuint m_shaderProgram;

    void checkCompileErrors(GLuint shader, std::string type);
};

#endif