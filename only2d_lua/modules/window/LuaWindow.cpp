//
// Created by leafnsand on 2015/7/13.
//

#include "LuaWindow.h"

#include "modules/window/Window.h"

namespace only2d
{
	const luaL_Reg LuaWindow::functions[] =
	{
		{ "setSettings", setSettings },
		{ "getTitle", getTitle },
		{ "setTitle", setTitle },
		{ nullptr, nullptr }
	};

	void LuaWindow::openModule(lua_State *L)
	{
		Lua::beginModule(L, LuaModule::Window);
		Lua::pushFunctions(L, functions);
		Lua::finishModule(L, LuaModule::Window);
	}

	int32_t LuaWindow::setSettings(lua_State *L)
	{
		auto window = Module::getInstance<Window>(ModuleType::WINDOW);
		auto table = Lua::getStringTable(L, 1);
		WindowSettings settings;
		settings.load(table);
		window->setSettings(settings);
		return 0;
	}

	int32_t LuaWindow::getTitle(lua_State *L)
	{
		auto window = Module::getInstance<Window>(ModuleType::WINDOW);
		Lua::pushString(L, window->getTitle());
		return 1;
	}

	int32_t LuaWindow::setTitle(lua_State *L)
	{
		auto window = Module::getInstance<Window>(ModuleType::WINDOW);
		auto title = Lua::getString(L, 1);
		window->setTitle(title);
		return 0;
	}
}
