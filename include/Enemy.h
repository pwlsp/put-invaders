#pragma once

#include <SFML/Graphics.hpp>
#include <random>

#include "config.h"

class Spaceship;

class Enemy
{
private:
    sf::Sprite sprite;
    sf::Texture texture;

    float x;
    float y;
    float speed = 0.1;

    int enemyWidth;
    int enemyHeight;
    

public:
    Enemy(std::vector<int> enemySizes, float speed, std::uniform_int_distribution<>& dist2, sf::Texture &texture);//unsigned short randomPos, unsigned short enemySize);
    Enemy(int enemyWidth, int enemyHeight, float speed, sf::Texture &texture);
    void draw(sf::RenderWindow &window);
    bool update(Spaceship& spaceship);

    sf::IntRect hitBox()
    {
        return sf::IntRect(x, y, enemyWidth, enemyHeight);

    }
};