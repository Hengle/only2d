//
// Created by leafnsand on 2015/7/16.
//

#pragma once

#include "common/Lua.h"

namespace only2d
{
	class LuaShader
	{
	public:
		static void openType(lua_State *L);

	protected:
		static int32_t match(lua_State *L);

		static int32_t setAttributeData(lua_State *L);

		static int32_t setUniformIntData(lua_State *L);

		static int32_t setUniformFloatData(lua_State *L);

		static int32_t setUniformMatrixData(lua_State *L);

		static int32_t attach(lua_State *L);

		static int32_t detach(lua_State *L);

	private:
		static const luaL_Reg functions[];
	};
}