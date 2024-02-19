#ifndef COMPONENT_H
#define COMPONENT_H


class Component
{
    public:
        Component();

        virtual void Start();
        virtual void Update(float deltaTime);
        virtual void Draw();

        void SetOwnerObject(class Object& _ownerobject) { ownerObject = ownerObject; }

    protected:
        class Object* ownerObject;
    private:
};

#endif