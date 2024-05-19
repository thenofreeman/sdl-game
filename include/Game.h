#pragma once

#include <iostream>

#include <SDL2/SDL.h>

#include "GlobalEnvironment.h"
#include "Texture.h"

class Game
{
    public:
        Game();
        virtual ~Game();

        void run();

    private:
        void initialize();
        void shutdown();

        void processEvents();
        void update(const int& deltaTime);
        void draw(SDL_Renderer*& renderer);

    private:
        bool isRunning;


        // REFACTOR
        Texture* texture;
        // ----

};