#include "Game.h"

#include <SFML/Window/Event.hpp>

#include "Engine.h"
#include "Graphics.h"

Game::Game() :
	m_isRunning(false),
	m_engine(new Engine()),
	m_window(),
	m_graphics(new Graphics(m_window))
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
			default:
			{
				break;
			}
		}
	}
}
