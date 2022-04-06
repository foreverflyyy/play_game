#include "grib.hpp"

namespace nu
{
	Grib::Grib(int x, int y, float r)
	{
		m_x = x;
		m_y = y;
		m_r = r;
	}

	bool Grib::Setup()
	{
		if (!m_texture.loadFromFile("img/grib.png"))
		{
			std::cout << "ERROR when loading grib.png" << std::endl;
			return false;
		}

		m_grib = new sf::Sprite();
		m_grib->setTexture(m_texture);
		m_grib->setOrigin(m_r, m_r);
		m_grib->setPosition(m_x, m_y);
		m_grib->setScale(0.15, 0.15);

		return true;
	}

    Grib::~Grib()
	{
		if (m_grib != nullptr)
			delete m_grib;
	}

	sf::Sprite* Grib::Get() { return m_grib; }

	int Grib::GetX() { return m_x; }
	int Grib::GetY() { return m_y; }
	float Grib::GetR() { return m_r; }
}