#include "../include/define_include.h"
#include "../include/config.h"
#include  "../include/Spaceship.h"
#include "../include/Enemy.h"
#include "../include/Player.h"

bool gameOver = 0;

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "PUT Invaders", sf::Style::Close);

  
    int frameCount = 0, spawnInterval = 2000;

    Player player;

    std::vector<Enemy> enemies; 

    std::vector<int> enemySizes = { 45, 50, 55, 60 };

    std::chrono::microseconds lag(0);
    std::chrono::steady_clock::time_point previousTime;
    previousTime  = std::chrono::steady_clock::now();

    std::random_device rd;  // Obtain a random seed from the hardware
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist1(60, SCREEN_WIDTH-60); // Distribution for enemies' positions
    std::uniform_int_distribution<> dist2(0, enemySizes.size()-1); // Distributions for enemies' sizes

    
    // Initalizing enemies
    sf::Texture enemy_texture;
    
    if (!enemy_texture.loadFromFile("res/enemies/cobble.png"))
    {
        std::cout << "File opening error\n";
    }

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
                if (frameCount % spawnInterval == 0)
                {
                    Enemy enemy(gen, dist1, dist2, enemySizes, enemy_texture);
                    enemies.push_back(enemy);
                }

                // Updating player and enemies
                player.update();
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

                window.clear();

                // Drawing the sprites on the screen
                player.draw(window);
                for (auto& enemy : enemies)
                {
                    enemy.draw(window);
                }
                window.display();
            }
        }
        
       
    }

    return 0;
}