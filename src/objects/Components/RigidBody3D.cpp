#include "RigidBody3D.h"
#include "objects/Object.h"

RigidBody3D::RigidBody3D(/* args */)
{
}

RigidBody3D::~RigidBody3D()
{
}

void RigidBody3D::Start()
{
}

void RigidBody3D::Update(float deltaTime)
{
    gravityUpdate(deltaTime);
}

void RigidBody3D::Draw()
{
}

void RigidBody3D::gravityUpdate(float _deltaTime)
{
    if(is_gravity_enabled)
    {
        velocity.y(velocity.y() + (-gravity_value * _deltaTime));
        ownerObject->setPosition(ownerObject->getTransform().GetPosition() + velocity * _deltaTime);
    }
    
}
