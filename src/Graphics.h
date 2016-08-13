#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "EMarkers.h"
#include "EWin.h"

// Graphical representation

class Graphics
{
public:
	Graphics(sf::RenderWindow& window);
	~Graphics();

	void init();
	void draw();

	void setGridMarker(unsigned x, unsigned y, EMarkers marker);
	void setWin(EWin win);
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
	EWin m_win;
};
