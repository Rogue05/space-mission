#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <AstronomicalObject.hpp>

AstronomicalObject planet;
AstronomicalObject moon;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    
    planet.pos(sf::Vector2f(100,100));
    planet.set_radius(50.0);
    planet.set_color(sf::Color(100, 250, 50));

    moon.set_radius(10.0);
    moon.set_color(sf::Color(250, 100, 50));
    moon.set_orbit(sf::Vector2f(20.0,0.0));
    planet.add_child(moon);

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