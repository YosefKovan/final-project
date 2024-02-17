#pragma once

#include <SFML/Graphics.hpp>
#include "Mouse.h"
#include "Cat.h"
#include "Static.h"
#include "Door.h"
#include "Wall.h"
#include "Cheese.h"
#include "Key.h"
#include "Reward.h"

class GameObject {

public:

	GameObject(const sf::Vector2f&, const sf::Sprite&, const int& objSize);
	
	bool collision(const GameObject&) const;
	virtual void handleCollision(GameObject&) = 0;
	virtual void handleCollision(Mouse&) = 0;
	virtual void handleCollision(Cat&) = 0;
	virtual void handleCollision(Door&) = 0;
	virtual void handleCollision(Wall&) = 0;
	virtual void handleCollision(Key&) = 0;
	virtual void handleCollision(Cheese&) = 0;
	virtual void handleCollision(Reward&) = 0;
	
	virtual void draw(sf::RenderWindow& window) = 0;

protected:	
	sf::Vector2f m_startPos;
	sf::Sprite m_sprite; //this might be changes to a rectangle.
	int m_objSize;
	bool m_isDisposed;

};