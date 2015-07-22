#include "LuaImageDataWrapMode.h"

#include "common/Lua.h"

#include "modules/graphics/ImageData.h"

namespace only2d
{
	void LuaImageDataWrapMode::openEnum(lua_State *L)
	{
		Lua::beginEnum(L);
		Lua::pushEnum<ImageDataWrapMode>(L, ImageDataWrapMode::CLAMP);
		Lua::setField(L, -2, "CLAMP");
		Lua::pushEnum<ImageDataWrapMode>(L, ImageDataWrapMode::REPEAT);
		Lua::setField(L, -2, "REPEAT");
		Lua::pushEnum<ImageDataWrapMode>(L, ImageDataWrapMode::MIRRORED_REPEAT);
		Lua::setField(L, -2, "MIRRORED_REPEAT");
		Lua::finishEnum(L, "ImageDataWrapMode");
	}
}
