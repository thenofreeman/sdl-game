#include "Game.h"

// REFACTOR
SDL_Surface* loadSurface(std::string path)
{
	SDL_Surface* optimizedSurface = nullptr;

	SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
	if (loadedSurface == nullptr)
	{
		std::cerr << "Unable to load image " << path << "! SDL Error: " << SDL_GetError() << std::endl;
	}
	else 
	{
		GlobalEnvironment& gEnvironment = GlobalEnvironment::getInstance();

		optimizedSurface = SDL_ConvertSurface(loadedSurface, gEnvironment.screen->format, 0);
		if (optimizedSurface == nullptr)
		{
			std::cerr << "Unable to optimize image " << path << "! SDL Error: " << SDL_GetError() << std::endl;
		}

		SDL_FreeSurface(loadedSurface);
	}

	return optimizedSurface;
}

bool loadMedia(SDL_Surface*& surface)
{
	bool success = true;

	std::string image_uri = "res/hello_world.bmp";
	surface = loadSurface(image_uri);

	if (surface == nullptr)
	{
		std::cerr << "Unable to load image " << image_uri << "! SDL Error: " << SDL_GetError() << std::endl;
		success = false;
	}

	return success;
}
// ----



Game::Game()
    :   isRunning{true}
{ 
    // REFACTOR
    gCurrentSurface = nullptr;
    // ----
}

void Game::run()
{
    GlobalEnvironment& gEnvironment = GlobalEnvironment::getInstance();

    if (!loadMedia(gCurrentSurface))
    {
        std::cerr << "Failed to load media!" << std::endl;
    }
    else
    {
        int deltaTime = 0;
        while (isRunning)
        {
            processEvents();
            update(deltaTime);
            draw(gEnvironment.window);
        }
    }
}

void Game::processEvents()
{
	static SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			isRunning = false;
	}
}

void Game::update(const int& deltaTime)
{ }

void Game::draw(SDL_Window*& window)
{
    static GlobalEnvironment& gEnvironment = GlobalEnvironment::getInstance();

	SDL_Rect stretchRect;
	stretchRect.x = 0;
	stretchRect.y = 0;
	stretchRect.w = gEnvironment.windowWidth;
	stretchRect.h = gEnvironment.windowHeight;
	SDL_BlitSurface(gCurrentSurface, NULL, gEnvironment.screen, &stretchRect);

	SDL_UpdateWindowSurface(window);
}

void Game::shutdown()
{
    freeSurfaces();
}

// REFACTOR
void Game::freeSurfaces()
{
	SDL_FreeSurface(gCurrentSurface);
	gCurrentSurface = nullptr;
}
// ----