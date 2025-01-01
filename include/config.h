#pragma once

#include <chrono>

constexpr unsigned short SCREEN_WIDTH = 1100;
constexpr unsigned short SCREEN_HEIGHT = 850;
constexpr unsigned short SPACESHIP_SIZE = 50;
constexpr unsigned short SCREEN_MARGIN = 5;
constexpr unsigned short BULLET_COOLDOWN = 300;
// constexpr unsigned short BULLET_COOLDOWN = 60;

constexpr float SS_INITIAL_SPEED = 0.3;
constexpr float BULLET_SPEED = 0.4;

constexpr unsigned short ENEMY_SIZE = 50;
constexpr float ENEMY_SPEED = 0.4;

constexpr std::chrono::microseconds FRAME_DURATION(1666);