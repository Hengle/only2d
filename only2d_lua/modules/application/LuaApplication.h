//
// Created by leafnsand on 2015/7/11.
//

#ifndef ONLY2D_LUAAPPLICATION_H
#define ONLY2D_LUAAPPLICATION_H

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

#endif //ONLY2D_LUAAPPLICATION_H

