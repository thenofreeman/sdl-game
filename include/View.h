#pragma once

#include <SDL2/SDL.h>

#include "Texture.h"

class View
{
    public:
        View(SDL_Rect rect, Texture*& texture);
        virtual ~View();

        virtual void update(const int& deltaTime);
        virtual void draw(SDL_Renderer*& renderer) const;

    public:

    private:

    private:
        SDL_Rect body;
        Texture* texture;

};