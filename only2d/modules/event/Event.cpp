#include "Event.h"

#include "common/Module.h"

#include "modules/application/Application.h"

#include <SDL2/SDL_events.h>

namespace only2d
{
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
			default:
				break;
			}
		}
		app.reset();
	}
}
