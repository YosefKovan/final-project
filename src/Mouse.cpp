#include "Mouse.h"

Mouse::Mouse(const sf::Vector2f& location, const sf::Sprite& sprite, const int& imgSize)
	: m_lives(0), m_score(0), Moving(location, sprite, imgSize)
{}
//-------------------------------------------
void Mouse::move() {
	switch (Screen.m_key)
	{
	case Left:
		sprite.move(-10, 0);
		break;
	case Right:
		sprite.move(10, 0);
		break;
	case Up:
		sprite.move(0, -10);
		break;
	case Down:
		sprite.move(0, 10);
		break;
	}
	
}
//-------------------------------------------
void Mouse::draw() {
	sf::Sprite sprite(*texture, sf::IntRect(10, 10, 10, 20));
	renderWindow.draw(sprite);
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
		m_isDisposed = true;

	obj.handleCollision(*this);
}
//-------------------------------------------
void Mouse::handleCollision(Wall& ) {

	//move the mouse back to where he was

}
//-------------------------------------------
void Mouse::handleCollision(Key& obj) {

	m_keys += 1;
	obj.handleCollision(*this);
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

	m_score += 5; //change to the actual amount

}
//-------------------------------------------
void Mouse::handleCollision(Reward& ) {


}
