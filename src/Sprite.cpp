#include "Sprite.h"

Sprite::Sprite(std::string path)
    : position{0, 0},
      dimensions{0, 0},
      texture{nullptr}
{ 
    AssetManager& assetManager = AssetManager::getInstance();

    texture = assetManager.loadTexture(path);
    texture->setUseClipping(false);
    texture->setPosition(position);

    dimensions = texture->getDimensions();
}

// Sprite::Sprite(const SpriteSheet& spriteSheet, const SDL_Rect& clipping)
//     : position{0, 0},
//       dimensions{0, 0},
//       texture{nullptr}
// { 
//     texture = new Texture(spriteSheet->getTexture());
//     texture->setUseClipping(true);
//     texture->setPosition(position);
// }

Sprite::~Sprite()
{
    delete texture;
    texture = nullptr;
}

void Sprite::update(const int& deltaTime) const
{}

void Sprite::draw(SDL_Renderer*& renderer) const
{
    texture->draw(renderer);
}

void Sprite::setPosition(Vector2<int> newPosition)
{
    position = newPosition;
}

void Sprite::setDimensions(Vector2<int> newDimensions)
{
    dimensions = newDimensions;
}

Vector2<int> Sprite::getPosition() const
{
    return position;
}

Vector2<int> Sprite::getDimensions() const
{
    return dimensions;
}