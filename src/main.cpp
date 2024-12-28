#include "../include/define_include.h"
#include "../include/config.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "PUT Invaders", sf::Style::Close);

    Spaceship spaceship;
    Enemy enemy;
    //std::vector<Enemy> enemies; 

    // # The Game Loop
    while (window.isOpen())
    {
        // # Managing window closing
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
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

    return 0;
}