//
// Created by leafnsand on 2015/7/16.
//

#ifndef ONLY2D_LUAIMAGE_H
#define ONLY2D_LUAIMAGE_H

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

#endif //ONLY2D_LUAIMAGE_H

