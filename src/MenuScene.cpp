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
    sprite = spritesheet->createSprite({100, 0, 100, 100});
    

    view = new View({10, 10, 100, 100}, sprite);
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