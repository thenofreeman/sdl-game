#include "InputHandler.h"

InputHandler::InputHandler()
{ }

InputHandler::~InputHandler()
{ }

void InputHandler::bindInput(const SDL_KeyCode& key, Action* action)
{
    inputMap[{ SDL_KEYDOWN, static_cast<Sint32>(key) }] = action;
}

Action* InputHandler::handleInput(const SDL_Event& event)
{
    switch (event.type)
    {
        case SDL_KEYDOWN:
            return inputMap[{ SDL_KEYDOWN , static_cast<Sint32>(event.key.keysym.sym) }];
            break;
        default:
            return nullptr;
            break;
    }
}