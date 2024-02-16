#include "GameObject.h"


GameObject::GameObject(const sf::Vector2f& location, sf::Sprite& sprite) 
	: m_sprite(sprite)
{
	m_sprite.setPosition(location);
}
//-------------------------------------------
bool GameObject::collision(const GameObject& obj) const{

	return m_sprite.getGlobalBounds().intersects(obj.m_sprite.getGlobalBounds());
}