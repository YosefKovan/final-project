#include "GameObject.h"


GameObject::GameObject(const sf::Vector2f& location, const sf::Sprite& sprite, const int& objSize) 
	: m_sprite(sprite), m_isDisposed(false), m_objSize(objSize)
{
	m_sprite.setPosition(location);
}
//-------------------------------------------
bool GameObject::collision(const GameObject& obj) const{

	return m_sprite.getGlobalBounds().intersects(obj.m_sprite.getGlobalBounds());
}