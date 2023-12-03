#ifndef SHADER_H
#define SHADER_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "transforms/Vectors.h"

#include <iostream>

class Shader
{
public:
    Shader(const char* vertexShaderDir, const char* fragmentShaderDir);

    void useShader();

    GLint getUniformLocation(const std::string& localName) const;

    void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;
    void setVec3(const std::string& name, const Vector3& value) const;
	void setVec3(const std::string& name, float x, float y, float z) const;
    void setMat4(const std::string& name, const glm::mat4& mat) const;
    
private:
    GLuint m_vertexShader, m_fragmentShader;
    GLuint m_shaderProgram;

    void checkCompileErrors(GLuint shader, std::string type);
};

#endif