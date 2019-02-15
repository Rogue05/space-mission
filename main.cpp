#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <CircleShapeNode.hpp>

CircleShapeNode mynode;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    
    mynode.set_radius(50.0);

    //sf::CircleShape shape(50.f);
    // set the shape color to green
    //shape.setFillColor(sf::Color(100, 250, 50));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        //window.draw(shape);
        mynode.draw(window,sf::Transform::Identity);
        window.display();
    }
    return EXIT_SUCCESS;
}