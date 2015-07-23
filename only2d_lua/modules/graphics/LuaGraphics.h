#pragma once

#include "common/Lua.h"

namespace only2d
{
	class LuaGraphics
	{
	public:
		static void openModule(lua_State *L);

	protected:
		static int32_t createShader(lua_State *L);

		static int32_t createImageData(lua_State *L);

		static int32_t createImage(lua_State *L);

		static int32_t getBackgroundColor(lua_State *L);

		static int32_t setBackgroundColor(lua_State *L);

		static int32_t getDrawCalls(lua_State *L);

	private:
		static const luaL_Reg functions[];
	};
}