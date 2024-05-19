#include "View.h"

View::View(SDL_Rect rect, Texture*& texture)
    : body{rect},
      texture{texture}
{ }

View::~View()
{ }

void View::update(const int& deltaTime)
{ }

void View::draw(SDL_Renderer*& renderer) const
{
    SDL_RenderSetViewport(renderer, &body);
    texture->draw(renderer);
}