#include "../include/define_include.h"
#include "../include/config.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "PUT Invaders", sf::Style::Fullscreen);

    Spaceship spaceship;

    // # The Game Loop
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
        spaceship.update();
        spaceship.draw(window);

        // sf::Texture texture;
        // sf::Sprite siup;
        // siup.setTexture(texture);
        // siup.setTextureRect(sf::IntRect(0, 0, SPACESHIP_SIZE, SPACESHIP_SIZE));
        // window.draw(siup);

        window.display();
    }

    return 0;
}