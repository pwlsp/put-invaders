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
    //float speed;
    int enemySize;
    

public:
    bool visibility;
    Enemy(std::mt19937& gen, std::uniform_real_distribution<>& dist1, std::uniform_int_distribution<>& dist2, std::vector<int> enemySizes, sf::Texture &texture);//unsigned short randomPos, unsigned short enemySize);
    void draw(sf::RenderWindow &window);
    void update(Spaceship& spaceship);

    sf::IntRect hitBox()
    //sf::RectangleShape hitBox()
    {
        /*sf::IntRect r1(x, y, enemySize, enemySize);
        sf::RectangleShape rectangle(sf::Vector2f(r1.width+1, r1.height));
        rectangle.setPosition(static_cast<float>(r1.left), static_cast<float>(r1.top));
        rectangle.setFillColor(sf::Color::Red);

        std::cout << "Rectangle Position: " << r1.left << ", " << r1.top << std::endl;
        std::cout << "Rectangle Size: " << r1.width << " x " << r1.height << std::endl;*/

        return sf::IntRect(x, y, enemySize, enemySize);

    }
};