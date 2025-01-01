#include <iostream>
#include <cmath>
#include <random>

#include "../include/Enemy.h"

extern bool gameOver;

Enemy::Enemy(std::mt19937& gen, std::uniform_real_distribution<>& dist1, std::uniform_int_distribution<>& dist2, std::vector<int> enemySizes, sf::Texture &texture)//unsigned short randomPos, unsigned short enemySize)
{
    visibility = 1;
    x = dist1(gen);
    y = 0;
    enemySize = enemySizes[dist2(gen)];

    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, enemySize, enemySize));
}

void Enemy::update()
{
    if (y + 0.1 < SCREEN_HEIGHT - enemySize) // - enemySize bez enemySize zniknie ca�e
    {
        //std::cout << y << "\n";
        y = y + 0.1;
    }
    else {
        std::cout << "Game Over!\t" << gameOver << "\n";
        gameOver = 1;
    }
    // Jesli healthbar == 0, to wtedy umiera i mo�e nowy by� wstawiony
    
}

void Enemy::draw(sf::RenderWindow &window)
{
    sprite.setPosition(x, y);
    window.draw(sprite);
}
