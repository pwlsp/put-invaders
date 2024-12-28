#include "../include/define_include.h"
#include "../include/config.h"

bool gameOver = 0;

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "PUT Invaders", sf::Style::Close);

  
    std::vector<Enemy> enemies; 

    std::vector<int> enemySizes = { 30,40,50 };

    std::chrono::microseconds lag(0);
    std::chrono::steady_clock::time_point previousTime;
    previousTime  = std::chrono::steady_clock::now();

    std::random_device rd;  // Obtain a random seed from the hardware
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist1(5, SCREEN_WIDTH-5); //distribution for enemies' positions
    std::uniform_int_distribution<> dist2(0, enemySizes.size()-1); //distributions for enemies' sizes
    

    Spaceship spaceship;
    //initalizing enemies
    for (int i = 0; i < 5; i++)
    {
        enemies.push_back(Enemy(gen, dist1, dist2, enemySizes));
    }

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
            //std::cout << "Frame rate\n";
            lag -= FRAME_DURATION;

            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed or gameOver)
                {
                    window.close();
                }
            }
            if (FRAME_DURATION > lag)
            {
                //updating spaceship and enemies
                spaceship.update();
                for (auto& enemy : enemies) {
                    enemy.update();
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