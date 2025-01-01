#pragma once

#include <SFML/Graphics.hpp>

#include "config.h"
#include "Weaponry.h"
#include "Bullet.h"

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

    std::vector<Bullet> getBulletsPos()
    {
        return weaponry.bullets;
    }

    sf::IntRect hitBox(int i)
    {
        return sf::IntRect(weaponry.bullets[i].x, weaponry.bullets[i].y, weaponry.bullet_width, weaponry.bullet_height);
    }
};