#include "Shape.h"

#include <SDL2/SDL.h>

class RectangleShape : public Shape
{
    public:
        RectangleShape(const int& x, const int& y, const int& w, const int& h, SDL_Color color);
        RectangleShape(SDL_Rect rect, SDL_Color color);
        virtual ~RectangleShape();

        virtual void update(const int& deltaTime);
        virtual void draw(SDL_Renderer*& renderer) const;
    
    public:

    private:

    private:
        SDL_Rect body;

    public:
        RectangleShape() = delete;

};