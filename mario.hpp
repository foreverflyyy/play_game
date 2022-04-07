#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

namespace nu {
    class Mario {
    public:
        Mario(int x, int y, int r);
        sf::Sprite* Get();
        void MoveRight();
        void MoveLeft();

    private:
        int m_x, m_y, m_r;
        sf::Texture m_texture;
        sf::Sprite* m_mario = nullptr;
    };
}