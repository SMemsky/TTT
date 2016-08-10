#include "Game.h"

#include <SFML/Window/Event.hpp>
#include <SFML/System/Clock.hpp>

// Note: rename gui to interface hence no gui system is used?

Game::Game() :
	m_graphics(),
	m_interface(this),
	m_engine(this),
	m_isRunning()
{}

Game::~Game()
{
	// I {} Scope-Bound RM :3
}

void Game::init()
{
	m_graphics.init();
	m_interface.init();
	m_engine.init();
}

// Move event handling into another class?
void Game::handleEvents()
{
	auto& window = m_graphics.getWindow();

	sf::Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::Closed:
			{
				m_isRunning = false;
				break;
			}
			case sf::Event::Resized:
			{
				m_graphics.onResize(event.size.width, event.size.height);
				break;
			}
			case sf::Event::MouseButtonPressed:
			{
				//m_interface.onMouseButtonPressed(event.mouseButton.button,
				//	event.mouseButton.x,
				//	event.mouseButton.y);
				break;
			}
			case sf::Event::MouseButtonReleased:
			{
				//m_interface.onMouseButtonReleased(event.mouseButton.button,
				//	event.mouseButton.x,
				//	event.mouseButton.y);
				break;
			}
			case sf::Event::MouseMoved:
			{
				//m_interface.onMouseMoved(event.mouseMove.x,
				//	event.mouseMove.y);
				break;
			}
			case sf::Event::MouseWheelScrolled:
			{
				//m_interface.onMouseScrolled(event.mouseWheelScroll.wheel,
				//	event.mouseWheelScroll.delta,
				//	event.mouseWheelScroll.x,
				//	event.mouseWheelScroll.y);
				break;
			}
			case sf::Event::KeyPressed:
			{
				//m_interface.onKeyPressed(event.key.code,
				//	event.key.alt,
				//	event.key.comtrol,
				//	event.key.shift,
				//	event.key.system);
				break;
			}
			case sf::Event::KeyReleased:
			{
				//m_interface.onKeyReleased(event.key.code,
				//	event.key.alt,
				//	event.key.comtrol,
				//	event.key.shift,
				//	event.key.system);
				break;
			}
			case sf::Event::TextEntered:
			{
				//m_interface.onTextEntered(event.text.unicode);
				break;
			}
			default:
			{
				/*
					Иногда хочется покодить еще, но пора уже, наконец, спать...
					00:58:00 10.08.2016
					Утро вечера не мудренее
					09:34:00 10.08.2016
				*/
				break;
			}
		}
	}
}

void Game::tick(double deltaTime)
{
	m_engine.tick(deltaTime);
	m_interface.tick(deltaTime);
}

int Game::run()
{
	sf::Clock playTime;
	sf::Time deltaTime;
	sf::Time frameStart;
	deltaTime = frameStart = sf::seconds(0);

	// Start game timer right before starting main loop, so the very first
	// frame will have minimal delta time
	playTime.restart();
	m_isRunning = true;
	while (m_isRunning)
	{
		// Calculate delta time based on time passed from last frame start
		deltaTime = playTime.getElapsedTime() - frameStart;
		frameStart = playTime.getElapsedTime();
		double delta = deltaTime.asSeconds();

		// Handle input
		handleEvents();

		// Update logic
		tick(delta);

		m_graphics.beginScene();
		// Make draws
		m_interface.draw();
		m_graphics.endScene();
	}
	return 0;
}