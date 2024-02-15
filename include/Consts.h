
#include <string>

enum Arrows { None, Left, Right, Up, Down };

enum Characters {Mouse, Cat, Door, Wall, Key, Cheese, Reward};
//-----------------------------------

//std::string charactersArr[7] = { "Mouse","Cat","Door","Wall","Key","Cheese", "Reward"};

const char charactersArr[7] = { '%','^','D','#','F','*','$' };

const char WHITESPACE = ' ';
//-----------------------------------
const int TOTAL_IMAGES = 1, TILE_SIZE = 60;

//-----------------------------------

std::string imgStrArr[TOTAL_IMAGES] = { "Background.jpg" };
