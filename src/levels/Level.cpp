#include "levels/Level.h"


void Level::baseStart()
{
    Start();
}

void Level::baseUpdate(float deltaTime)
{
    for (int i = 0; i < m_objects.size(); i++)
    {
        m_objects[i]->Update();
        Update(deltaTime);
    }
}

void Level::baseDraw()
{
    for (int i = 0; i < m_objects.size(); i++)
    {
        m_objects[i]->Draw();
        Draw();
    }
}


void Level::Start()
{
    
}

void Level::Update(float deltaTime)
{

}

void Level::Draw()
{
}
