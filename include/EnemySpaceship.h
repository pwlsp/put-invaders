#pragma once

#include <SFML/Graphics.hpp>

#include "config.h"
#include "Bullet.h"
#include "Spaceship.h"
#include "Enemy.h"

class EnemySpaceship : public Spaceship, protected Enemy
{
private:
    // float x;
    // float y;
    // float speed;
public:
    EnemySpaceship(int enemyWidth, int enemyHeight, float speed, sf::Texture &enemy_spaceship_texture, sf::Texture &bullet_texture);
    bool update(Spaceship &spaceship);

    void draw(sf::RenderWindow &window)
    {

        Enemy::sprite.setPosition(Enemy::x, Enemy::y);
        window.draw(Enemy::sprite);

        for (Bullet &bullet : bullets)
        {
            bullet_sprite.setPosition(bullet.x, bullet.y);
            window.draw(bullet_sprite);
        }
    }
};