#include <grib.hpp>

namespace nu {
        Grib::Grib(int x, int y, int r, float speed){
            m_x = x;
            m_y = y;
            m_r = r;
            m_speed = speed;
            m_grib = new sf::Sprite();
            m_texture.loadFromFile("img/grib.png");
            m_grib->setTexture(m_texture);
//        if (!m_texture.loadFromFile("img/grib.png"))
//        {
//            std::cout << "ERROR when loading grib.png" << std::endl;
//            return false;
//        }
            m_grib->setOrigin(m_r, m_r);
            m_grib->setPosition(m_x, m_y);
            m_grib->setScale(0.15, 0.15);
        }
    void Grib::Move(){
        m_y += m_speed;
        m_grib->setPosition(m_x, m_y);
    }
    void Grib::SetY(int y){
        m_y = y;
        m_grib->setPosition(m_x, m_y);
    }
    int Grib::GetY() { return m_y; }
    void Grib::SetVelocity(int speed){
        m_speed = speed;
    }
    sf::Sprite* Grib::Get() { return m_grib; }
};