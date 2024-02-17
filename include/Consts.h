#pragma once

#include <SFML/Graphics.hpp>
#include <string>


enum Arrows { None, Left, Right, Up, Down };

enum Characters {MOUSE, CAT, DOOR, WALL, KEY, CHEESE, REWARD, WHITESPACE};
//-----------------------------------

//std::string charactersArr[7] = { "Mouse","Cat","Door","Wall","Key","Cheese", "Reward"};

const char charactersArr[7] = { '%','^','D','#','F','*','$' };

const char WHITESPACE = ' ';
//-----------------------------------

const int TOTAL_IMAGES = 1, TILE_SIZE = 60;

//-----------------------------------

std::string imgStrArr[TOTAL_IMAGES] = { "Background.jpg" };

//-----------------------------------

const auto move = sf::Vector2f(10, 10);
