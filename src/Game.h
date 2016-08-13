#pragma once

#include <memory>

#include <SFML/Graphics/RenderWindow.hpp>

class Engine;
class Graphics;

class Game
{
public:
	Game();
	~Game();

	void init();
	int run();
private:
	void pollEvents();
	void update() const;
	int pressToCell(int x, int y) const;
private:
	bool m_isRunning;

	std::shared_ptr<Engine> m_engine;

	sf::RenderWindow m_window;
	std::shared_ptr<Graphics> m_graphics;

	struct
	{
		unsigned x;
		unsigned y;
		bool pressed;
	} m_mousePress;
};
