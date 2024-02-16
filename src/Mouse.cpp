#include "Mouse.h"

Mouse::Mouse()
	: m_lives(0), m_score(0)
{}
//-------------------------------------------
void Mouse::move() {

	
}
//-------------------------------------------
void Mouse::draw() {

}
//-------------------------------------------
int Mouse::getTotalLives() {
	return m_lives;
}
//-------------------------------------------
int Mouse::getTotalScore() {
	return m_score;
}

//===================== handle collision functions =====================
//-------------------------------------------
void Mouse::handleCollision(GameObject& gameObj) {

	gameObj.handleCollision(*this);
}
//-------------------------------------------
void Mouse::handleCollision(Mouse&) {

	//do nothing
}
//-------------------------------------------
void Mouse::handleCollision(Cat& obj) {

	m_collision = true;
	m_lives--;
	
	if (m_lives == 0)
		isDisposed = true;

	obj.handleCollision(*this);
}
//-------------------------------------------
void Mouse::handleCollision(Wall& ) {

	//move the mouse back to where he was

}
//-------------------------------------------
void Mouse::handleCollision(Key& obj) {

	m_keys += 1;
	obj.handleCollision(*this)
}
//-------------------------------------------
void Mouse::handleCollision(Door& ) {

	if (m_keys > 1)
	{
		m_keys -= 1;
		handleCollision(*this);
		return;
	}

	//setPositionBack()

}
//-------------------------------------------
void Mouse::handleCollision(Cheese& ) {

	m_score + = 5; //change to the actual amount

}
//-------------------------------------------
void Mouse::handleCollision(Reward& ) {


}
