#pragma once

#include <SDL2/SDL.h>

class Scene
{
    public:
        virtual ~Scene() { }

        virtual void initialize() = 0;
        virtual void shutdown() = 0;

        virtual void processEvents(SDL_Event& event) = 0;
        virtual void handleInput() = 0;
        virtual void update(const int& deltaTime) = 0;
        virtual void draw(SDL_Renderer*& renderer) const = 0;

    public:

    protected:
        Scene() { }

    protected:

};