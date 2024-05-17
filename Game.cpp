#include "Game.h"

// REFACTOR
SDL_Surface* gCurrentSurface = nullptr;

SDL_Surface* loadSurface(std::string path)
{
	SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
	if (loadedSurface == nullptr)
	{
		std::cerr << "Unable to load image " << path << "! SDL Error: " << SDL_GetError() << std::endl;
	}

	return loadedSurface;
}

bool loadMedia()
{
	bool success = true;

	std::string image_uri = "res/hello_world.bmp";
	gCurrentSurface = SDL_LoadBMP(image_uri.c_str());

	if (gCurrentSurface == nullptr)
	{
		std::cerr << "Unable to load image " << image_uri << "! SDL Error: " << SDL_GetError() << std::endl;
	}

	return success;
}
// ----



Game::Game()
  : isRunning{true}
{ 
    // REFACTOR
    SDL_Surface* screenSurface = nullptr;
    // ----
}

void Game::run(SDL_Window* window)
{
    // REFACTOR
    if (window) 
        screenSurface = SDL_GetWindowSurface(window);
    // ----

    if (!loadMedia())
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
            draw(window);
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

void Game::draw(SDL_Window* window)
{
	SDL_BlitSurface(gCurrentSurface, NULL, screenSurface, NULL);

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