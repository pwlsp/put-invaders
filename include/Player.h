#pragma once

#include <SFML/Graphics.hpp>

#include "config.h"
#include "Weaponry.h"
#include "Bullet.h"
#include "Spaceship.h"

class Player : public Spaceship
{
public:
    Player();
    void draw(sf::RenderWindow &window);
    void update();
};