#include "Moving.h"

Moving::Moving(const sf::Vector2f& location, const sf::Sprite& sprite, const int& imgSize)
	:m_prevPos(location), m_curPos(location), m_collision(false), 
	 GameObject(location, sprite, imgSize)
{}
//-------------------------------------------
void Moving::resetPosition() {

	m_prevPos = m_curPos = m_startPos;	
}
//-------------------------------------------
bool Moving::catMouseCollision() {
	
	if (m_collision) {
		m_collision = false;
		return true;
	}
	return false;
}