#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "EMarkers.h"

// Graphical representation

class Graphics
{
	enum StrikeType
	{
		STRIKE_NONE = -1,
		STRIKE_ROW_1,
		STRIKE_ROW_2,
		STRIKE_ROW_3,
		STRIKE_COL_1,
		STRIKE_COL_2,
		STRIKE_COL_3,
		STRIKE_DIAGONAL_UP,
		STRIKE_DIAGONAL_DOWN
	};
public:
	Graphics(sf::RenderWindow& window);
	~Graphics();

	void init();
	void draw();
private:
	void loadResources();
	void createSprites();
private:
	sf::RenderWindow& m_window;

	sf::Texture m_tileTexture;
	
	sf::Sprite m_background;
	sf::Sprite m_hash;
	sf::Sprite m_cross;
	sf::Sprite m_nought;
	sf::Sprite m_strike;
	sf::Sprite m_diagonalStrike;

	std::vector<EMarkers> m_grid;
	StrikeType m_strikeType;
};
