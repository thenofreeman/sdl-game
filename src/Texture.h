#pragma once

#include <string>

#include <SDL2/SDL.h>

#include "Vector.h"

class Texture
{
    public:
        Texture();
        virtual ~Texture();

        bool load(std::string path);

        void update(const int& deltaTime) const;
        void draw(SDL_Renderer*& renderer) const;

        void setPosition(Vector2<int> newPosition);
        void setDimensions(Vector2<int> newDimensions);
        Vector2<int> getPosition() const;
        Vector2<int> getDimensions() const;

        void free();

    public:

    private:

    private:
        SDL_Texture* texture;

        Vector2<int> position;
        Vector2<int> dimensions;

};