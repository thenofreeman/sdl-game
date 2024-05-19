#include "Game.h"

#include "AssetManager.h"
#include "RectangleShape.h"
#include "LineShape.h"
#include "Color.h"
#include "View.h"

Game::Game()
    :   isRunning{true}
{ 
    // REFACTOR
    texture = nullptr;
    // ----
}

Game::~Game()
{ 
    // REFACTOR
    delete texture;
    // ----
}

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
	AssetManager assetManager = AssetManager::getInstance();
	texture = assetManager.load("res/foo.png");

	if (texture == nullptr)
	{
		std::cerr << "Initialization Issue!" << std::endl;
	}
}

void Game::shutdown()
{
	texture->free();
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

void Game::draw(SDL_Renderer*& renderer)
{
    static GlobalEnvironment& gEnvironment = GlobalEnvironment::getInstance();

	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);

	View view({10, 10, 100, 100}, texture);
	view.draw(renderer);

	SDL_Rect r = {0, 0, gEnvironment.windowWidth, gEnvironment.windowHeight};
	SDL_RenderSetViewport(renderer, &r);

	RectangleShape outlineRect({
		gEnvironment.windowWidth/6, 
		gEnvironment.windowHeight/6,
		gEnvironment.windowWidth*2/3, 
		gEnvironment.windowHeight*2/3
	}, Color::GREEN);
	outlineRect.draw(renderer);

	RectangleShape fillRect({
		gEnvironment.windowWidth/4, 
		gEnvironment.windowHeight/4,
		gEnvironment.windowWidth/2, 
		gEnvironment.windowHeight/2
	}, Color::RED);
	fillRect.draw(renderer);

	LineShape solidLine({ 
		0, gEnvironment.windowHeight/2
	}, { 
		gEnvironment.windowWidth, gEnvironment.windowHeight/2
	}, Color::BLUE);
	solidLine.draw(renderer);

	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, 0xFF);
	for(int i = 0; i < gEnvironment.windowHeight; i+=4)
		SDL_RenderDrawPoint(renderer, gEnvironment.windowWidth/2, i);

	SDL_RenderPresent(renderer);
}