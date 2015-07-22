#pragma once

#include "common/Lua.h"

namespace only2d
{
	class LuaFile
	{
	public:
		static void openType(lua_State *L);

	protected:
		static int32_t good(lua_State *L);

		static int32_t getSize(lua_State *L);

		static int32_t read(lua_State *L);

		static int32_t write(lua_State *L);

		static int32_t flush(lua_State *L);

		static int32_t eof(lua_State *L);

		static int32_t tell(lua_State *L);

		static int32_t available(lua_State *L);

		static int32_t seek(lua_State *L);

	private:
		static const luaL_Reg functions[];
	};
}