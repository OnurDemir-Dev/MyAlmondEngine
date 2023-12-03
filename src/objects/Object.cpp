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

void Object::Update(float deltaTime)
{
    
}

void Object::Draw()
{

}


