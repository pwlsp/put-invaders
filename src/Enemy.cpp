#include <iostream>
#include <cmath>
#include <random>

#include "../include/Enemy.h"

extern bool gameOver;

Enemy::Enemy(std::mt19937& gen, std::uniform_int_distribution<>& dist1, std::uniform_int_distribution<>& dist2, std::vector<int> enemySizes)//unsigned short randomPos, unsigned short enemySize)
{
    //initial position
    x = dist1(gen);
    y = 0;
    //speed = ENEMY_SPEED;
    enemySize = enemySizes[dist2(gen)];
    //std::cout << enemySizes.size() << " " << enemySize << "\n";

    if (!texture.loadFromFile("r"))
    {
        std::cout << "File opening error\n";
    }

    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, ENEMY_SIZE, ENEMY_SIZE));
}

void Enemy::update()
{
    //std::cout << "ok\n";
   // x = x - 0.01;
    
    if (y + 0.1 < SCREEN_HEIGHT - enemySize) // - enemySize bez enemySize zniknie ca�e
    {
        std::cout << y << "\n";
        y = y + 0.1;
    }
    else {
        std::cout << "Game Over!\n";
        gameOver = 1;
    }
   //spada, 
   // //je�li dotrze na sam dol to game over?
    //jesli healbar == 0, to wtedy umiera i mo�e nowy by� wstawiony
    
}

void Enemy::draw(sf::RenderWindow& window)
{
    sprite.setPosition(x, y);
    window.draw(sprite);
}
