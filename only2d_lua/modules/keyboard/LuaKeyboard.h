//
// Created by leafnsand on 2015/7/20.
//

#pragma once

#include "common/Lua.h"

namespace only2d
{
    class LuaKeyboard
    {
    public:
	    static void openModule(lua_State *L);

    protected:
	    static int32_t isPressed(lua_State *L);

    private:
	    static const luaL_Reg functions[];
    };
}