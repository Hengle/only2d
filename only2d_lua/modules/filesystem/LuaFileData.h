//
// Created by leafnsand on 2015/7/15.
//

#ifndef ONLY2D_LUAFILEDATA_H
#define ONLY2D_LUAFILEDATA_H

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

#endif //ONLY2D_LUAFILEDATA_H

