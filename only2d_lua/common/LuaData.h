//
// Created by leafnsand on 2015/7/15.
//

#pragma once

#include "Lua.h"

namespace only2d
{
	class LuaData
	{
	public:
		static void openType(lua_State *L);

	protected:
		static int32_t assign(lua_State *L);

		static int32_t getBuffer(lua_State *L);

		static int32_t getSize(lua_State *L);

		static int32_t at(lua_State *L);

	private:
		static const luaL_Reg functions[];
	};
}