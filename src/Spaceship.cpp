#include <iostream>
#include <cmath>

#include "../include/Spaceship.h"

void Spaceship::draw(sf::RenderWindow &window)
{
    
    sprite.setPosition(x, y);
    window.draw(sprite);

    for (Bullet &bullet : bullets)
    {
        bullet_sprite.setPosition(bullet.x, bullet.y);
        window.draw(bullet_sprite);
    }
    

    //std::cout << bullets.size() << std::endl;
}