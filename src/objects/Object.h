#ifndef OBJECT_H
#define OBJECT_H

#include "transforms/Vectors.h"

#include <iostream>

class Object
{

public:
    Object();

    virtual void Start();
    virtual void Update();
    virtual void Draw();

    void SetName(const char* newName) { m_objectName = newName; }

    void setPosition(const glm::vec3& position);
    void setScale(const glm::vec3& scale);
    void setRotation(float angle, const glm::vec3& axis);


    template <typename T>
    T* CreateObject();

    template <typename T>
    void WriteOnConsole(T logString);

private:

    const char* m_objectName;

    Transform m_transform;

};
#endif