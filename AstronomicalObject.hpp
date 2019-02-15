#pragma once

#include <CircleShapeNode.hpp>

class AstronomicalObject: public CircleShapeNode{
public:
    void set_angular_velocity(float vel){
        m_angular_velocity = vel;
    }
private:
    float m_angular_velocity;
    virtual void onUpdate(float dt) override{
        rotate(dt*m_angular_velocity);
    }
}