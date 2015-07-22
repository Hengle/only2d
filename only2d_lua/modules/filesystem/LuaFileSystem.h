//
// Created by leafnsand on 2015/7/13.
//

#pragma once

#include "common/Lua.h"

namespace only2d
{
	class LuaFileSystem
	{
	public:
		static void openModule(lua_State *L);

	protected:
		static int32_t createFile(lua_State *L);

		static int32_t createBinaryFile(lua_State *L);

		static int32_t appendFile(lua_State *L);

		static int32_t appendBinaryFile(lua_State *L);

		static int32_t openFile(lua_State *L);

		static int32_t openBinaryFile(lua_State *L);

		static int32_t newFileData(lua_State *L);

	private:
		static const luaL_Reg functions[];
	};
}