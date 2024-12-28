#include "../include/define_include.h"
#include "../include/config.h"

bool gameOver = 0;

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "PUT Invaders", sf::Style::Close);

  
    int frameCount = 0, spawnInterval = 2000, enemyCount = 1, activeEnemies = 0;

    std::vector<Enemy> enemies; 

    std::vector<int> enemySizes = { 30,40,50 };

    std::chrono::microseconds lag(0);
    std::chrono::steady_clock::time_point previousTime;
    previousTime  = std::chrono::steady_clock::now();

    std::random_device rd;  // Obtain a random seed from the hardware
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist1(10, SCREEN_WIDTH-10); //distribution for enemies' positions
    std::uniform_int_distribution<> dist2(0, enemySizes.size()-1); //distributions for enemies' sizes
    

    Spaceship spaceship;
    //initalizing enemies
    for (int i = 0; i < 5; i++)
    {
        enemies.push_back(Enemy(gen, dist1, dist2, enemySizes));
    }
    enemies[0].visibility = 1;

    // # The Game Loop
    while (window.isOpen())
    {
        //Making the game frame rate independent.
        std::chrono::microseconds deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - previousTime);
        lag += deltaTime;
        previousTime += deltaTime;
        
        // # Managing window closing
        sf::Event event;
        while (FRAME_DURATION <= lag)
        {
            std::cout << "Frame count\t " << frameCount << "\n";
            lag -= FRAME_DURATION;

            while (window.pollEvent(event))
            {
                std::cout << "check game over\t" << gameOver << "\n";
                if (event.type == sf::Event::Closed or gameOver)
                {
                    window.close();
                }

            }
            frameCount++;
            if (FRAME_DURATION > lag)
            {
                if (frameCount % spawnInterval == 0 && activeEnemies < enemies.size())
                {
                    std::cout << "NEW ENEMY APPEARED\n" << "\t" << enemyCount << " " << activeEnemies << "\n";
                    enemies[enemyCount].visibility = 1;
                    activeEnemies++;
                    if (enemyCount + 1 == enemies.size()) {
                        enemyCount = 0;
                    }
                    else
                    {
                        enemyCount++;
                    }
                }
                //updating spaceship and enemies
                spaceship.update();
                for (auto& enemy : enemies) {
                    if (enemy.visibility)
                    {
                        enemy.update();
                    }
                }

                window.clear();

                //drawing the sprites on the screen
                spaceship.draw(window);
                for (auto& enemy : enemies)
                {
                    if (enemy.visibility)
                    {
                        enemy.draw(window);
                    }
                }

                window.display();
            }
        }
        
       
    }

    return 0;
}