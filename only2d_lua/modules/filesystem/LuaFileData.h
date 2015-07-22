#pragma once

#include "common/Lua.h"

namespace only2d
{
	class LuaFileData
	{
	public:
		static void openType(lua_State *L);

	protected:
		static int32_t getFilename(lua_State *L);

		static int32_t getExtention(lua_State *L);

	private:
		static const luaL_Reg functions[];
	};
}