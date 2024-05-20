#include "View.h"

View::View(SDL_Rect rect, Sprite*& sprite)
    : body{rect},
      sprite{sprite}
{ }

View::~View()
{ }

void View::update(const int& deltaTime)
{ }

void View::draw(SDL_Renderer*& renderer) const
{
    SDL_RenderSetViewport(renderer, &body);
    sprite->draw(renderer);
}