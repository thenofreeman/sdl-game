#include "Sprite.h"

Sprite::Sprite(SpriteSheet* spriteSheet, const SDL_Rect& clipping)
    : position{0, 0},
      dimensions{0, 0},
      sheet{spriteSheet},
      clipping{clipping}
{ }

Sprite::~Sprite()
{
    delete sheet;
    sheet = nullptr;
}

void Sprite::update(const int& deltaTime) const
{}

void Sprite::draw(SDL_Renderer*& renderer) const
{
    sheet->getTexture()->draw(renderer, clipping);
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