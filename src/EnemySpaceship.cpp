#include <iostream>

#include "../include/EnemySpaceship.h"

extern bool gameOver;

EnemySpaceship::EnemySpaceship(int enemyWidth, int enemyHeight, float speed,sf::Texture &enemy_spaceship_texture, sf::Texture &bullet_texture)
{
    this->enemyWidth = enemyWidth;
    this->enemyHeight = enemyHeight;
    this->Enemy::speed = speed;

    Enemy::x = dist1(gen);
    Enemy::y = -enemyHeight;

    bullet_cooldown = 100;

    Enemy::sprite.setTexture(enemy_spaceship_texture);
    Enemy::sprite.setTextureRect(sf::IntRect(0, 0, enemyWidth, enemyHeight));

    Spaceship::bullet_sprite.setTexture(bullet_texture);
    Spaceship::bullet_sprite.setTextureRect(sf::IntRect(0, 0, bullet_width, bullet_height));
}

bool EnemySpaceship::update(Spaceship& spaceship)
{
    if (Enemy::y + Enemy::speed < SCREEN_HEIGHT - enemyHeight) 
    {
        Enemy::y = Enemy::y + Enemy::speed;
    }
    else {
       std::cout << "Game Over!\t" << gameOver << "\n";
       exit(0);
    }

    std::vector<Bullet> playerbullets = spaceship.getBulletsPos();
    int i = 0; 
    while (playerbullets.size() != 0 && i < playerbullets.size())
    {
        if (Enemy::hitBox().intersects(spaceship.hitBox(i)))
        {
            spaceship.deleteBullet(i); 
            playerbullets.erase(playerbullets.begin() + i); 
            return false;
        }
        else
        {
            i++;
        }
    }

    // Updating existing bullets
    bullet_cooldown = std::max<short>(0, bullet_cooldown - 1);
    for (Bullet &bullet : bullets)
    {
        bullet.y += bullet_speed;
    }
    // Deleting bullets out of screen
    int iter = 0;
    while(iter < bullets.size()){
        if(bullets[iter].y >= SCREEN_HEIGHT+bullet_height){
            bullets.erase(bullets.begin() + iter);
        }
        else{
            ++iter;
        }
    }

    if(bullet_cooldown == 0)
    {
        Bullet new_bullet(Enemy::x + SPACESHIP_SIZE / 2 - bullet_width / 2, Enemy::y + enemyHeight + bullet_height);
        bullets.push_back(new_bullet);
        bullet_cooldown = ENEMY_BULLET_COOLDOWN;
    }

    return true;
}

