#pragma once

#include <SFML/Graphics.hpp>

#include "config.h"
#include "Bullet.h"

class Spaceship
{
protected:
    sf::Sprite sprite;
    sf::Texture texture;

    float x;
    float y;
    float speed;

    std::vector<Bullet> bullets;
    sf::Sprite bullet_sprite;
    sf::Texture bullet_texture;

    float bullet_speed = BULLET_SPEED;
    unsigned short bullet_cooldown = 0;
    unsigned short bullet_width = 6;
    unsigned short bullet_height = 18;

public:
    void draw(sf::RenderWindow &window);

    void deleteBullet(int i)
    {
        bullets.erase(bullets.begin() + i);
    }

    std::vector<Bullet> getBulletsPos()
    {
        return bullets;
    }

    sf::IntRect hitBox(int i)
    {
        return sf::IntRect(bullets[i].x, bullets[i].y, bullet_width, bullet_height);
    }
};