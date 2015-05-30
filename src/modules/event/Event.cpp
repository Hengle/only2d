//
// Created by leafnsand on 2015/5/28.
//

#include "Event.h"
#include "modules/only2d/Only2D.h"

#include <SDL2/SDL_events.h>

namespace only2d
{
    ModuleType Event::getType() const
    {
        return ModuleType::EVENT;
    }

    const char *Event::getName() const
    {
        return "Event";
    }

    Event::Event()
    {
        registerModule(this);
    }

    Event::~Event()
    {
        deregisterModule(this);
    }

    void Event::pollEvent()
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    getInstance<Only2D>(ModuleType::ONLY2D)->quit();
                default:
                    break;
            }
        }
    }
}