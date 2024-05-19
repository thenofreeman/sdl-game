#include "Game.h"

// REFACTOR
#include <SDL2/SDL_image.h>

SDL_Texture* loadTexture(std::string path)
{
	SDL_Texture* newTexture = nullptr;

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == nullptr)
	{
		std::cerr << "Unable to load image " << path << "! SDL Error: " << IMG_GetError() << std::endl;
	}
	else
	{
		GlobalEnvironment& gEnvironment = GlobalEnvironment::getInstance();

		newTexture = SDL_CreateTextureFromSurface(gEnvironment.renderer, loadedSurface);
		if (newTexture == nullptr)
		{
			std::cerr << "Unable to load image " << path << "! SDL Error: " << IMG_GetError() << std::endl;
		}

		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}

bool loadMedia(SDL_Texture*& texture)
{
	bool success = true;

	std::string image_uri = "res/texture.png";
	texture = loadTexture(image_uri);

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