#ifndef MESH_H
#define MESH_H

#include "common.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include "transforms/Vectors.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

class Mesh
{

public:
    Mesh(const std::vector<Vector3> vertices, const std::vector<unsigned int>& indices);
    ~Mesh();

    void Draw();

private:
    GLuint VAO, VBO, EBO;
    //TODO: Mesh Shader will change later
    GLuint* m_meshShader;
    GLsizei indexCount;
};

#endif