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
    };