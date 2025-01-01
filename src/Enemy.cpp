#include <iostream>
#include <cmath>
#include <random>

#include "../include/Enemy.h"
#include "../include/Spaceship.h"
#include "../include/Bullet.h"

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

void Enemy::update(Spaceship& spaceship)
{
    if (y + 0.1 < SCREEN_HEIGHT - enemySize) 
    {
        y = y + 0.1;
    }
    else {
       std::cout << "Game Over!\t" << gameOver << "\n";
       exit(0);
    }

    std::vector<Bullet> bullets = spaceship.getBulletsPos();
    int i = 0; 
    while (i < bullets.size())
    {
        if (hitBox().intersects(spaceship.hitBox(i)))
        {
            
            std::cout << "bullet dead: " << i << "\n";
            exit(0);
            bullets.erase(bullets.begin() + i);
            
        }
        else
        {
            i++;
        }

   }
    
}

void Enemy::draw(sf::RenderWindow &window)
{
    sprite.setPosition(x, y);
    window.draw(sprite);
}

