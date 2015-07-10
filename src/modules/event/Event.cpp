//
// Created by leafnsand on 2015/5/28.
//

#include "Event.h"
#include "modules/application/Application.h"

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
    }

    Event::~Event()
    {
    }

    void Event::pollEvent()
    {
        SDL_Event event;
		auto app = Module::getInstance<Application>(ModuleType::APPLICATION);
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
					app->quit();
                    break;
                case SDL_KEYDOWN:
                    break;
                default:
                    break;
            }
        }
		app.reset();
    }
}