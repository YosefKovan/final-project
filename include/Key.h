#pragma once

#include "GameObject.h"

class Key : public GameObject {

public:
	Key(const sf::Vector2f& location, const sf::Sprite& sprite, const int& imgSize)
		: GameObject(location, sprite, imgSize) {}

	void handleCollision(GameObject& obj) override 
	{
		obj.handleCollision(*this);
	}

	void handleCollision(Mouse& obj) override 
	{
		m_isDisposed = true;
	}

	void handleCollision(Cat& obj) override {}
	void handleCollision(Wall& obj) override {}
	void handleCollision(Key& obj) override {}
	void handleCollision(Door& obj) override {}
	void handleCollision(Cheese& obj) override {}
	void handleCollision(Reward& obj) override {}

};