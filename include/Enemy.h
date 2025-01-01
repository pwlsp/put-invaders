#pragma once

#include <SFML/Graphics.hpp>

#include "config.h"

class Enemy
{
private:
    sf::Sprite sprite;
    sf::Texture texture;

    float x;
    float y;
    //float speed;
    int enemySize;
    

public:
    bool visibility;
    Enemy(std::mt19937& gen, std::uniform_real_distribution<>& dist1, std::uniform_int_distribution<>& dist2, std::vector<int> enemySizes, sf::Texture &texture);//unsigned short randomPos, unsigned short enemySize);
    void draw(sf::RenderWindow &window);
    void update();
};