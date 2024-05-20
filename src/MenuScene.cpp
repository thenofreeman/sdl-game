#include "MenuScene.h"

#include "AssetManager.h"

MenuScene::MenuScene()
    : sprite{nullptr},
      view{nullptr}
{ }

MenuScene::~MenuScene()
{ 
    delete sprite;
}

void MenuScene::initialize()
{
    spritesheet = new SpriteSheet("res/dots.png");
    sprite = spritesheet->createSprite({ 0, 0, 100, 100 });
    sprite->setPosition({ 50, 50 });
    

    view = new View({ 50, 50, 150, 150 }, sprite);
}

void MenuScene::shutdown()
{

}

void MenuScene::processEvents(SDL_Event& event)
{

}

void MenuScene::handleInput()
{

}

void MenuScene::update(const int& deltaTime)
{

}

void MenuScene::draw(SDL_Renderer*& renderer) const
{
	view->draw(renderer);
}