#include "Application.h"

#include "common/Module.h"

#include "modules/event/Event.h"
#include "modules/filesystem/FileSystem.h"
#include "modules/graphics/Graphics.h"
#include "modules/keyboard/Keyboard.h"
#include "modules/texture/Texture.h"
#include "modules/timer/Timer.h"
#include "modules/window/Window.h"

namespace only2d
{
	Application::Application() :
		running(true)
	{
	}

	Application::~Application()
	{
	}

	int32_t Application::run(int32_t argc, char *argv[])
	{
		auto filesystem = Module::open<FileSystem>(ModuleType::FILESYSTEM);
		if (argc > 1)
		{
			filesystem->init(argv[1]);
		}
		else
		{
			filesystem->init(nullptr);
		}

		auto event = Module::open<Event>(ModuleType::EVENT);

		auto window = Module::open<Window>(ModuleType::WINDOW);
		WindowSettings settings;
		settings.load(filesystem->getSettings());
		window->setSettings(settings);

		auto graphics = Module::open<Graphics>(ModuleType::GRAPHICS);
		graphics->setResolution(settings.width, settings.height);
		graphics->setBackgroundColor(settings.background);

		auto texture = Module::open<Texture>(ModuleType::TEXTURE);

		auto timer = Module::open<Timer>(ModuleType::TIMER);

		auto keyboard = Module::open<Keyboard>(ModuleType::KEYBOARD);

		initialize();

		while (running)
		{
			event->pollEvent();
			graphics->clear();
			update(timer->step());
			window->swapBuffers();
			graphics->checkOpenGLError();
		}

		filesystem.reset();
		event.reset();
		window.reset();
		graphics.reset();
		texture.reset();
		timer.reset();
		keyboard.reset();

		finalize();

		Module::close(ModuleType::KEYBOARD);
		Module::close(ModuleType::TIMER);
		Module::close(ModuleType::TEXTURE);
		Module::close(ModuleType::GRAPHICS);
		Module::close(ModuleType::WINDOW);
		Module::close(ModuleType::EVENT);
		Module::close(ModuleType::FILESYSTEM);

		return 0;
	}

	void Application::quit()
	{
		running = false;
	}
}
