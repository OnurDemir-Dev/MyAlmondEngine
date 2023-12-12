#include "Camera.h"

#include "engine/Engine.h"

Camera::Camera(Vector3 position, Vector3 up, float yaw, float pitch) : Front(Vector3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM)
{
    Position = position;
    WorldUp = up;
    Yaw = yaw;
    Pitch = pitch;
    projection = glm::perspective(glm::radians(Zoom), (float)Engine::ScreenWidth / (float)Engine::ScreenHeight, 0.1f, 100.0f); 
    updateCameraVectors();
}

Camera::Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch) : Front(Vector3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM)
{
    Position = Vector3(posX, posY, posZ);
    WorldUp = Vector3(upX, upY, upZ);
    Yaw = yaw;
    Pitch = pitch;
    projection = glm::perspective(glm::radians(Zoom), (float)Engine::ScreenWidth / (float)Engine::ScreenHeight, 0.1f, 100.0f); 
    updateCameraVectors();
}

void Camera::Start()
{
}

void Camera::Update(float deltaTime)
{
    projection = glm::perspective(glm::radians(Zoom), (float)Engine::ScreenWidth / (float)Engine::ScreenHeight, 0.1f, 100.0f);
}

void Camera::Draw()
{
    Engine::CurrentShader->setMat4("view", GetViewMatrix());
    Engine::CurrentShader->setMat4("projection", projection);
}

void Camera::ProcessKeyboard(Camera_Movement direction, float deltaTime)
{
    float velocity = MovementSpeed * deltaTime;
    if (direction == FORWARD)
    {
        Position += Front * velocity;
        std::cout << Position.x() << ", " << Position.y() << ", " << Position.z() << std::endl;
        std::cout << MovementSpeed << std::endl;
    }
        
    if (direction == BACKWARD)
        Position -= Front * velocity;
    if (direction == LEFT)
        Position -= Right * velocity;
    if (direction == RIGHT)
        Position += Right * velocity;
    if (direction == UP)
        Position += Up * velocity;
    if (direction == DOWN)
        Position -= Up * velocity;
}

void Camera::ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch)
{
    xoffset *= MouseSensitivity;
    yoffset *= MouseSensitivity;

    Yaw += xoffset;
    Pitch += yoffset;

    // make sure that when pitch is out of bounds, screen doesn't get flipped
    if (constrainPitch)
    {
        if (Pitch > 89.0f)
            Pitch = 89.0f;
        if (Pitch < -89.0f)
            Pitch = -89.0f;
    }

    // update Front, Right and Up Vectors using the updated Euler angles
    updateCameraVectors();
}

void Camera::ProcessMouseScroll(float yoffset)
{
    Zoom -= (float)yoffset;
    if (Zoom < 1.0f)
        Zoom = 1.0f;
    if (Zoom > 45.0f)
        Zoom = 45.0f;
}

glm::mat4 Camera::LookAt(Vector3 position, Vector3 target, Vector3 worldUp)
{
    Vector3 zaxis = (position - target);
    zaxis = zaxis.normalize();
    worldUp = worldUp.normalize();
    Vector3 xaxis = worldUp.cross(zaxis).normalize();
    Vector3 yaxis = zaxis.cross(xaxis);

    // Create translation and rotation matrix
    // In glm we access elements as mat[col][row] due to column-major layout
    glm::mat4 translation = glm::mat4(1.0f); // Identity matrix by default
    translation[3][0] = -position.x(); // Third column, first row
    translation[3][1] = -position.y();
    translation[3][2] = -position.z();
    glm::mat4 rotation = glm::mat4(1.0f);
    rotation[0][0] = xaxis.x(); // First column, first row
    rotation[1][0] = xaxis.y();
    rotation[2][0] = xaxis.z();
    rotation[0][1] = yaxis.x(); // First column, second row
    rotation[1][1] = yaxis.y();
    rotation[2][1] = yaxis.z();
    rotation[0][2] = zaxis.x(); // First column, third row
    rotation[1][2] = zaxis.y();
    rotation[2][2] = zaxis.z();

    return translation * rotation;
}

void Camera::updateCameraVectors()
{
    // calculate the new Front vector
    Vector3 front;
    front.x(cos(glm::radians(Yaw)) * cos(glm::radians(Pitch)));
    front.y(sin(glm::radians(Pitch)));
    front.z(sin(glm::radians(Yaw)) * cos(glm::radians(Pitch)));

    Vector3 absfront;
    absfront.x(cos(glm::radians(Yaw)));
    absfront.y(0.0f);
    absfront.z(sin(glm::radians(Yaw)));

    Front = front.normalize();
    absFront = absfront.normalize();
    // also re-calculate the Right and Up vector
    Right = Front.cross(WorldUp).normalize();  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
    Up = Right.cross(Front).normalize();
}


