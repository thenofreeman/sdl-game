#include "InputHandler.h"

InputHandler::InputHandler()
{ }

InputHandler::~InputHandler()
{ }

void InputHandler::bindInput(const SDL_KeyCode& key, Action* action)
{
    inputMap[key] = action;
}

Action* InputHandler::handleInput(const SDL_Keycode& key)
{
    return inputMap[key];
}