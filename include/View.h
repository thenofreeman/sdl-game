#pragma once

#include <SDL2/SDL.h>

#include "Sprite.h"

class View
{
    public:
        View(SDL_Rect rect, Sprite*& sprite);
        virtual ~View();

        virtual void update(const int& deltaTime);
        virtual void draw(SDL_Renderer*& renderer) const;

    public:

    private:

    private:
        SDL_Rect body;
        Sprite* sprite;

};