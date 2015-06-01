//
// Created by leafnsand on 2015/5/28.
//

#include <common/Console.h>
#include "Only2D.h"

#include "modules/event/Event.h"
#include "modules/filesystem/FileSystem.h"
#include "modules/graphics/Graphics.h"
#include "modules/texture/Texture.h"
#include "modules/window/Window.h"

namespace only2d
{
    ModuleType Only2D::getType() const
    {
        return ModuleType::ONLY2D;
    }

    const char *Only2D::getName() const
    {
        return "Only2d";
    }

    Only2D::Only2D() :
            running(true)
    {
        registerModule(this);
    }

    Only2D::~Only2D()
    {
        deregisterModule(this);
    }

    int32_t Only2D::run(int32_t argc, char *argv[])
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

        Window window;
        WindowSettings settings;
        settings.load(fileSystem.getSettings());
        window.setSettings(settings);

        Graphics graphics;

        Texture texture;

        Event event;

        while (running)
        {
            event.pollEvent();
            graphics.clear();
            window.swapBuffers();
        }
        return 0;
    }

    void Only2D::quit()
    {
        running = false;
    }
}