#pragma once

#include <iostream>
#include <string>
#include <vector>

#include <SDL2/SDL_image.h>

#include "Texture.h"

class AssetManager
{
    public:
        virtual ~AssetManager();

        static AssetManager& getInstance()
        {
            static AssetManager instance;
            return instance;
        }

        Texture* loadTexture(std::string path);

    public:

    private:
        std::vector<Texture*> textures;

    private:
        AssetManager();

};