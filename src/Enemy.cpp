#include <iostream>
#include <cmath>

#include "../include/Enemy.h"

Enemy::Enemy()//unsigned short RANDOM_POS, unsigned short ENEMY_SIZE)
{
    x = 0;
    //x = (RANDOM_POS - ENEMY_SIZE) ; //tutaj gdzie sie pojawia
    y = 0;
    speed = SS_INITIAL_SPEED;

    if (!texture.loadFromFile("r"))
    {
        std::cout << "File opening error\n";
    }

    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, ENEMY_SIZE, ENEMY_SIZE));
}

void Enemy::update()
{
    std::cout << "ok\n";
   //spada

    
}

void Enemy::draw(sf::RenderWindow& window)
{
    sprite.setPosition(x, y);
    window.draw(sprite);
}
