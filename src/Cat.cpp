#include "Cat.h"

//===================== handle collision functions =====================
//-------------------------------------------
void Cat::handleCollision(GameObject& gameObj) {

	gameObj.handleCollision(*this);
}
//-------------------------------------------
void Cat::handleCollision(Mouse&) {

   //do nothing
}
//-------------------------------------------
void Cat::handleCollision(Cat&) {

  //do nothing
}
//-------------------------------------------
void Cat::handleCollision(Wall&) {

	//set back the positon to the previous position

}
//-------------------------------------------
void Cat::handleCollision(Key& obj) {

	//do nothing
}
//-------------------------------------------
void Cat::handleCollision(Door&) {

	//do nothing
}
//-------------------------------------------
void Cat::handleCollision(Cheese&) {

	//do nothing

}
//-------------------------------------------
void Cat::handleCollision(Reward&) {

	//do nothing
}
