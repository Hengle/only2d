#include "LuaEvent.h"

namespace only2d
{
	const luaL_Reg LuaEvent::functions[] =
	{
		{ nullptr, nullptr }
	};

	void LuaEvent::openModule(lua_State *L)
	{
		Lua::beginModule(L, LuaModule::Event);
		Lua::pushFunctions(L, functions);
		Lua::finishModule(L, LuaModule::Event);
	}
}
