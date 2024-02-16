#include <SFML/Graphics.hpp>
#include "Mouse.h"
#include "Cat.h
#include "Static"


class GameObject {

public:

	GameObject(const sf::Vector2f&, sf::Sprite&);
	
	bool collision(const GameObject&) const;
	virtual void handleCollision(GameObject&) = 0;
	virtual void handleCollision(Mouse&) = 0;
	virtual void handleCollision(Cat&) = 0;
	virtual void handleCollision(Door&) = 0;
	virtual void handleCollision(Wall&) = 0;
	virtual void handleCollision(Reward&) = 0;
	virtual void handleCollision(Cheese&) = 0;
	
	virtual void draw(sf::RenderWindow& window) = 0;

protected:
	sf::Vector2f m_startPos;
	int m_objSIze;
	bool m_isDisposed;

};