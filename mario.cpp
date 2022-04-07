#include <mario.hpp>

namespace nu {
        Mario::Mario(int x, int y, int r){
            m_x = x;
            m_y = y;
            m_r = r;
            m_mario = new sf::Sprite();
            m_texture.loadFromFile("img/mario.png");
            m_mario->setTexture(m_texture);
//        if (!m_texture.loadFromFile("img/grib.png"))
//        {
//            std::cout << "ERROR when loading grib.png" << std::endl;
//            return false;
//        }
            m_mario->setOrigin(m_r, m_r);
            m_mario->setPosition(m_x, m_y);
            m_mario->setScale(0.5, 0.5);
        }
        sf::Sprite* Mario::Get() { return m_mario; }
    void Mario::MoveRight(){
        m_texture.loadFromFile("img/mario.png");
        m_mario->setTexture(m_texture);
        m_x += 10;
        m_mario->setPosition(m_x, m_y);
    }
    void Mario::MoveLeft(){
        m_texture.loadFromFile("img/marioLeft.png");
        m_mario->setTexture(m_texture);
        m_x -= 10;
        m_mario->setPosition(m_x, m_y);
    }
    void Mario::MoveUp(){
//        float y_new = m_y;
//        while(y_new < m_y + 30) {
//            y_new += 30 / 2;
//            m_mario->setPosition(m_x, y_new);
//        }
//        while(y_new > m_y) {
//            y_new -= 30 / 2;
//            m_mario->setPosition(m_x, y_new);
//        }

    }
    int Mario::GetX() { return m_x; }
    int Mario::GetY() { return m_y; }
    float Mario::GetR() { return m_r; }

};