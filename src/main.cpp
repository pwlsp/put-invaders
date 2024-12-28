#include "../include/define_include.h"
#include "../include/config.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "PUT Invaders", sf::Style::Close);

  
    //std::vector<Enemy> enemies; 

    std::vector<int> enemySizes = { 30,40,50 };

    std::chrono::microseconds lag(0);
    std::chrono::steady_clock::time_point previousTime;
    previousTime  = std::chrono::steady_clock::now();

    std::random_device rd;  // Obtain a random seed from the hardware
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist1(5, SCREEN_WIDTH-5);
    std::uniform_int_distribution<> dist2(0, enemySizes.size()-1);
    

    Spaceship spaceship;
    //unsigned short randomPos, enemySize;
    Enemy enemy(gen, dist1, dist2, enemySizes);

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
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }
            }
            if (FRAME_DURATION > lag)
            {
                window.clear();
                spaceship.update();
                spaceship.draw(window);
                //wszystkie enemies musza byc zupsatowane
                //dodawane po pewnym okresie czasu
                enemy.update();
                /* if (enemies.size() < 5)
                 {*/
                enemy.draw(window);
                /*}*/

                window.display();
            }
        }
        
       
    }

    return 0;
}