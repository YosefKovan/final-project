#include "GameObject.h"

class GameObject {

protected:
  virtual void draw() = 0;
  sf::Vector2f m_location;

};