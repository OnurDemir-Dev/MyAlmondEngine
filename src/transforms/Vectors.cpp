#include "transforms/Vectors.h"
#include "Vectors.h"

void Vector3::Translate(Vector3 newVector3)
{
    data = getPositionFromMat4(glm::translate(glm::mat4(1.0f), newVector3.data));
}

//Transform Area
void Transform::SetPosition(Vector3 newPos)
{
    m_position.Translate(newPos);
}