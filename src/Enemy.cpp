#include <iostream>
#include <cmath>
#include <random>

#include "../include/Enemy.h"
#include "../include/Spaceship.h"
#include "../include/Bullet.h"

extern bool gameOver;

Enemy::Enemy(std::mt19937& gen, std::uniform_real_distribution<>& dist1, std::uniform_int_distribution<>& dist2, std::vector<int> enemySizes, sf::Texture &texture)//unsigned short randomPos, unsigned short enemySize)
{
    enemySize = enemySizes[dist2(gen)];

    x = dist1(gen);
    y = -enemySize;

    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, enemySize, enemySize));
}

bool Enemy::update(Spaceship& spaceship)
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
    while (bullets.size() != 0 && i < bullets.size())
    {
        if (hitBox().intersects(spaceship.hitBox(i)))
        {
            spaceship.deleteBullet(i); 
            bullets.erase(bullets.begin() + i); 
            return false;
        }
        else
        {
            i++;
        }

    }
    return true;
}

void Enemy::draw(sf::RenderWindow &window)
{
    sprite.setPosition(x, y);
    window.draw(sprite);
}

