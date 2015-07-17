//
// Created by leafnsand on 2015/7/13.
//

#ifndef ONLY2D_LUAEVENT_H
#define ONLY2D_LUAEVENT_H

#include "common/Lua.h"

namespace only2d
{
	class LuaEvent
	{
	public:
		static void openModule(lua_State *L);

	private:
		static const luaL_Reg functions[];
	};
}

#endif //ONLY2D_LUAEVENT_H

