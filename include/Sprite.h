#pragma once

#include <SDL2/SDL.h>

#include "SpriteSheet.h"
#include "Vector.h"

class Sprite
{
    public:
        Sprite(SpriteSheet* spriteSheet, const SDL_Rect& clipping);
        virtual ~Sprite();

        void update(const int& deltaTime) const;
        void draw(SDL_Renderer*& renderer) const;

        void setPosition(Vector2<int> newPosition);
        void setDimensions(Vector2<int> newDimensions);
        Vector2<int> getPosition() const;
        Vector2<int> getDimensions() const;

    public:

    private:

    private:
        SpriteSheet* sheet;
        SDL_Rect clipping;

        Vector2<int> position;
        Vector2<int> dimensions;

    private:
        Sprite() = delete;

};