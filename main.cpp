/*This source code copyrighted by Lazy Foo' Productions 2004-2024
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <iostream>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

enum KeyPressSurfaces
{
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};

bool init();
bool loadMedia();
void run();
void processEvents();
void update();
void draw();
void close();
SDL_Surface* loadSurface(std::string path);

SDL_Window* gWindow = nullptr;
SDL_Surface* gScreenSurface = nullptr;
SDL_Surface* gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];
SDL_Surface* gHelloWorld = nullptr;
SDL_Surface* gCurrentSurface = nullptr;

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
			run();
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

	std::string image_uri = "res/hello_world.bmp";
	gHelloWorld = SDL_LoadBMP(image_uri.c_str());

	if (gHelloWorld == nullptr)
	{
		std::cerr << "Unable to load image " << image_uri << "! SDL Error: " << SDL_GetError() << std::endl;
	}

	return success;
}

bool quit = false;

void run()
{
	while (!quit)
	{
		processEvents();
		update();
		draw();
	}
}

void processEvents()
{
	static SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			quit = true;
	}
}

void update()
{

}

void draw()
{
	SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);

	SDL_UpdateWindowSurface(gWindow);
}

void close()
{
	SDL_FreeSurface(gHelloWorld);
	gHelloWorld = nullptr;

	SDL_DestroyWindow(gWindow);
	gWindow = nullptr;

	SDL_Quit();
}

SDL_Surface* loadSurface(std::string path)
{
	SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
	if (loadedSurface == nullptr)
	{
		std::cerr << "Unable to load image " << path << "! SDL Error: " << SDL_GetError() << std::endl;
	}

	return loadedSurface;
}