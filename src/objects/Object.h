#ifndef OBJECT_H
#define OBJECT_H

#include "transforms/Vectors.h"
#include "objects/Component.h"

#include <algorithm>
#include <iostream>
#include <vector>

class Object
{

public:
    Object();

    

    virtual void Start();
    virtual void Update(float deltaTime);
    virtual void Draw();

    void SetName(const char* newName) { m_objectName = newName; }

    void setPosition(const Vector3 position);
    void setScale(const Vector3 scale);
    void setRotation(float angle, const Vector3 axis);

    Transform getTransform();

    template <typename T, typename... TArgs >
    T* CreateComponent(TArgs... args)
    {
        T* tempComponent = new T(args...);
        tempComponent->SetOwnerObject(this);
        tempComponent->Start();
        m_components.push_back(tempComponent);
        return tempComponent;
    }

    template <typename T, typename... TArgs>
    T* GetComponent()
    {
        auto tempComponent = std::find_if(m_components.begin(), m_components.end(), [](Component* e) { return typeid(*e) == typeid(T); });
        if (tempComponent != m_components.end())
        {
            return static_cast<T*>(*tempComponent);
        }
        
        return nullptr;
    }


    template <typename T>
    void WriteOnConsole(T logString) 
    {
        std::cout<< m_objectName << ": " << logString << std::endl;
    }

private:

    const char* m_objectName;

    Transform m_transform;

    std::vector<Component*> m_components;

    void baseStart();
    void baseUpdate(float deltaTime);
    void baseDraw();
    friend class Level;

};
#endif