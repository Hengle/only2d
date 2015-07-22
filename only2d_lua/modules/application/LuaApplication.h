//
// Created by leafnsand on 2015/7/11.
//

#pragma once

#include "common/Lua.h"

namespace only2d
{
	class LuaApplication
	{
	public:
		static void openModule(lua_State *L);

	protected:
		static int quit(lua_State *L);

	private:
		static const luaL_Reg functions[];
	};
}