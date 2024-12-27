#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "config.h"
#include "Bullet.h"

class Weaponry
{
public:
    // They can (and must) be public, because weaponry object will be private :)
    std::vector<Bullet> bullets;
    sf::Sprite bullet_sprite;
    sf::Texture bullet_texture;

    float bullet_speed = BULLET_SPEED;
    unsigned short bullet_cooldown = 0;
    unsigned short bullet_width = 6;
    unsigned short bullet_height = 18;
};