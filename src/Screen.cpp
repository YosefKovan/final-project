#include "Screen.h"
#include <fstream>
#include <iostream>


Screen::Screen() 
    : m_window(sf::VideoMode(1400, 800), "SFML Window"), 
      m_key(None), m_rows(0), m_cols(0)
{}
//-----------------------------------------------
void Screen::getFileName() {

    std::ifstream file; 
    file.open(m_fileName);
    
    while (file.is_open()) {
        
        std::string fileName;
        std::getline(file, fileName);
        getLevelFromFile(fileName);
    }
}
//-----------------------------------------------
void Screen::getLevelFromFile(std::string fileName) {

    sf::Vector2f location(0,0);

    std::ifstream file;
    file.open(m_fileName);
    std::string line;

    if(file.is_open())
       file >> m_rows >> m_cols;

    while (file.is_open()) {
        std::getline(file, line);

        for (auto character : line) {
            addObject(character, location); //for whitespace it will only increase the x.
            location.x += TILE_SIZE;
        }

        location.y += TILE_SIZE;      
    }
}

//-----------------------------------------------
void Screen::addObject(char object, sf::Vector2f &location) {

    switch (object) {
        case '%': 
            m_moving.push_back(std::make_unique<Mouse>(location));
            break;
        case '^': 
            m_moving.push_back(std::make_unique<Cat>(location));
            break;
        case 'D':
            m_static.push_back(std::make_unique<Door>(location));
            break;
        case '#':
            m_static.push_back(std::make_unique<Wall>(location));
            break;
        case 'F':
            m_static.push_back(std::make_unique<Key>(location));
            break;
        case '*': 
            m_static.push_back(std::make_unique<Cheese>(location));
            break;
        case '$':
            m_static.push_back(std::make_unique<Reward>(location));
            break;
    }
}
//-----------------------------------------------
void Screen::playGmae() {

    while (m_window.isOpen()) {
        getEvent();
    }
}
//-----------------------------------------------
void Screen::readImages() {

    for (auto imgStr : imgStrArr) {
        auto imgTexture = sf::Texture();
        imgTexture.loadFromFile(imgStr);
        m_textures.push_back(imgTexture);
    }


        
}
//-----------------------------------------------
void Screen::getEvent() {

   
    if (auto event = sf::Event{}; m_window.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                m_window.close();
                break;
            case sf::Event::KeyPressed:
                if (int key = getKey(event); key != None)
                    m_key = key;
                break;
            case sf::Event::KeyReleased:
                if (int key = getKey(event); key != None)
                    m_key = None; 
                break;

        }
    }

}
//-----------------------------------------------
int Screen::getKey(const sf::Event& event) const{

    if (event.key.code == sf::Keyboard::Left)
        return Left;
    else if (event.key.code == sf::Keyboard::Right)
        return Right;
    else if (event.key.code == sf::Keyboard::Up)
        return Up;
    else if (event.key.code == sf::Keyboard::Down)
        return Down;

    return None;
}