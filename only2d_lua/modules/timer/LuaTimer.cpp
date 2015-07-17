//
// Created by leafnsand on 2015/7/13.
//

#include "LuaTimer.h"

#include "modules/timer/Timer.h"

namespace only2d
{
	const luaL_Reg LuaTimer::functions[] =
	{
		{ "getTime", getTime },
		{ "getDelta", getDelta },
		{ "getFPS", getFPS },
		{ nullptr, nullptr }
	};

	void LuaTimer::openModule(lua_State *L)
	{
		Lua::beginModule(L, LuaModule::Timer);
		Lua::pushFunctions(L, functions);
		Lua::finishModule(L, LuaModule::Timer);
	}

	int32_t LuaTimer::getTime(lua_State *L)
	{
		auto timer = Module::getInstance<Timer>(ModuleType::TIMER);
		Lua::pushNumber(L, timer->getTime());
		return 1;
	}

	int32_t LuaTimer::getDelta(lua_State *L)
	{
		auto timer = Module::getInstance<Timer>(ModuleType::TIMER);
		Lua::pushNumber(L, timer->getDelta());
		return 1;
	}

	int32_t LuaTimer::getFPS(lua_State *L)
	{
		auto timer = Module::getInstance<Timer>(ModuleType::TIMER);
		Lua::pushInteger(L, timer->getFPS());
		return 1;
	}
}
