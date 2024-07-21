#include "objects/Object.h"
#include "engine/Engine.h"
#include "Object.h"


Object::Object()
{
    m_objectName = "Default";
}

void Object::baseStart()
{
    WriteOnConsole("Start");
    Start();
}

void Object::baseUpdate(float deltaTime)
{
    Update(deltaTime);
    for (int i = 0; i < m_components.size(); i++)
    {
        m_components[i]->Update(deltaTime);
    }
}

void Object::baseDraw()
{
    Draw();
    for (int i = 0; i < m_components.size(); i++)
    {
        m_components[i]->Draw();
    }
}

void Object::Start()
{
    
}

void Object::Update(float deltaTime)
{
    
}

void Object::Draw()
{

}

void Object::setPosition(const Vector3 position)
{
    m_transform.SetPosition(position);
}

Transform Object::getTransform()
{
    return m_transform;
}

