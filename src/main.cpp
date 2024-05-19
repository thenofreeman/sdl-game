#include <iostream>

#include <SDL2/SDL.h>

#include "Game.h"
#include "GlobalEnvironment.h"

int main(int argc, char* args[])
{
	GlobalEnvironment& gEnvironment = GlobalEnvironment::getInstance();

	if (!gEnvironment.initialize())
	{
		std::cerr << "Failed to initialize SDL Window!" << std::endl;
		return 1;
	}

	Game game;
	game.run();

	if (!gEnvironment.shutdown())
	{
		std::cerr << "Failed to shutdown SDL Window!" << std::endl;
		return 1;
	}

	return 0;
}