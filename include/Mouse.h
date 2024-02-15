#include "Moving.h"

class Mouse : public Moving{
public:
	Mouse();
	void move() override;
	void draw();

private:
	int m_lives;
	int m_score;
};