#pragma once

#include "common/Color.h"

#include <cstdint>
#include <utility>
#include <string>
#include <vector>

namespace only2d
{
	class WindowSettings
	{
	public:
		WindowSettings();

		void load(const std::vector<std::pair<std::string, std::string>> &settings);

		int32_t x;
		int32_t y;
		int32_t width;
		int32_t height;
		int32_t minWidth;
		int32_t minHeight;
		int32_t maxWidth;
		int32_t maxHeight;
		bool fullscreen;
		bool borderless;
		bool resizeable;
		bool highdpi;
		Color background;

		bool event;
		bool filesystem;
		bool graphics;
		bool texture;
		bool timer;
		bool window;
	};
}