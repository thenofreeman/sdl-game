#pragma once

#include <string>

#include <SDL2/SDL.h>

#include "Vector.h"

class Texture
{
    public:
        Texture();
        Texture(std::string path, Vector2<int> dimensions);
        virtual ~Texture();

        bool load(std::string path);

        void update(const int& deltaTime) const;
        void draw(SDL_Renderer*& renderer) const;
        void draw(SDL_Renderer*& renderer, const SDL_Rect& clipping) const;

        void setPosition(Vector2<int> newPosition);
        void setDimensions(Vector2<int> newDimensions);
        void setColor(const SDL_Color& color);
        void setBlendMode(const SDL_BlendMode& blending);
        void setTransparency(const Uint8& alpha);

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