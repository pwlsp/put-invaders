#include <iostream>
#include <cmath>

#include "../include/Player.h"

Player::Player()
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
    if (!bullet_texture.loadFromFile("res/bullets/green.png"))
    {
        std::cout << "File opening error\n";
    }
    bullet_sprite.setTexture(bullet_texture);
    bullet_sprite.setTextureRect(sf::IntRect(0, 0, bullet_width, bullet_height));
}

void Player::update()
{
    // Updating existing bullets
    bullet_cooldown = std::max<short>(0, bullet_cooldown - 1);
    for (Bullet &bullet : bullets)
    {
        bullet.y -= bullet_speed;
    }
    // Deleting bullets out of screen
    int iter = 0;
    while(iter < bullets.size()){
        if(bullets[iter].y <= -bullet_height){
            bullets.erase(bullets.begin() + iter);
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

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && bullet_cooldown == 0)
    {
        Bullet new_bullet(x + SPACESHIP_SIZE / 2 - bullet_width / 2, y - bullet_height);
        bullets.push_back(new_bullet);
        bullet_cooldown = BULLET_COOLDOWN;
    }
}

