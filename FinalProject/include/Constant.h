#pragma once

#include <SFML/Graphics.hpp>

const float SIZE = 70;

const int LIVES = 5;

const unsigned int WINDOW_WIDTH = sf::VideoMode::getDesktopMode().width;
const unsigned int WINDOW_HEIGHT = sf::VideoMode::getDesktopMode().height;

const int UP = 79;
const int DOWN = 76;
const int RIGHT = 78;
const int LEFT = 77;
const int STAND = 75;

const char DIGGER = '/';
const char MONSTER = '!';
const char DIAMOND = 'D';
const char WALL = '#';
const char STONE = '@';
const char GIFT = '+';

const float GIFT_WIDTH = 373 / 0.9;
const float GIFT_HEIGHT = 439 / 0.9;

const float DIAMOND_WIDTH = 602;
const float DIAMOND_HEIGHT = 398 / 0.7;

const float WALL_WIDTH = 640;
const float WALL_HEIGHT = 416;

const float STONE_WIDTH = 1132 / 0.9;
const float STONE_HEIGHT = 808 / 0.9;

const float DIGGER_WIDTH = 238 / 0.8;
const float DIGGER_HEIGHT = 219 / 0.8;
// int DIGGER_SIZE = 56;

const int MONSTER_WIDTH = 2400 / 0.7;
const int MONSTER_HEIGHT = 2227 / 0.7;

const float DIGGER_SPEED = 150;
const float REG_MONSTER_SPEED = 100;
const float SMART_MONSTER_SPEED = 70;

const int REG_MONSTER_STEPS = 10000;

const int STONE_GIFT = 5;
const int SCORE_GIFT = 50;
const float TIME_GIFT = 10;

const int LEVEL_SCORE = 20;
const int DIAMOND_SCORE = 15;