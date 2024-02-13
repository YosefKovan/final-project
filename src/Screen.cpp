#include "Screen.h"


Screen::Screen() 
    : m_window(sf::VideoMode(1400, 800), "SFML Window")
{}
//-----------------------------------------------
void readFromFile() {

    int rows, cols;
}
//-----------------------------------------------
void Screen::playGmae() {

    while (m_window.isOpen()) {
        getEvent();
    }
}
//-----------------------------------------------
void Screen::readImages() {

    for (int i = 0; i < TOTAL_IMAGES; i++) {
        auto img = sf::Texture();
        img.loadFromFile(imgStrArr[i]);
        m_textures.push_back(img);
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