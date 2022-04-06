#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>

namespace nu
{
	class Grib
	{
	public:
        Grib(int x, int y, float r);
		~Grib();

		bool Setup();

		sf::Sprite* Get();
		int GetX();
		int GetY();
		float GetR();

	private:
		int m_x, m_y;
		float m_r;

		sf::Texture m_texture;
		sf::Sprite* m_grib = nullptr;
	};
}