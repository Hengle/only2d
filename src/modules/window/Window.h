//
// Created by leafnsand on 2015/5/28.
//

#ifndef ONLY2D_WINDOW_H
#define ONLY2D_WINDOW_H

#include "WindowSettings.h"
#include "common/Module.h"

#include <SDL2/SDL.h>

namespace only2d
{
    class Window : public Module
    {
    public:
        Window();

        virtual ~Window();

        virtual ModuleType getType() const;

        virtual const char *getName() const;

        void create(int32_t x, int32_t y, int32_t width, int32_t height, uint32_t flags);

        void setSettings(WindowSettings &settings);

        void swapBuffers();

        const std::string &getTitle() const;

        void setTitle(const std::string &title);

    private:
        void destroyContext();

        void destroyWindow();

    private:
        SDL_Window *window;
        SDL_GLContext context;
        std::string title;
    };
}

#endif //ONLY2D_WINDOW_H
