#pragma once

#include <iostream>

#include <SDL2/SDL.h>

class GlobalEnvironment
{
    public:
        virtual ~GlobalEnvironment() { }
          
        static GlobalEnvironment& getInstance()
        {
            static GlobalEnvironment instance;
            return instance;
        }

        bool initialize();
        bool shutdown();

    public:
        SDL_Window* window;
        SDL_Surface* screen;
        SDL_Renderer* renderer;

        int windowWidth;
        int windowHeight;

    private:
        std::string title;

    private:
        GlobalEnvironment();

};