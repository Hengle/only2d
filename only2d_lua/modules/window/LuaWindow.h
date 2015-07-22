#pragma once

#include "common/Lua.h"

namespace only2d
{
	class LuaWindow
	{
	public:
		static void openModule(lua_State *L);

	protected:
		static int32_t setSettings(lua_State *L);

		static int32_t getTitle(lua_State *L);

		static int32_t setTitle(lua_State *L);

	private:
		static const luaL_Reg functions[];
	};
}