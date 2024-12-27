#pragma once

#include <SFML/Graphics.hpp>

#include "config.h"

class Bullet
{
public:
    float x;
    float y;
    Bullet(float set_x, float set_y){
        x = set_x;
        y = set_y;
    }
};