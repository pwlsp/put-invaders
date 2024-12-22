#include <SFML/Graphics.hpp>

#include "config.h"

class Spaceship
{
private:
    sf::Sprite sprite;
    sf::Texture texture;

    unsigned short x;
    unsigned short y;

public:
    Spaceship();
    void draw(sf::RenderWindow &window);
    void update();
    void spawn();
};