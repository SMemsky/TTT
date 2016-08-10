#pragma once

#include "GameBoard.h"

class Game;

class Engine
{
public:
	Engine(Game* game);
	~Engine();

	void init();
	void tick(double deltaTime);
private:
	Game* m_game;

	GameBoard m_board;
};
