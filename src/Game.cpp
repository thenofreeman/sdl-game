#include "Game.h"

// REFACTOR
#include <SDL2/SDL_image.h>

bool loadMedia(SDL_Texture*& texture)
{
	bool success = true;

	GlobalEnvironment& gEnvironment = GlobalEnvironment::getInstance();

	std::string image_uri = "res/texture.png";
	texture = IMG_LoadTexture(gEnvironment.renderer, image_uri.c_str());

	if (texture == nullptr)
	{
		std::cerr << "Unable to load texture image " << image_uri << "! SDL Error: " << SDL_GetError() << std::endl;
		success = false;
	}

	return success;
}
// ----



Game::Game()
    :   isRunning{true}
{ 
    // REFACTOR
    texture = nullptr;
    // ----
}

void Game::run()
{
    GlobalEnvironment& gEnvironment = GlobalEnvironment::getInstance();

    if (!loadMedia(texture))
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

	SDL_RenderClear(gEnvironment.renderer);
	SDL_RenderCopy(gEnvironment.renderer, texture, NULL, NULL);

	SDL_RenderPresent(gEnvironment.renderer);
}

void Game::shutdown()
{
    freeSurfaces();
}

// REFACTOR
void Game::freeSurfaces()
{
	SDL_DestroyTexture(texture);
	texture = nullptr;
}
// ----