#pragma once

#include <stack>

#include <SDL2/SDL.h>

#include "Action.h"
#include "InputHandler.h"

class Scene
{
    public:
        virtual ~Scene() { }

        virtual void initialize() = 0;
        virtual void shutdown() = 0;

        virtual bool processEvents(const SDL_Event& event) = 0;
        virtual void update(const int& deltaTime) = 0;
        virtual void draw(SDL_Renderer*& renderer) const = 0;

    public:

    protected:
        Scene() { }

    protected:
        InputHandler inputHandler;

        std::stack<Action*> actionStack;

};