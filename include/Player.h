#pragma once

#include <SFML/Graphics.hpp>

#include "config.h"
#include "Bullet.h"
#include "Spaceship.h"

class Player : public Spaceship
{
public:
    Player();
    void update();
};

