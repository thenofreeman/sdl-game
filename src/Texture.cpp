#include "Texture.h"

#include <SDL2/SDL_image.h>

#include "GlobalEnvironment.h"

Texture::Texture()
    : texture{nullptr},
      position{0, 0},
      dimensions{0, 0}
{ }

Texture::Texture(std::string path, Vector2<int> dimensions)
    : texture{nullptr},
      position{0, 0},
      dimensions{dimensions}
{ 
    load(path);
}

Texture::~Texture()
{ 
    free();
}

bool Texture::load(std::string path)
{ 
	bool success = true;

    free();

    SDL_Texture* newTexture = nullptr;

    GlobalEnvironment& gEnvironment = GlobalEnvironment::getInstance();

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (!loadedSurface)
	{
		std::cerr << "Unable to load texture image " << path << "! SDL Error: " << IMG_GetError() << std::endl;
		success = false;
	}
    else
    {
        SDL_Color& key = gEnvironment.keyingColor;
        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, key.r, key.g, key.b));

        newTexture = SDL_CreateTextureFromSurface(gEnvironment.renderer, loadedSurface);
        if (!newTexture)
        {
            std::cerr << "Unable to create texture from image " << path << "! SDL Error: " << SDL_GetError() << std::endl;
            success = false;
        }
        else
        {
            dimensions.x = loadedSurface->w;
            dimensions.y = loadedSurface->h;

            texture = newTexture;
        }

        SDL_FreeSurface(loadedSurface);
    }

	return success;
}

void Texture::update(const int& deltaTime) const
{ }

void Texture::draw(SDL_Renderer*& renderer) const
{ 
    SDL_Rect quad = { position.x, position.y, dimensions.x, dimensions.y };
    SDL_RenderCopy(renderer, texture, NULL, &quad);
}

void Texture::draw(SDL_Renderer*& renderer, const SDL_Rect& clipping) const
{ 
    SDL_Rect quad = { 
        position.x, 
        position.y, 
        clipping.w, 
        clipping.h 
    };

    SDL_RenderCopy(renderer, texture, &clipping, &quad);
}

void Texture::setPosition(Vector2<int> newPosition)
{ 
    position = newPosition;
}

void Texture::setDimensions(Vector2<int> newDimensions)
{ 
    dimensions = newDimensions;
}

void Texture::setColor(const SDL_Color& color)
{
    SDL_SetTextureColorMod(texture, color.r, color.g, color.b);
}

Vector2<int> Texture::getPosition() const
{ 
    return position;
}

Vector2<int> Texture::getDimensions() const
{ 
    return dimensions;
}

void Texture::free()
{ 
    if (texture)
    {
        SDL_DestroyTexture(texture);

        texture = nullptr;
        dimensions.x = 0;
        dimensions.y = 0;
    }
}