//
// Created by leafnsand on 2015/6/4.
//

#pragma once

#include "common/Module.h"

namespace only2d
{
	class WindowSettings;

	class Application : public Module
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