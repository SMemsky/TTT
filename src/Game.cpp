#include "Game.h"

#include <SFML/Window/Event.hpp>

#include "Engine.h"
#include "Graphics.h"
#include "EWin.h"

Game::Game() :
	m_isRunning(false),
	m_engine(new Engine()),
	m_window(),
	m_graphics(new Graphics(m_window)),
	m_mousePress{0, 0, false}
{}

Game::~Game()
{}

void Game::init()
{
	m_engine->init();

	m_graphics->init();
}

int Game::run()
{
	m_isRunning = true;
	while (m_isRunning)
	{
		pollEvents();

		update();

		m_graphics->draw();

		m_window.display();
	}

	return 0;
}

void Game::pollEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::Closed:
			{
				m_isRunning = false;
				break;
			}
			case sf::Event::MouseButtonPressed:
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					int index = pressToCell(event.mouseButton.x,
						event.mouseButton.y);
					unsigned x = index % 3;
					unsigned y = index / 3;

					m_mousePress.x = x;
					m_mousePress.y = y;
					m_mousePress.pressed = true;
				}
			}
			case sf::Event::MouseButtonReleased:
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					int index = pressToCell(event.mouseButton.x,
						event.mouseButton.y);
					unsigned x = index % 3;
					unsigned y = index / 3;

					if (m_mousePress.pressed &&
						m_mousePress.x == x &&
						m_mousePress.y == y)
					{
						if (m_engine->getWin() != WIN_NONE)
						{
							m_engine->startNewGame();
						}
						else
						{
							m_engine->onCellPress(x, y);
						}
						m_mousePress.pressed = false;
					}
				}
			}
			default:
			{
				break;
			}
		}
	}
}

void Game::update() const
{
	for (unsigned y = 0; y < 3; ++y)
	{
		for (unsigned x = 0; x < 3; ++x)
		{
			m_graphics->setGridMarker(x, y, m_engine->getCellValue(x, y));
		}
	}

	m_graphics->setWin(m_engine->getWin());
}

int Game::pressToCell(int x, int y) const
{
	unsigned cellSizeX = m_window.getSize().x / 3;
	unsigned cellSizeY = m_window.getSize().y / 3;

	int tmpX = x / cellSizeX;
	int tmpY = y / cellSizeY;

	return tmpX + tmpY * 3;
}
