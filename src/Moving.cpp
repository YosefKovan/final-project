#include "Moving.h"

Moving::Moving(const sf::Vector2f& location)
	:m_prevPos(location), m_curPos(location),
	 m_startPos(location), m_objSize(40), m_collision(false)
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