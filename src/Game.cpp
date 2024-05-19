#include "Game.h"

// REFACTOR
SDL_Surface* loadSurface(std::string path)
{
	SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
	if (loadedSurface == nullptr)
	{
		std::cerr << "Unable to load image " << path << "! SDL Error: " << SDL_GetError() << std::endl;
	}

	return loadedSurface;
}

bool loadMedia(SDL_Surface*& surface)
{
	bool success = true;

	std::string image_uri = "res/hello_world.bmp";
	surface = SDL_LoadBMP(image_uri.c_str());

	if (surface == nullptr)
	{
		std::cerr << "Unable to load image " << image_uri << "! SDL Error: " << SDL_GetError() << std::endl;
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

	SDL_BlitSurface(gCurrentSurface, NULL, gEnvironment.screen, NULL);

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