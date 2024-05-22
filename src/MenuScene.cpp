#include "MenuScene.h"

MenuScene::MenuScene()
    : sprite{nullptr}
{ }

MenuScene::~MenuScene()
{ 
    delete sprite;
}

void MenuScene::initialize()
{
    spritesheet = new SpriteSheet("res/dots.png");
    sprite = spritesheet->createSprite({ 0, 0, 100, 100 });
    sprite->setPosition({ 0, 0 });

    Action* actionA = new PositionAAction;
    Action* actionB = new PositionBAction;
    inputHandler.bindInput(SDLK_h, actionA);
    inputHandler.bindInput(SDLK_l, actionB);

}

void MenuScene::shutdown()
{

}

bool MenuScene::processEvents(SDL_Event& event)
{
    bool eventProcessed = true;

    Action* newAction = inputHandler.handleInput(event.key.keysym.sym);

    if (newAction)
        actionStack.push(newAction);
    else
        eventProcessed = false;

    return eventProcessed;
}

void MenuScene::update(const int& deltaTime)
{
    if (!actionStack.empty())
    {
        actionStack.top()->execute(sprite);
        actionStack.pop();
    }
}

void MenuScene::draw(SDL_Renderer*& renderer) const
{
	sprite->draw(renderer);
}