//
// Created by leafnsand on 2015/7/16.
//

#ifndef ONLY2D_LUAIMAGEDATA_H
#define ONLY2D_LUAIMAGEDATA_H

#include "common/Lua.h"

namespace only2d
{
	class LuaImageData
	{
	public:
		static void openType(lua_State *L);

	protected:
		static int32_t bind(lua_State *L);

		static int32_t unbind(lua_State *L);

		static int32_t getWidth(lua_State *L);

		static int32_t setWidth(lua_State *L);

		static int32_t getHeight(lua_State *L);

		static int32_t setHeight(lua_State *L);

		static int32_t getGLTexture(lua_State *L);

		static int32_t getWrap(lua_State *L);

		static int32_t setWrap(lua_State *L);

		static int32_t getFilter(lua_State *L);

		static int32_t setFilter(lua_State *L);

	private:
		static const luaL_Reg functions[];
	};
}

#endif //ONLY2D_LUAIMAGEDATA_H

