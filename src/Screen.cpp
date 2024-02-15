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

    sf::Vector2f location;

    std::ifstream file;
    file.open(m_fileName);
    std::string line;

    if(file.is_open())
       file >> m_rows >> m_cols;

    while (file.is_open()) {
        std::getline(file, line);
        
        for (auto character : line)
            addObject(character, location);
           
    }
}
//-----------------------------------------------
void Screen::addObject(char object, sf::Vector2f &location) {

    switch (object) {
        case '%': 
            m_gameObjects.push_back(Mouse(location));
            break;
        case '^': 
            break;
        case 'D':
            break;
        case '#':
            break;
        case 'F':
            break;
        case '*': 
            break;
        case '$':
            break:
        case WHITESPACE:
            location.x + = TILE_SIZE;
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
        auto imgTextur = sf::Texture();
        imgTextur.loadFromFile(imgStr);
        m_textures.push_back(imgTextur);
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