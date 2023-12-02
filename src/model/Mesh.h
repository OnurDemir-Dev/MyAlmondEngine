#ifndef MESH_H
#define MESH_H

#include "common.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"


#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

class Mesh
{

public:
    Mesh(const std::vector<glm::vec3> vertices, const std::vector<GLuint>& indices);
    ~Mesh();

    void Draw();

private:
    GLuint VAO, VBO, EBO;
    GLuint* m_meshShader;
    GLsizei indexCount;
};

#endif