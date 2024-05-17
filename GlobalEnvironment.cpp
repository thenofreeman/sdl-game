#include "GlobalEnvironment.h"

GlobalEnvironment::GlobalEnvironment() 
    :   window{nullptr},
        windowHeight{480},
        windowWidth{640},
        screen{nullptr},
        title{"Default Title"}
{ }

bool GlobalEnvironment::initialize()
{
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
		success = false;
	}
	else
	{
		window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
		if(window == nullptr)
		{
			std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
			success = false;
		}

        if (window) 
        {
            screen = SDL_GetWindowSurface(window);
        }
	}

	return success;
}

bool GlobalEnvironment::shutdown()
{
    // always true... shouldn't be.
    bool success = true;

	SDL_DestroyWindow(window);
	window = nullptr;

	SDL_Quit();

    return success;
}