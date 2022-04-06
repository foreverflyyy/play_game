#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>

namespace nu
{
	const float g = 9.8;

	class Mario
	{
	public:
        Mario(int x0, int y0, float r);
		~Mario();

		bool Setup();
		void Move();

		sf::Sprite* Get();
		int GetX();
		int GetY();
		float GetR();
	private:
		int m_x, m_y, m_x0, m_y0;
		float m_r;

		sf::Texture m_texture;
		sf::Sprite* m_mario = nullptr;
	};

}