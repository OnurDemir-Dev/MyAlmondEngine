#ifndef VECTORS_H
#define VECTORS_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/matrix_decompose.hpp>

// Define Vector3 class derived from Vector2
class Vector3 {
public:
    

    // Constructors
    Vector3() : data(0.0f, 0.0f, 0.0f) {}
    Vector3(float x, float y, float z) : data(x, y, z) {}

    void Translate(Vector3 newVector3);

protected:
    glm::vec3 data;

    glm::vec3 getPositionFromMat4(const glm::mat4& matrix) 
    {
        return glm::vec3(matrix[3]);  // Extract the translation part from the fourth column
    }
/*
    glm::vec3 getRotationFromMat4(const glm::mat4& matrix) 
    {
        // Extract rotation matrix
        glm::mat3 rotationMatrix = glm::mat3(matrix);

        // Convert rotation matrix to Euler angles
        glm::vec3 euler = glm::degrees(glm::extractEulerAngleXYZ(rotationMatrix));

        return euler;
    }
    */

    glm::vec3 getScaleFromMat4(const glm::mat4& matrix)
    {
        glm::vec3 scale;
        
        // Extract the scale along each axis
        scale.x = glm::length(glm::vec3(matrix[0])); // X-axis
        scale.y = glm::length(glm::vec3(matrix[1])); // Y-axis
        scale.z = glm::length(glm::vec3(matrix[2])); // Z-axis
        
        return scale;
    }
};


// Define Vector2 class
class Vector2 : public Vector3 {
public:
    glm::vec3 data;

    // Constructors
    Vector2() : data(0.0f, 0.0f, 0.0f) {}
    Vector2(float x, float y) : data(x, y, 0.0f) {}
};

class Transform 
{

public:

    Transform() : m_position(0.0f, 0.0f, 0.0f), m_rotation(0.0f, 0.0f, 0.0f), m_scale(1.0f, 1.0f, 1.0f) {}

    void SetPosition(Vector3 newPos);
protected:
    Vector3 m_position;
    Vector3 m_rotation;
    Vector3 m_scale;

};


#endif