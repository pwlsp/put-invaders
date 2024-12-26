#include <SFML/Graphics.hpp>

#include "config.h"

class Spaceship
{
private:
    sf::Sprite sprite;
    sf::Texture texture;

    float x;
    float y;
    float speed;

public:
    Spaceship();
    void draw(sf::RenderWindow &window);
    void update();
};