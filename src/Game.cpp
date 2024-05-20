#include "Game.h"

#include "AssetManager.h"

Game::Game()
    : isRunning{true},
	  scene{new MenuScene}
{ }

Game::~Game()
{ }

void Game::run()
{
    GlobalEnvironment& gEnvironment = GlobalEnvironment::getInstance();

	initialize();

	int deltaTime = 0;
	while (isRunning)
	{
		processEvents();
		update(deltaTime);
		draw(gEnvironment.renderer);
	}

	shutdown();
}

void Game::initialize()
{
	scene->initialize();
}

void Game::shutdown()
{ 
	scene->shutdown();
}

void Game::processEvents()
{
	static SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			isRunning = false;
		else 
			if (event.type == SDL_KEYDOWN)
				bool eventProcessed = scene->processEvents(event);
	}
}

void Game::update(const int& deltaTime)
{ 
	scene->update(deltaTime);
}

void Game::draw(SDL_Renderer*& renderer) const
{
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);

	scene->draw(renderer);

	SDL_RenderPresent(renderer);
}