#include <SFML/Graphics.hpp>
#include <vector>
#include "Consts.h"
#include "GameObject.h"
#include "Mouse.h"


class Screen {

public:
	Screen();
	Screen() = default;
	void playGmae();

private:
	void readImages();
	void getEvent();
	int getKey(const sf::Event& event) const;
	void getFileName();
	void getLevelFromFile(std::string fileName);
	void addObject(char, sf::Vector2f&);
	
	int m_key;
	int m_rows, m_cols;
	std::string m_fileName;
	sf::RenderWindow m_window;
	std::vector<sf::Texture> m_textures;
	std::vector<sf::Sprite> m_sprites;
	std::vector<GameObject> m_gameObjects;

};