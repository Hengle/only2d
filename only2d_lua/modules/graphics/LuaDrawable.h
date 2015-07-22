//
// Created by leafnsand on 2015/7/16.
//

#pragma once

#include "common/Lua.h"

namespace only2d
{
	class LuaDrawable
	{
	public:
		static void openType(lua_State *L);

	protected:
		static int32_t getX(lua_State *L);

		static int32_t setX(lua_State *L);

		static int32_t getY(lua_State *L);

		static int32_t setY(lua_State *L);

		static int32_t getRotation(lua_State *L);

		static int32_t setRotation(lua_State *L);

		static int32_t getScaleX(lua_State *L);

		static int32_t setScaleX(lua_State *L);

		static int32_t getScaleY(lua_State *L);

		static int32_t setScaleY(lua_State *L);

		static int32_t getOffsetX(lua_State *L);

		static int32_t setOffsetX(lua_State *L);

		static int32_t getOffsetY(lua_State *L);

		static int32_t setOffsetY(lua_State *L);

		static int32_t getSkewX(lua_State *L);

		static int32_t setSkewX(lua_State *L);

		static int32_t getSkewY(lua_State *L);

		static int32_t setSkewY(lua_State *L);

		static int32_t getAlpha(lua_State *L);

		static int32_t setAlpha(lua_State *L);

		static int32_t isVisible(lua_State *L);

		static int32_t setVisible(lua_State *L);

		static int32_t getColor(lua_State *L);

		static int32_t setColor(lua_State *L);

		static int32_t getBlendMode(lua_State *L);

		static int32_t setBlendMode(lua_State *L);

	private:
		static const luaL_Reg functions[];
	};
}