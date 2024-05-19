#include "LineShape.h"

LineShape::LineShape(Vector2<int> from, Vector2<int> to, SDL_Color color)
    : Shape{color},
      from{from}, 
      to{to}
{ }

LineShape::~LineShape()
{ }

void LineShape::update(const int& deltaTime)
{ }

void LineShape::draw(SDL_Renderer*& renderer) const
{
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(renderer, from.x, from.y, to.x, to.y);
}