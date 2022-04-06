#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

namespace nu {
    class Grib {
    public:
        Grib(int x, int y, int r, float speed);
        sf::Sprite* Get();
        void Move();
        void SetY(int y);
        int GetY();
        void SetVelocity(int speed);

    private:
        int m_x, m_y, m_r;
        float m_speed;
        sf::Texture m_texture;
        sf::Sprite* m_grib = nullptr;
    };
}