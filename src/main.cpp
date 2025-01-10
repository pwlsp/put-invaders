#include "../include/define_include.h"
#include "../include/config.h"
#include  "../include/Spaceship.h"
#include "../include/Enemy.h"
#include "../include/Player.h"
#include "../include/EnemySpaceship.h"

bool gameOver = 0;

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "PUT Invaders", sf::Style::Close);
  
    int frameCount = 0, rockSpawnInterval = 2000, cometSpawnInterval = 5000, enemySpaceshipSpawnInterval = 4500;


    // Initalizing textures
    sf::Texture enemy_texture, comet_texture, enemy_spaceship_texture, enemy_bullet_texture;
    
    if (!enemy_texture.loadFromFile("res/enemies/cobble.png"))
    {
        std::cout << "File opening error\n";
    }
    
    if (!comet_texture.loadFromFile("res/enemies/comet.png"))
    {
        std::cout << "File opening error\n";
    }

    if (!enemy_spaceship_texture.loadFromFile("res/spaceships/tie.png"))
    {
        std::cout << "File opening error\n";
    }

    if (!enemy_bullet_texture.loadFromFile("res/bullets/red.png"))
    {
        std::cout << "File opening error\n";
    }

    // Initalizing player and enemies

    Player player;

    std::vector<Enemy> enemies; 

    std::vector<int> enemySizes = { 45, 50, 55, 60 };
    std::uniform_int_distribution<> dist2(0, enemySizes.size()-1); // Distributions for enemies' sizes

    std::vector<Enemy> comets;
    // (40, 120, comet_texture)

    std::vector<EnemySpaceship> enemyspaceships; 

    std::chrono::microseconds lag(0);
    std::chrono::steady_clock::time_point previousTime;
    previousTime  = std::chrono::steady_clock::now();



    int iterator;

    // The Game Loop
    while (window.isOpen())
    {
        // Making the game frame rate independent.
        std::chrono::microseconds deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - previousTime);
        lag += deltaTime;
        previousTime += deltaTime;
        
        // Managing window closing
        sf::Event event;
        while (FRAME_DURATION <= lag)
        {
            // std::cout << "Frame count\t " << frameCount << "\n";
            lag -= FRAME_DURATION;

            while (window.pollEvent(event))
            {
                //std::cout << "check game over\t" << gameOver << "\n";
                if (event.type == sf::Event::Closed or gameOver)
                {
                    window.close();
                }

            }
            frameCount++;
            if (FRAME_DURATION > lag)
            {
                if (frameCount % rockSpawnInterval == 0)
                {
                    Enemy enemy(enemySizes, 0.1, dist2, enemy_texture);
                    enemies.push_back(enemy);
                }

                if (frameCount % cometSpawnInterval == 0)
                {
                    Enemy comet(40, 120, 0.25, comet_texture);
                    enemies.push_back(comet);
                }

                if (frameCount % enemySpaceshipSpawnInterval == 0)
                {
                    EnemySpaceship enemyspaceship(50, 50, 0.1, enemy_spaceship_texture, enemy_bullet_texture);
                    enemyspaceships.push_back(enemyspaceship);
                }

                // Updating player and enemies
                player.update(enemyspaceships);
                
                iterator = 0;
                for (Enemy& enemy : enemies) {
                    
                    if (!enemy.update(player)) {
                        enemies.erase(enemies.begin() + iterator);
                    }
                    else
                    {
                        iterator++;
                    }
                }

                iterator = 0;
                for (Enemy& comet : comets) {
                    
                    if (!comet.update(player)) {
                        comets.erase(comets.begin() + iterator);
                    }
                    else
                    {
                        iterator++;
                    }
                }

                iterator = 0;
                for (EnemySpaceship& enemyspaceship : enemyspaceships) {
                    
                    if (!enemyspaceship.update(player)) {
                        enemyspaceships.erase(enemyspaceships.begin() + iterator);
                    }
                    else
                    {
                        iterator++;
                    }
                }

                window.clear();

                // Drawing the sprites on the screen
                player.draw(window);
                for (auto& enemy : enemies)
                {
                    enemy.draw(window);
                }
                for (auto& comet : comets)
                {
                    comet.draw(window);
                }
                for (auto& enemyspaceship : enemyspaceships)
                {
                    enemyspaceship.draw(window);
                }
                window.display();
            }
        }
        
       
    }

    return 0;
}