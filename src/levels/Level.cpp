#include "levels/Level.h"
#include "Level.h"

Level::Level()
{
    levelCamera = new Camera();
}

void Level::baseStart()
{
    Start();
    levelCamera->Start();
}

void Level::baseUpdate(float deltaTime)
{
    for (int i = 0; i < m_objects.size(); i++)
    {
        m_objects[i]->baseUpdate(deltaTime);
    }
    Update(deltaTime);
    levelCamera->Update(deltaTime);
}

void Level::baseDraw()
{
    for (int i = 0; i < m_objects.size(); i++)
    {
        m_objects[i]->baseDraw();
    }
    Draw();
    levelCamera->Draw();
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
