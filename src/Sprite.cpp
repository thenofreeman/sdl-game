#include "Sprite.h"

Sprite::Sprite(std::string path)
    : position{0, 0},
      dimensions{0, 0},
      texture{nullptr},
      clipping{0,0,0,0}
{ 
    AssetManager& assetManager = AssetManager::getInstance();

    texture = assetManager.loadTexture(path);
    texture->setPosition(position);
    clipping = { texture->getPosition().x, texture->getPosition().y, texture->getDimensions().x, texture->getDimensions().y };

    dimensions = texture->getDimensions();
}

Sprite::Sprite(Texture* texture, const SDL_Rect& clipping)
    : position{0, 0},
      dimensions{0, 0},
      texture{texture},
      clipping{clipping}
{
    texture->setPosition(position);
}

Sprite::~Sprite()
{
    delete texture;
    texture = nullptr;
}

void Sprite::update(const int& deltaTime) const
{}

void Sprite::draw(SDL_Renderer*& renderer) const
{
    texture->draw(renderer, clipping);
}

void Sprite::setPosition(Vector2<int> newPosition)
{
    position = newPosition;
    texture->setPosition(newPosition);
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