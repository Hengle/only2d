#pragma once

#include "WindowSettings.h"

#include <SDL2/SDL.h>

namespace only2d
{
	class Window
	{
	public:
		Window();

		virtual ~Window();

		void setSettings(WindowSettings &settings);

		void swapBuffers();

		const std::string &getTitle() const;

		void setTitle(const std::string &title);

	private:
		void create(int32_t x, int32_t y, int32_t width, int32_t height, uint32_t flags);

		void destroyContext();

		void destroyWindow();

	private:
		SDL_Window *window;
		SDL_GLContext context;
		std::string title;
	};
}