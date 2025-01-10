#pragma once

#include <SFML/Graphics.hpp>
#include <random>

#include "config.h"

static std::random_device rd;  // Obtain a random seed from the hardware
static std::mt19937 gen(rd());
static std::uniform_real_distribution<> dist1(60, SCREEN_WIDTH-60); // Distribution for enemies' positions

class Spaceship;

class Enemy
{
protected:
    sf::Sprite sprite;
    sf::Texture texture;
    float x;
    float y;
    float speed;

    int enemyWidth;
    int enemyHeight;
    

public:
    Enemy(std::vector<int> enemySizes, float speed, std::uniform_int_distribution<>& dist2, sf::Texture &texture);//unsigned short randomPos, unsigned short enemySize);
    Enemy(int enemyWidth, int enemyHeight, float speed, sf::Texture &texture);
    Enemy();
    virtual void draw(sf::RenderWindow &window);
    bool update(Spaceship& spaceship);

    sf::IntRect hitBox()
    {
        return sf::IntRect(x, y, enemyWidth, enemyHeight);

    }
};