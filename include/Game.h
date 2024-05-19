#pragma once

#include <iostream>

#include <SDL2/SDL.h>

#include "GlobalEnvironment.h"
#include "Texture.h"
#include "Scene.h"
#include "MenuScene.h"

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
        void draw(SDL_Renderer*& renderer) const;

    private:
        bool isRunning;

        Scene* scene;

};