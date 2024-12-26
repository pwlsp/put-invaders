#include <iostream>
#include <cmath>

#include "../include/Spaceship.h"

Spaceship::Spaceship()
{
    x = (SCREEN_WIDTH - SPACESHIP_SIZE) / 2;
    y = SCREEN_HEIGHT - SPACESHIP_SIZE;
    speed = SS_INITIAL_SPEED;

    if (!texture.loadFromFile("res/spaceships/tie.png"))
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
        x = std::max<float>(x - speed, 0.0);
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) == true)
    {
        x = std::min<float>(x + speed, SCREEN_WIDTH-SPACESHIP_SIZE);
    }
}