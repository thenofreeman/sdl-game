#pragma once

#include <SDL2/SDL.h>

class Shape
{
    protected:
        Shape(SDL_Color color);
        virtual ~Shape();

        virtual void update(const int& deltaTime) = 0;
        virtual void draw(SDL_Renderer*& renderer) const = 0;

    protected:
        SDL_Color color;

    public:
        Shape() = delete;

};