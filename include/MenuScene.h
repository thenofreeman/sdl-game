#pragma once

#include <SDL2/SDL.h>

#include "Action.h"
#include "Scene.h"
#include "SpriteSheet.h"
#include "Sprite.h"
#include "View.h"

class MenuScene : public Scene
{
    public:
        MenuScene();
        virtual ~MenuScene();

        virtual void initialize();
        virtual void shutdown();

        virtual bool processEvents(SDL_Event& event);
        virtual void update(const int& deltaTime);
        virtual void draw(SDL_Renderer*& renderer) const;

    public:

    private:

    private:
        SpriteSheet* spritesheet;
        Sprite* sprite;

};