#include "GlobalEnvironment.h"

#include <SDL2/SDL_image.h>

GlobalEnvironment::GlobalEnvironment() 
    :   window{nullptr},
        windowHeight{480},
        windowWidth{640},
        screen{nullptr},
        renderer{nullptr},
        title{"Default Title"},
		keyingColor{Color::CYAN}
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
		else
		{
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if (renderer == nullptr)
			{
				std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
				success = false;
			}
			else 
			{
				SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
					success = false;
				}
				else // if (window) 
				{
					screen = SDL_GetWindowSurface(window);
				}

			}
		}

	}

	return success;
}

bool GlobalEnvironment::shutdown()
{
    // always true... shouldn't be.
    bool success = true;

	SDL_DestroyRenderer(renderer);
	renderer = nullptr;
	SDL_DestroyWindow(window);
	window = nullptr;

	IMG_Quit();
	SDL_Quit();

    return success;
}