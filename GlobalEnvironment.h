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

    private:
        int windowWidth;
        int windowHeight;

        std::string title;

    private:
        GlobalEnvironment();

};