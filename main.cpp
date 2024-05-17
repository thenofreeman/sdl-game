#include <iostream>

#include <SDL2/SDL.h>

#include "Game.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

bool initializeSDL(SDL_Window* window);
void shutdownSDL(SDL_Window* window);

int main(int argc, char* args[])
{
	SDL_Window* window = nullptr;

	if (!initializeSDL(window))
	{
		std::cerr << "Failed to initialize SDL Window!" << std::endl;
	}
	else
	{
		Game game;
		game.run(window);

		game.shutdown();
	}

	shutdownSDL(window);

	return 0;
}

bool initializeSDL(SDL_Window* window)
{
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
		success = false;
	}
	else
	{
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if(window == nullptr)
		{
			std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
			success = false;
		}
	}

	return success;
}

void shutdownSDL(SDL_Window* window)
{
	SDL_DestroyWindow(window);
	window = nullptr;

	SDL_Quit();
}