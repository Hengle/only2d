//
// Created by leafnsand on 2015/6/4.
//

#include "Application.h"
#include "modules/event/Event.h"
#include "modules/filesystem/FileSystem.h"
#include "modules/graphics/Graphics.h"
#include "modules/texture/Texture.h"
#include "modules/timer/Timer.h"
#include "modules/window/Window.h"

namespace only2d
{
    ModuleType Application::getType() const
    {
        return ModuleType::APPLICATION;
    }

    const char *Application::getName() const
    {
        return "Only2d";
    }

    Application::Application() :
            running(true)
    {
    }

    Application::~Application()
    {
    }

    int32_t Application::run(int32_t argc, char *argv[])
    {
        auto fileSystem = Module::open<FileSystem>(ModuleType::FILESYSTEM);
        if (argc > 1)
        {
            fileSystem->init(argv[1]);
        }
        else
        {
            fileSystem->init(nullptr);
        }

        auto event = Module::open<Event>(ModuleType::EVENT);

        auto window = Module::open<Window>(ModuleType::WINDOW);

        WindowSettings settings;
        settings.load(fileSystem->getSettings());
        window->setSettings(settings);

        auto graphics = Module::open<Graphics>(ModuleType::GRAPHICS);

        graphics->setResolution(settings.width, settings.height);
        graphics->setBackgroundColor(settings.background);

        auto texture = Module::open<Texture>(ModuleType::TEXTURE);

        auto timer = Module::open<Timer>(ModuleType::TIMER);

        initialize();

        while (running)
        {
            event->pollEvent();
            graphics->clear();
            update(timer->step());
            window->swapBuffers();
            graphics->checkOpenGLError();
        }

        finalize();

        return 0;
    }

    void Application::quit()
    {
        running = false;
    }
}