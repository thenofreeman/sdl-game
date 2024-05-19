#include "Shape.h"

#include <SDL2/SDL.h>

#include "Vector.h"

class LineShape : public Shape
{
    public:
        LineShape(Vector2<int> from, Vector2<int> to, SDL_Color color);
        virtual ~LineShape();

        virtual void update(const int& deltaTime);
        virtual void draw(SDL_Renderer*& renderer) const;
    
    public:

    private:

    private:
        Vector2<int> from;
        Vector2<int> to;

    public:
        LineShape() = delete;

};