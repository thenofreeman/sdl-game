#pragma once

#include <unordered_map> // unordered_map
#include <memory> // hash

#include <SDL2/SDL.h>

#include "Action.h"

class InputHandler 
{
    public:
        InputHandler();
        virtual ~InputHandler();

        void bindInput(const SDL_KeyCode& key, Action* action);
        Action* handleInput(const SDL_Keycode& key);

    public:

    private:

    private:
        struct KeyHash {
            std::size_t operator()(const SDL_Keycode& key) const {
                return std::hash<int>()(static_cast<int>(key));
            }
        };
        std::unordered_map<SDL_Keycode, Action*, KeyHash> inputMap;

};