#include "Screen.h"
#include "GameObject.h"

class Moving : public GameObject {

	virtual void move() = 0;
};