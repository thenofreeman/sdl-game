#include "SpriteSheet.h"

SpriteSheet::SpriteSheet(std::string path, Vector2<int> dimensions)
    : dimensions{dimensions},
      texture{new Texture(path, dimensions)}
{ }

SpriteSheet::~SpriteSheet()
{ 
    delete texture;
    texture = nullptr;
}

void SpriteSheet::setDimensions(Vector2<int> newDimensions)
{ 
    dimensions = newDimensions;
}

Vector2<int> SpriteSheet::getDimensions() const
{ 
    return dimensions;
}

Texture* SpriteSheet::getTexture() const
{
    return texture;
}