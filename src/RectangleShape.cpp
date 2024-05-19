#include "RectangleShape.h"

RectangleShape::RectangleShape(const int& x, const int& y, const int& w, const int& h, SDL_Color color)
    : Shape{color},
      body{x, y, w, h}
{ }
RectangleShape::RectangleShape(SDL_Rect rect, SDL_Color color)
    : Shape{color},
      body{rect}
{ }

RectangleShape::~RectangleShape()
{ }

void RectangleShape::update(const int& deltaTime)
{ }

void RectangleShape::draw(SDL_Renderer*& renderer) const
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &body);
}