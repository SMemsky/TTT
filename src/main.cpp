#include <iostream>
#include <exception>

#include "Game.h"

int main(int argc, char* argv[])
{
	Game game;
	try
	{
		game.init();
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return 0;
	}

	return game.run();
}
