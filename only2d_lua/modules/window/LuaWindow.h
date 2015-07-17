//
// Created by leafnsand on 2015/7/13.
//

#ifndef ONLY2D_LUAWINDOW_H
#define ONLY2D_LUAWINDOW_H

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

#endif //ONLY2D_LUAWINDOW_H

