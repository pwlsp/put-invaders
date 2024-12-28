#pragma once

#include <SFML/Graphics.hpp>

#include "config.h"

class Enemy
{
private:
    sf::Sprite sprite;
    sf::Texture texture;

    float x;
    float y;
    float speed;

public:
    Enemy();//unsigned short RANDOM_POS, unsigned short ENEMY_SIZE);
    void draw(sf::RenderWindow& window);
    void update();
};