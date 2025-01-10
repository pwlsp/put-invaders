#include <iostream>
#include <cmath>
#include <random>

#include "../include/Enemy.h"
#include "../include/Spaceship.h"
#include "../include/Bullet.h"

extern bool gameOver;

std::random_device rd;  // Obtain a random seed from the hardware
std::mt19937 gen(rd());
std::uniform_real_distribution<> dist1(60, SCREEN_WIDTH-60); // Distribution for enemies' positions

// for random size, square, non-shooting enemies (slow rocks)
Enemy::Enemy(std::vector<int> enemySizes, float speed, std::uniform_int_distribution<>& dist2, sf::Texture &texture) : speed(speed)//unsigned short randomPos, unsigned short enemySize)
{
    enemyWidth = enemySizes[dist2(gen)];
    enemyHeight = enemyWidth;

    x = dist1(gen);
    y = -enemyHeight;

    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, enemyWidth, enemyHeight));
}
// for fixed size, non-shooting enemies (fast comets)
Enemy::Enemy(int enemyWidth, int enemyHeight, float speed ,sf::Texture &texture) : enemyWidth(enemyWidth), enemyHeight(enemyHeight), speed(speed)
{
    x = dist1(gen);
    y = -enemyHeight;

    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, enemyWidth, enemyHeight));
}

bool Enemy::update(Spaceship& spaceship)
{
    if (y + 0.1 < SCREEN_HEIGHT - enemyHeight) 
    {
        y = y + speed;
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

