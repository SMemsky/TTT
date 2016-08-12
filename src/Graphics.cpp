#include "Graphics.h"

#include <iostream>

#include <SFML/Window/VideoMode.hpp>
#include <SFML/Graphics/Rect.hpp>

Graphics::Graphics(sf::RenderWindow& window) :
	m_window(window),
	m_tileTexture(),
	m_background(),
	m_hash(),
	m_cross(),
	m_nought(),
	m_strike(),
	m_diagonalStrike(),
	m_grid({
		Cross, Nought, NoMarker,
		Nought, Cross, NoMarker,
		Nought, NoMarker, Cross
	}),
	m_strikeType(STRIKE_DIAGONAL_DOWN)
{}

Graphics::~Graphics()
{}

void Graphics::init()
{
	// TODO: Configs

	loadResources();
	createSprites();

	sf::VideoMode videoMode(480, 480);
	sf::String title("Tic-tac-toe");

	m_window.create(videoMode, title);
	m_window.setFramerateLimit(30); // Save up user's CPU time :dark_moon:
}

void Graphics::draw()
{
	m_window.draw(m_background);
	m_window.draw(m_hash);

	for (unsigned y = 0; y < 3; ++y)
	{
		for (unsigned x = 0; x < 3; ++x)
		{
			switch (m_grid[x + y * 3])
			{
				case Cross:
				{
					m_cross.setPosition(160.0f * x, 160.0f * y);
					m_window.draw(m_cross);
					break;
				}
				case Nought:
				{
					m_nought.setPosition(160.0f * x, 160.0f * y);
					m_window.draw(m_nought);
					break;
				}
				default:
				{
					break;
				}
			}
		}
	}

	switch (m_strikeType)
	{
		case STRIKE_ROW_1:
		case STRIKE_ROW_2:
		case STRIKE_ROW_3:
		{
			m_strike.setPosition(0.0f, 160.0f * (m_strikeType - STRIKE_ROW_1));
			m_strike.setRotation(0.0f);
			m_window.draw(m_strike);
			break;
		}
		case STRIKE_COL_1:
		case STRIKE_COL_2:
		case STRIKE_COL_3:
		{
			m_strike.setPosition(160.0f * (m_strikeType - STRIKE_COL_1), 0.0f);
			m_strike.setRotation(90.0f);
			m_strike.move(160.0f, 0.0f);
			m_window.draw(m_strike);
			break;
		}
		case STRIKE_DIAGONAL_UP:
		{
			m_diagonalStrike.setRotation(0.0f);
			m_window.draw(m_diagonalStrike);
			break;
		}
		case STRIKE_DIAGONAL_DOWN:
		{
			m_diagonalStrike.setRotation(90.0f);
			m_window.draw(m_diagonalStrike);
			break;
		}
		default:
		{
			break;
		}
	}
}

void Graphics::loadResources()
{
	sf::Image tileImage;
	if (!tileImage.loadFromFile("../res/tiles.png"))
	{
		tileImage.create(128, 128, sf::Color(255, 20, 147));
	}

	m_tileTexture.loadFromImage(tileImage);
}

void Graphics::createSprites()
{
	m_background.setTexture(m_tileTexture);
	m_background.setTextureRect(sf::IntRect(0, 0, 480, 480));
	m_background.setPosition(0.0f, 0.0f);

	m_hash.setTexture(m_tileTexture);
	m_hash.setTextureRect(sf::IntRect(480, 0, 480, 480));
	m_hash.setPosition(0.0f, 0.0f);

	m_cross.setTexture(m_tileTexture);
	m_cross.setTextureRect(sf::IntRect(0, 480, 160, 160));
	m_nought.setTexture(m_tileTexture);
	m_nought.setTextureRect(sf::IntRect(160, 480, 160, 160));

	m_strike.setTexture(m_tileTexture);
	m_strike.setTextureRect(sf::IntRect(0, 640, 480, 160));
	m_diagonalStrike.setTexture(m_tileTexture);
	m_diagonalStrike.setTextureRect(sf::IntRect(480, 480, 480, 480));
	m_diagonalStrike.setOrigin(240.0f, 240.0f);
	m_diagonalStrike.setPosition(240.0f, 240.0f);
}
