#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
#include <iostream>

namespace nu {
    class Mario {
    public:
        Mario(int x, int y, int r);
        sf::Sprite* Get();
        void MoveRight();
        void MoveLeft();
        void MoveUp();
        int GetX();
        int GetY();
        float GetR();
        void SetX(int x);

    private:
        int m_x, m_y, m_r;
        sf::Texture m_texture;
        sf::Sprite* m_mario = nullptr;
    };
}