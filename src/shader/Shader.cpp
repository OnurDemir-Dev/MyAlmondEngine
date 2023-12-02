#include "shader/Shader.h"

#include "common.h"

#include <fstream>
#include <sstream>

Shader::Shader(const char* vertexShaderDir, const char* fragmentShaderDir)
{
    // Read vertex shader source from file
    std::string vertexShaderSource = readFile(vertexShaderDir);
    if (vertexShaderSource.empty()) {
        std::cerr << "Failed to read vertex shader source" << std::endl;
    }

    // Read fragment shader source from file
    std::string fragmentShaderSource = readFile(fragmentShaderDir);
    if (fragmentShaderSource.empty()) {
        std::cerr << "Failed to read fragment shader source" << std::endl;
    }

    // Compile and link shaders
    const char* vertexShaderSourceCStr = vertexShaderSource.c_str();
    m_vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(m_vertexShader, 1, &vertexShaderSourceCStr, NULL);
    glCompileShader(m_vertexShader);
    checkCompileErrors(m_vertexShader, "VERTEX");

    const char* fragmentShaderSourceCStr = fragmentShaderSource.c_str();
    m_fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(m_fragmentShader, 1, &fragmentShaderSourceCStr, NULL);
    glCompileShader(m_fragmentShader);
    checkCompileErrors(m_fragmentShader, "FRAGMENT");

    m_shaderProgram = glCreateProgram();
    glAttachShader(m_shaderProgram, m_vertexShader);
    glAttachShader(m_shaderProgram, m_fragmentShader);
    glLinkProgram(m_shaderProgram);
    checkCompileErrors(m_shaderProgram, "PROGRAM");

    glDeleteShader(m_vertexShader);
    glDeleteShader(m_fragmentShader);

}

void Shader::useShader()
{
    glUseProgram(m_shaderProgram);
}


void Shader::checkCompileErrors(GLuint shader, std::string type)
    {
        GLint success;
        GLchar infoLog[1024];
        if (type != "PROGRAM")
        {
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
            if (!success)
            {
                glGetShaderInfoLog(shader, 1024, NULL, infoLog);
                std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
            }
        }
        else
        {
            glGetProgramiv(shader, GL_LINK_STATUS, &success);
            if (!success)
            {
                glGetProgramInfoLog(shader, 1024, NULL, infoLog);
                std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
            }
        }
    }
