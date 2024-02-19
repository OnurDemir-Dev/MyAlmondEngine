#ifndef MESH_H
#define MESH_H

#include "common.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include "transforms/Vectors.h"
#include "objects/Component.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

class Mesh : public Component
{

public:
    Mesh(const std::vector<Vector3> vertices, const std::vector<unsigned int>& indices);
    ~Mesh();

    void Update();
    void Draw();

private:
    GLuint VAO, VBO, EBO;
    //TODO: Mesh Shader will change later
    GLuint* m_meshShader;
    GLsizei indexCount;
    glm::mat4 model;
};

#endif