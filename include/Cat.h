#pragma once

#include "Moving.h"
#include <SFML/Graphics.hpp>

class Cat : public Moving{

public:
	void move(int direction) override;
	void draw(sf::RenderWindow& window) override;

	void handleCollision(GameObject&) override;
	void handleCollision(Mouse&) override;
	void handleCollision(Cat&) override;
	void handleCollision(Wall&) override;
	void handleCollision(Key&) override;
	void handleCollision(Door&) override;
	void handleCollision(Cheese&) override;
	void handleCollision(Reward&) override;

};