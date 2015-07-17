//
// Created by leafnsand on 2015/7/16.
//

#include "LuaImageDataFilterMode.h"

#include "common/Lua.h"

#include "modules/graphics/ImageData.h"

namespace only2d
{
	void LuaImageDataFilterMode::openEnum(lua_State *L)
	{
		Lua::beginEnum(L);
		Lua::pushEnum<ImageDataFilterMode>(L, ImageDataFilterMode::LINEAR);
		Lua::setField(L, -2, "LINEAR");
		Lua::pushEnum<ImageDataFilterMode>(L, ImageDataFilterMode::NEAREST);
		Lua::setField(L, -2, "NEAREST");
		Lua::finishEnum(L, "ImageDataFilterMode");
	}
}
