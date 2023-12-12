#ifndef BASELEVEL_H
#define BASELEVEL_H

#include "objects/Object.h"
#include "model/Mesh.h"
#include "camera/Camera.h"

#include <iostream>
#include <vector>


class Level
{
public:
    Level();

    virtual void Start();
    virtual void Update(float deltaTime);
    virtual void Draw();

    std::vector<Object*> GetCurrentObjects() { return m_objects;}
    Camera* GetLevelCamera() { return levelCamera ;}

    template <typename T>
    T* CreateObject(const char* objectName)
    {
        T* tempObject = new T();
        tempObject->SetName(objectName);
        tempObject->Start();
        m_objects.push_back(tempObject);
        return tempObject;
    }

protected:
    Camera* levelCamera;
private:
    std::vector<Object*> m_objects;
    

    void baseStart();
    void baseUpdate(float deltaTime);
    void baseDraw();
    friend class Engine;
};


#endif