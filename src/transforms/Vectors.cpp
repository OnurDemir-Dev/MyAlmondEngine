#include "transforms/Vectors.h"
#include "Vectors.h"

Vector3::operator glm::vec3() const
{
    return data;
}

void Vector3::Translate(Vector3 newVector3)
{
    data = getPositionFromMat4(glm::translate(glm::mat4(1.0f), newVector3.data));
}

//Transform Area
void Transform::SetPosition(Vector3 newPos)
{
    m_position.Translate(newPos);
}

Vector3 Transform::GetPosition()
{
    return m_position;
}