#include "LuaApplication.h"

#include "common/Module.h"

#include "modules/application/Application.h"

namespace only2d
{
	const luaL_Reg LuaApplication::functions[] =
	{
		{ "quit", quit },
		{ nullptr, nullptr }
	};

	void LuaApplication::openModule(lua_State *L)
	{
		Lua::beginModule(L, LuaModule::Application);
		Lua::pushFunctions(L, functions);
		Lua::finishModule(L, LuaModule::Application);
	}

	int32_t LuaApplication::quit(lua_State *L)
	{
		auto application = Module::getInstance<Application>(ModuleType::APPLICATION);
		application->quit();
		return 0;
	}
}
