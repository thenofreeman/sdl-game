#include "AssetManager.h"

AssetManager::AssetManager()
{ }

AssetManager::~AssetManager()
{
    for (Texture* texture : textures)
    {
        delete texture; 
    }
}

Texture* AssetManager::loadTexture(std::string path)
{
    Texture* newTexture = new Texture;

	if (!newTexture->load(path))
	{
		std::cerr << "Unable to load texture image " << path << "! SDL Error: " << SDL_GetError() << std::endl;
        newTexture = nullptr;
	}
    else
    {
        //textures.push_back(newTexture);
    }

    return newTexture;
}