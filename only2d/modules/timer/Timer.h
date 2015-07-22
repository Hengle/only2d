#pragma once

#include <chrono>

namespace only2d
{
	class Timer
	{
	public:
		Timer();

		virtual ~Timer();

		float step();

		float getTime() const;

		float getDelta() const;

		int32_t getFPS() const;

	private:
		std::chrono::time_point<std::chrono::system_clock> lastUpdate;
		int32_t count;
		int32_t fps;
		float delta;
		float time;
		float lastUpdateFPS;
	};
}