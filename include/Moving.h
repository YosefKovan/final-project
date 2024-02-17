#pragma once

#include "Screen.h"
#include "GameObject.h"

class Moving : public GameObject {

public:
	Moving(const sf::Vector2f &location ,const sf::Sprite&, const int&);
	virtual void move() = 0;
	void resetPosition();
	bool catMouseCollision();

protected:	
	bool m_collision;
	sf::Vector2f m_prevPos;
	sf::Vector2f m_curPos;
	
};