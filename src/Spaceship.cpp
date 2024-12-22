#include <SFML/Graphics.hpp>
#include <iostream>

#include "../include/config.h"

#include "../include/Spaceship.h"

Spaceship::Spaceship()
{
    if (!texture.loadFromFile("../res/base-spaceship.png"))
    {
        std::cout << "File opening error\n";
    }

    sprite.setTexture(texture);
}

void Spaceship::draw(sf::RenderWindow &window)
{
    sprite.setPosition(x, y);
    sprite.setTextureRect(sf::IntRect(0, 0, SPACESHIP_SIZE, SPACESHIP_SIZE));

    window.draw(sprite);
}

void Spaceship::update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) == true)
    {
        x = std::max<int>(x - 1, 0);
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) == true)
    {
        x = std::min<int>(x + 1, SCREEN_WIDTH-SPACESHIP_SIZE);
    }
}

void Spaceship::spawn()
{
    x = (SCREEN_WIDTH - SPACESHIP_SIZE) / 2;
    y = SCREEN_HEIGHT - SPACESHIP_SIZE;
}