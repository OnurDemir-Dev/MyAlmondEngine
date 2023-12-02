#include "objects/Object.h"
#include "engine/Engine.h"
#include "Object.h"


Object::Object()
{
    m_objectName = "Default";
}

void Object::Start()
{
    WriteOnConsole("Start");
}

void Object::Update()
{
    
}

void Object::Draw()
{

}


template <typename T>
T *Object::CreateObject()
{
    return Engine::CurrentLevel->CreateObject<T>();
}

template <typename T>
void Object::WriteOnConsole(T logString)
{
    std::cout<< m_objectName << ": " << logString << std::endl;
}