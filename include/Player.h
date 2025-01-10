#pragma once

#include <SFML/Graphics.hpp>

#include "config.h"
#include "Bullet.h"
#include "Spaceship.h"
#include "EnemySpaceship.h"

class Player : public Spaceship
{
public:
    Player();
    void update(std::vector<EnemySpaceship> &enemyspaceships);
    
    sf::IntRect hitBox()
    {
        return sf::IntRect(x, y, SPACESHIP_SIZE, SPACESHIP_SIZE);
    }
};

