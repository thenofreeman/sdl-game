#pragma once

#include <SDL2/SDL.h>

struct EventPair 
{
    SDL_EventType eventType;
    Sint32 value;

    bool operator==(const EventPair& rhs) {
        return (eventType == rhs.eventType)
            && (value == rhs.value);
    }
};

bool inline operator==(const EventPair& lhs, const EventPair& rhs) {
    return (lhs.eventType == rhs.eventType)
        && (lhs.value == rhs.value);
}
