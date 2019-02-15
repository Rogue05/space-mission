#pragma once

#include <Node.hpp>

class CircleShapeNode : public Node
{
public:

    // .. functions to define the sprite
    void set_radius(float radius){
        m_circle = sf::CircleShape(radius);
        move(sf::Vector2f(-radius/2,-radius/2))
        // m_circle.setFillColor(sf::Color(100, 250, 50));
    }

    void set_color(sf::Color color){
        m_circle.setFillColor(color);
    }

private:

    virtual void onDraw(sf::RenderTarget& target, const sf::Transform& transform) const
    {
        target.draw(m_circle, transform);
        // target.draw(*((sf::Sprite*)(this)), transform);
    }

    virtual void onUpdate(float dt) override{
        // Not defined
    }

    sf::CircleShape m_circle;
};