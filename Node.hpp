#pragma once

#include <SFML/Graphics.hpp>
#include <set>

class Node{
public:

    // ... functions to transform the node
    void rotate(float angle){
        m_transform.rotate(angle);
    }

    void scale(float scale){
        m_transform.scale(scale,scale);
    }

    // ... functions to manage the node's children

    void update(float dt){
        onUpdate(dt);
        for(auto child:m_children)
            child->update(dt);
    }

    void draw(sf::RenderTarget& target, const sf::Transform& parentTransform) const
    {
        sf::Transform combinedTransform = parentTransform * m_transform;
        onDraw(target, combinedTransform);
        for (auto child:m_children)
            child->draw(target, combinedTransform);
    }

private:

    virtual void onDraw(sf::RenderTarget& target, const sf::Transform& transform) const = 0;
    virtual void onUpdate(float dt) = 0;

    sf::Transform m_transform;
    std::set<Node*> m_children;
};
