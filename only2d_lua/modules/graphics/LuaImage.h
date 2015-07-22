#pragma once

#include "common/Lua.h"

namespace only2d
{
	class LuaImage
	{
	public:
		static void openType(lua_State *L);

	protected:
		static int32_t draw(lua_State *L);

		static int32_t getImageData(lua_State *L);

		static int32_t setImageData(lua_State *L);

	private:
		static const luaL_Reg functions[];
	};
}