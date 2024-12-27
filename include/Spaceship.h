#pragma once

#include <SFML/Graphics.hpp>

#include "config.h"
#include "Weaponry.h"

class Spaceship
{
private:
    sf::Sprite sprite;
    sf::Texture texture;

    float x;
    float y;
    float speed;

    Weaponry weaponry;

public:
    Spaceship();
    void draw(sf::RenderWindow &window);
    void update();
};