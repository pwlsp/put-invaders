#include <iostream>
#include <cmath>

#include "../include/Spaceship.h"

Spaceship::Spaceship()
{
    x = (SCREEN_WIDTH - SPACESHIP_SIZE) / 2;
    y = SCREEN_HEIGHT - SPACESHIP_SIZE - 5.0;
    speed = SS_INITIAL_SPEED;

    // configuring spaceship's sprite:
    if (!texture.loadFromFile("res/spaceships/red.png"))
    {
        std::cout << "File opening error\n";
    }
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, SPACESHIP_SIZE, SPACESHIP_SIZE));

    // configuring bullet's sprite:
    if (!weaponry.bullet_texture.loadFromFile("res/bullets/green.png"))
    {
        std::cout << "File opening error\n";
    }
    weaponry.bullet_sprite.setTexture(weaponry.bullet_texture);
    weaponry.bullet_sprite.setTextureRect(sf::IntRect(0, 0, weaponry.bullet_width, weaponry.bullet_height));
}

void Spaceship::update()
{
    // Updating existing bullets
    weaponry.bullet_cooldown = std::max<short>(0, weaponry.bullet_cooldown - 1);
    for (Bullet &bullet : weaponry.bullets)
    {
        bullet.y -= weaponry.bullet_speed;
    }
    // Deleting bullets out of screen
    int iter = 0;
    while(iter < weaponry.bullets.size()){
        if(weaponry.bullets[iter].y <= -weaponry.bullet_height){
            weaponry.bullets.erase(weaponry.bullets.begin() + iter);
        }
        else{
            ++iter;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        x = std::max<float>(SCREEN_MARGIN, x - speed);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        x = std::min<float>(SCREEN_WIDTH - SPACESHIP_SIZE - SCREEN_MARGIN, x + speed);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && weaponry.bullet_cooldown == 0)
    {
        Bullet new_bullet(x + SPACESHIP_SIZE / 2 - weaponry.bullet_width / 2, y - weaponry.bullet_height);
        weaponry.bullets.push_back(new_bullet);
        weaponry.bullet_cooldown = BULLET_COOLDOWN;
    }
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
