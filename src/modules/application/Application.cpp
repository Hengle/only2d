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
        registerModule(this);
    }

    Application::~Application()
    {
        deregisterModule(this);
    }

    int32_t Application::run(int32_t argc, char *argv[])
    {
        FileSystem fileSystem;
        if (argc > 1)
        {
            fileSystem.init(argv[1]);
        }
        else
        {
            fileSystem.init(nullptr);
        }

        Event event;

        Window window;
        WindowSettings settings;
        settings.load(fileSystem.getSettings());
        window.setSettings(settings);

        Graphics graphics;
        graphics.setResolution(settings.width, settings.height);
        graphics.setBackgroundColor(settings.background);

        Texture texture;

        Timer timer;

        initialize();

        while (running)
        {
            event.pollEvent();
            graphics.clear();
            update(timer.step());
            window.swapBuffers();
        }

        finalize();

        return 0;
    }

    void Application::quit()
    {
        running = false;
    }
}