#include "MenuScene.h"

#include "AssetManager.h"

MenuScene::MenuScene()
    : texture{new Texture},
      view{nullptr}
{ }

MenuScene::~MenuScene()
{ 
    delete texture;
}

void MenuScene::initialize()
{
	AssetManager assetManager = AssetManager::getInstance();
    texture = assetManager.loadTexture("res/foo.png");

    view = new View({10, 10, 100, 100}, texture);
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