#pragma once

#include <iostream>

#include <SDL2/SDL.h>

#include "GlobalEnvironment.h"

class Game
{
    public:
        Game();
        virtual ~Game() { }

        void run();
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
        SDL_Texture* texture;
        // ----

};