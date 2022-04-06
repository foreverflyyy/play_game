#include "mario.hpp"
#include <iostream>

namespace nu
{
	Mario::Mario(int x0, int y0, float r)
	{
		m_x0 = x0;
		m_y0 = y0;
		m_r = r;
	}

	bool Mario::Setup()
	{
		if (!m_texture.loadFromFile("img/mario.png"))
		{
			std::cout << "ERROR when loading mario.png" << std::endl;
			return false;
		}

		m_mario = new sf::Sprite();
		m_mario->setTexture(m_texture);
		m_mario->setOrigin(m_r, m_r);
		m_mario->setPosition(m_x, m_y);
        m_mario->setScale(0.5, 0.5);

		return true;
	}

    Mario::~Mario()
	{
		if (m_mario != nullptr)
			delete m_mario;
	}

	void Mario::Move()
	{

	}

	sf::Sprite* Mario::Get() { return m_mario; }

	int Mario::GetX() { return m_x; }
	int Mario::GetY() { return m_y; }
	float Mario::GetR() { return m_r; }
}