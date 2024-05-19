#pragma once

#include <SDL2/SDL.h>

class View
{
    public:
        View(SDL_Rect rect, SDL_Texture*& texture);
        virtual ~View();

        virtual void update(const int& deltaTime);
        virtual void draw(SDL_Renderer*& renderer) const;

    public:

    private:

    private:
        SDL_Rect body;
        SDL_Texture* texture;

};