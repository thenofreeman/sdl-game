#pragma once

#include <iostream>

#include <SDL2/SDL.h>

class Game
{
    public:
        Game();
        virtual ~Game() { }

        void run(SDL_Window*& window);
        void shutdown();

    private:
        void processEvents();
        void update(const int& deltaTime);
        void draw(SDL_Window*& window);

        // REFACTOR
        void freeSurfaces();
        // ----

    private:
        bool isRunning;

        // REFACTOR
        SDL_Surface* screenSurface;
        SDL_Surface* gCurrentSurface;
        // ----

};