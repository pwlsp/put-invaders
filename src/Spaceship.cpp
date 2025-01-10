#include <iostream>
#include <cmath>

#include "../include/Spaceship.h"

Spaceship::Spaceship()
{
}

void Spaceship::draw(sf::RenderWindow &window)
{
    
    sprite.setPosition(x, y);
    window.draw(sprite);

    for (Bullet &bullet : weaponry.bullets)
    {
        weaponry.bullet_sprite.setPosition(bullet.x, bullet.y);
        window.draw(weaponry.bullet_sprite);
    }
    

    //std::cout << weaponry.bullets.size() << std::endl;
}