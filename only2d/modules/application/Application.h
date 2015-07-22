#pragma once

#include <cstdint>

namespace only2d
{
	class WindowSettings;

	class Application
	{
	public:
		Application();

		virtual ~Application();

		int32_t run(int32_t argc, char *argv[]);

		void quit();

		virtual void initialize() = 0;

		virtual void update(float delta) = 0;

		virtual void finalize() = 0;

	private:
		bool running;
	};
}