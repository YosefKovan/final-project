#include <SFML/Graphics.hpp>
#include <vector>
#include "Consts.h"


class Screen {

public:
	Screen();
	void playGmae();

private:
	void readImages();
	void getEvent();
	int getKey(const sf::Event& event) const;
	void readFromFile();
	
	int m_key;
	sf::RenderWindow m_window;
	std::vector<sf::Texture> m_textures;
	std::vector<sf::Sprite> m_sprites;
};