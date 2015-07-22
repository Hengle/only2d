//
// Created by leafnsand on 2015/7/13.
//

#pragma once

#include "common/Lua.h"

namespace only2d
{
	class LuaTimer
	{
	public:
		static void openModule(lua_State *L);

	protected:
		static int32_t getTime(lua_State *L);

		static int32_t getDelta(lua_State *L);

		static int32_t getFPS(lua_State *L);

	private:
		static const luaL_Reg functions[];
	};
}