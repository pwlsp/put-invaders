#include "../include/define_include.h"
#include "../include/config.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "PUT Invaders", sf::Style::Close);
    sf::CircleShape shape(100.f);
    // shape.setFillColor(sf::Color::Magenta);

    Spaceship spaceship;
    spaceship.spawn();

    while (window.isOpen())
    {
        // # Managing window closing
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        // window.draw(shape);
        spaceship.update();
        spaceship.draw(window);
        window.display();
    }

    return 0;
}