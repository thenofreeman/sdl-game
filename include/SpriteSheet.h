#pragma once

#include <string>

#include <SDL2/SDL.h>

#include "Texture.h"
#include "Vector.h"

class SpriteSheet
{
    public:
        SpriteSheet(std::string path, Vector2<int> dimensions);
        virtual ~SpriteSheet();

        void setDimensions(Vector2<int> newDimensions);
        Vector2<int> getDimensions() const;

        Texture* getTexture() const;

    public:

    private:

    private:
        Texture* texture;

        Vector2<int> dimensions;

    private:
        SpriteSheet() = delete;

};