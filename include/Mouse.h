#pragma once

#include "Moving.h"
#include <SFML/Graphics.hpp>

class Mouse : public Moving{
public:
	Mouse(const sf::Vector2f&, const sf::Sprite&, const int&);
	void move() override;
	void draw() override;
	
	void handleCollision(GameObject&) override;
	void handleCollision(Mouse&) override;
	void handleCollision(Cat&) override;
	void handleCollision(Wall&) override;
	void handleCollision(Key&) override;
	void handleCollision(Door&) override;
	void handleCollision(Cheese&) override;
    void handleCollision(Reward&) override;

	int getTotalLives();
	int getTotalScore();

private:
	int m_lives;
	int m_score;
	int m_keys;
};