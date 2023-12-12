#ifndef CAMERA_H
#define CAMERA_H

#include "transforms/Vectors.h"

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>

enum Camera_Movement {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT,
    UP,
    DOWN
};

// Default camera values
const float YAW = -90.0f;
const float PITCH = 0.0f;
const float SPEED = 2.5f;
const float SENSITIVITY = 0.1f;
const float ZOOM = 45.0f;

class Camera
{
public:
    // camera Attributes
    Vector3 Position;
    Vector3 Front;
    Vector3 Up;
    Vector3 Right;
    Vector3 WorldUp;
    Vector3 absFront;
    // euler Angles
    float Yaw;
    float Pitch;
    // camera options
    float MovementSpeed;
    float MouseSensitivity;
    float Zoom;
    glm::mat4 projection;

    Camera(Vector3 position = Vector3(0.0f, 0.0f, 0.0f), Vector3 up = Vector3(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH);
    Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch);

    void Start();
    void Update(float deltaTime);
    void Draw();

    glm::mat4 GetViewMatrix() { return glm::lookAt(glm::vec3(Position), glm::vec3(Position + Front), glm::vec3(Up)); }

    void ProcessKeyboard(Camera_Movement direction, float deltaTime);
    void ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true);
    void ProcessMouseScroll(float yoffset);

    glm::mat4 LookAt(Vector3 position, Vector3 target, Vector3 worldUp);

private:
    void updateCameraVectors();
};


#endif // !CAMERA_H


