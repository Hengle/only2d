//
// Created by leafnsand on 2015/5/28.
//

#include "common/Console.h"
#include "Window.h"

namespace only2d
{
    ModuleType Window::getType() const
    {
        return ModuleType::WINDOW;
    }

    const char *Window::getName() const
    {
        return "Window";
    }

    Window::Window() :
            window(nullptr),
            context(nullptr),
            title("only2d")
    {
        registerModule(this);
        if (SDL_InitSubSystem(SDL_INIT_VIDEO) != 0)
        {
            Console::error << "initialize SDL video fail: " << SDL_GetError() << Console::endl;
        }
    }

    Window::~Window()
    {
        deregisterModule(this);
        destroyContext();
        destroyWindow();
        SDL_QuitSubSystem(SDL_INIT_VIDEO);
    }

    void Window::create(int32_t x, int32_t y, int32_t width, int32_t height, uint32_t flags)
    {
        destroyContext();
        destroyWindow();
        window = SDL_CreateWindow(title.c_str(), x, y, width, height, flags);
        if (window == nullptr)
        {
            Console::error << "create window fail: " << SDL_GetError() << Console::endl;
        }
        context = SDL_GL_CreateContext(window);
        if (context == nullptr)
        {
            Console::error << "create context fail: " << SDL_GetError() << Console::endl;
        }
    }

    void Window::setSettings(WindowSettings &settings)
    {
        SDL_DisplayMode mode;
        SDL_GetDesktopDisplayMode(0, &mode);
        if (settings.x <= 0 || settings.y <= 0)
        {
            settings.x = SDL_WINDOWPOS_UNDEFINED;
            settings.y = SDL_WINDOWPOS_UNDEFINED;
        }
        if (settings.width <= 0 || settings.height <= 0)
        {
            settings.width = mode.w;
            settings.height = mode.h;
        }
        settings.minWidth = std::max(settings.minWidth, 1);
        settings.minHeight = std::max(settings.minHeight, 1);
        if (settings.maxWidth <= 0 || settings.maxHeight <= 0)
        {
            settings.maxWidth = mode.w;
            settings.maxHeight = mode.h;
        }
        settings.maxWidth = std::min(settings.maxWidth, mode.w);
        settings.maxHeight = std::min(settings.maxHeight, mode.h);
        uint32_t flags = SDL_WINDOW_OPENGL;
        if (settings.fullscreen)
        {
            flags |= SDL_WINDOW_FULLSCREEN;
        }
        if (settings.borderless)
        {
            flags |= SDL_WINDOW_BORDERLESS;
        }
        if (settings.resizeable)
        {
            flags |= SDL_WINDOW_RESIZABLE;
        }
        if (settings.highdpi)
        {
            flags |= SDL_WINDOW_ALLOW_HIGHDPI;
        }
        create(settings.x, settings.y, settings.width, settings.height, flags);
        if (settings.resizeable)
        {
            SDL_SetWindowMinimumSize(window, settings.minWidth, settings.minHeight);
            SDL_SetWindowMaximumSize(window, settings.maxWidth, settings.maxHeight);
        }
        SDL_RaiseWindow(window);
    }

    void Window::swapBuffers()
    {
        if (window)
        {
            SDL_GL_SwapWindow(window);
        }
    }

    const std::string &Window::getTitle() const
    {
        return title;
    }

    void Window::setTitle(const std::string &title)
    {
        this->title = title;
        if (window)
        {
            SDL_SetWindowTitle(window, this->title.c_str());
        }
    }

    void Window::destroyContext()
    {
        if (context)
        {
            SDL_GL_DeleteContext(context);
            context = nullptr;
        }
    }

    void Window::destroyWindow()
    {
        if (window)
        {
            SDL_DestroyWindow(window);
            SDL_FlushEvent(SDL_WINDOWEVENT);
            window = nullptr;
        }
    }
}