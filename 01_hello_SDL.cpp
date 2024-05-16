/*This source code copyrighted by Lazy Foo' Productions 2004-2024
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <iostream>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

bool init();
bool loadMedia();
void close();

SDL_Window* gWindow = nullptr;
SDL_Surface* gScreenSurface = nullptr;
SDL_Surface* gHelloWorld = nullptr;

int main(int argc, char* args[])
{
	if (!init())
	{
		std::cerr << "Failed to initialize!" << std::endl;
	}
	else
	{
		if (!loadMedia())
		{
			std::cerr << "Failed to load media!" << std::endl;
		}
		else
		{
			SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);

			SDL_UpdateWindowSurface(gWindow);

			// Temporary hack to keep the window open on all platforms
            SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
		}
	}

	close();

	return 0;
}

bool init()
{
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
		success = false;
	}
	else
	{
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if(gWindow == nullptr)
		{
			std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
			success = false;
		}
		else
		{
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}

	return success;
}


bool loadMedia()
{
	bool success = true;

	std::string image_uri = "hello_world.bmp";
	gHelloWorld = SDL_LoadBMP(image_uri.c_str());

	if (gHelloWorld == nullptr)
	{
		std::cerr << "Unable to load image " << image_uri << "! SDL Error: " << SDL_GetError() << std::endl;
	}

	return success;
}

void close()
{
	SDL_FreeSurface(gHelloWorld);
	gHelloWorld = nullptr;

	SDL_DestroyWindow(gWindow);
	gWindow = nullptr;

	SDL_Quit();
}