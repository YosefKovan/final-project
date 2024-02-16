#include "Static.h"


class Cheese : public Static {

	void handleCollision(GameObject&) override;
	void handleCollision(Mouse&) override;
	void handleCollision(Mouse&) override;
	void handleCollision(Cat&) override;
	void handleCollision(Wall&) override;
	void handleCollision(Key&) override;
	void handleCollision(Door&) override;
	void handleCollision(Cheese&) override;
	void handleCollision(Reward&) override;
	
};