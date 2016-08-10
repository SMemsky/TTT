#pragma once

#include "Graphics.h"
#include "Interface.h"
#include "Engine.h"

class Game
{
public:
	Game();
	~Game();

	void init();
	int run();
private:
	void handleEvents();
	void tick(double deltaTime);
private:
	Graphics m_graphics;
	Interface m_interface;
	Engine m_engine;

	bool m_isRunning;
};
