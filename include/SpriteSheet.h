#pragma once

#include <string>

#include <SDL2/SDL.h>

#include "Sprite.h"
#include "Texture.h"
#include "Vector.h"

class SpriteSheet
{
    public:
        SpriteSheet(std::string path);
        virtual ~SpriteSheet();

        Vector2<int> getDimensions() const;

        Sprite* createSprite(const SDL_Rect& clipping) const;

    public:

    private:
        void setDimensions(Vector2<int> newDimensions);

    private:
        Texture* texture;

        Vector2<int> dimensions;

    private:
        SpriteSheet() = delete;

};