#pragma once

#include <unordered_map> // unordered_map
#include <memory> // hash

#include <SDL2/SDL.h>

#include "Action.h"
#include "EventPair.h"

class InputHandler 
{
    public:
        InputHandler();
        virtual ~InputHandler();

        void bindInput(const SDL_KeyCode& key, Action* action);
        Action* handleInput(const SDL_Event& event);

    public:

    private:

    private:
        struct KeyHash {
            std::size_t operator()(const EventPair& eventPair) const {
                return std::hash<int>()(static_cast<int>(eventPair.eventType)) 
                     ^ std::hash<int>()(static_cast<int>(eventPair.value));
            }
        };

        std::unordered_map<EventPair, Action*, KeyHash> inputMap;

};