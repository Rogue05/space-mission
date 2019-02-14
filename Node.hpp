#pragma once

#include <SFML/Graphics.hpp>
#include <set>

class Node{
public:

    // ... functions to transform the node

    // ... functions to manage the node's children

    void draw(sf::RenderTarget& target, const sf::Transform& parentTransform) const
    {
        // combine the parent transform with the node's one
        sf::Transform combinedTransform = parentTransform * m_transform;

        // let the node draw itself
        onDraw(target, combinedTransform);

        // draw its children
        for (auto child:m_children)
            child->draw(target, combinedTransform);
    }

private:

    virtual void onDraw(sf::RenderTarget& target, const sf::Transform& transform) const = 0;

    sf::Transform m_transform;
    std::set<Node*> m_children;
};

// a simple derived class: a node that draws a sprite
class CircleShapeNode : public Node
{
public:

    // .. functions to define the sprite
    void set_radius(float radius){
        m_circle = sf::CircleShape(radius);
        m_circle.setFillColor(sf::Color(100, 250, 50));
    }

private:

    virtual void onDraw(sf::RenderTarget& target, const sf::Transform& transform) const
    {
        target.draw(m_circle, transform);
        // target.draw(*((sf::Sprite*)(this)), transform);
    }

    sf::CircleShape m_circle;
};
