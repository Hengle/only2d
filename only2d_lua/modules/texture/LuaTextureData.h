//
// Created by leafnsand on 2015/7/16.
//

#ifndef ONLY2D_LUATEXTUREDATA_H
#define ONLY2D_LUATEXTUREDATA_H

#include "common/Lua.h"

namespace only2d
{
	class LuaTextureData
	{
	public:
		static void openType(lua_State *L);

	protected:
		static int32_t encode(lua_State *L);

		static int32_t decode(lua_State *L);

		static int32_t getWidth(lua_State *L);

		static int32_t getHeight(lua_State *L);

	private:
		static const luaL_Reg functions[];
	};
}

#endif //ONLY2D_LUATEXTUREDATA_H

