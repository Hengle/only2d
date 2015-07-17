//
// Created by leafnsand on 2015/6/4.
//

#ifndef ONLY2D_TIMER_H
#define ONLY2D_TIMER_H

#include "common/Module.h"

#include <chrono>

namespace only2d
{
	class Timer : public Module
	{
	public:
		Timer();

		virtual ~Timer();

		virtual ModuleType getType() const override;

		virtual const char *getName() const override;

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

#endif //ONLY2D_TIMER_H
