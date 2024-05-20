#include "SpriteSheet.h"

SpriteSheet::SpriteSheet(std::string path)
    : dimensions{0, 0},
      texture{nullptr}
{
    AssetManager& assetManager = AssetManager::getInstance();

    texture = assetManager.loadTexture(path);

    dimensions = texture->getDimensions();
}

SpriteSheet::~SpriteSheet()
{ 
    delete texture;
    texture = nullptr;
}

Vector2<int> SpriteSheet::getDimensions() const
{ 
    return dimensions;
}

Sprite* SpriteSheet::createSprite(const SDL_Rect& clipping) const
{
    Sprite* newSprite = new Sprite(texture);
    newSprite->setClipping(clipping);
    newSprite->setDimensions({ clipping.w, clipping.h });

    return newSprite;
}

void SpriteSheet::setDimensions(Vector2<int> newDimensions)
{ 
    dimensions = newDimensions;
}