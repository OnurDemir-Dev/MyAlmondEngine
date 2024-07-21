#ifndef RIGIDBODY_3D_H
#define RIGIDBODY_3D_H

#include "objects/Component.h"
#include "transforms/Vectors.h"

class RigidBody3D : public Component
{
private:
    
    bool is_gravity_enabled = true;
    float gravity_value = 9.8f;
    Vector3 velocity = Vector3(0.f, 0.f, 0.f);

    

    void gravityUpdate(float _deltaTime);
public:
    RigidBody3D(/* args */);
    ~RigidBody3D();

    virtual void Start() override;
    virtual void Update(float deltaTime) override;
    virtual void Draw() override;

    void SetGravityEnabled(bool _value) { is_gravity_enabled = _value ;}
    bool GetGravityEnabled() { return is_gravity_enabled ;}
};

#endif