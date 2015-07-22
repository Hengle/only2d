#include "LuaBlendMode.h"

#include "common/Lua.h"

#include "modules/graphics/BlendMode.h"

namespace only2d
{
	void LuaBlendMode::openEnum(lua_State *L)
	{
		Lua::beginEnum(L);
		Lua::pushEnum<BlendMode>(L, BlendMode::ALPHA);
		Lua::setField(L, -2, "ALPHA");
		Lua::pushEnum<BlendMode>(L, BlendMode::ADD);
		Lua::setField(L, -2, "ADD");
		Lua::pushEnum<BlendMode>(L, BlendMode::SUBTRACT);
		Lua::setField(L, -2, "SUBTRACT");
		Lua::pushEnum<BlendMode>(L, BlendMode::MULTIPLY);
		Lua::setField(L, -2, "MULTIPLY");
		Lua::pushEnum<BlendMode>(L, BlendMode::PRE_MULTIPLIED);
		Lua::setField(L, -2, "PRE_MULTIPLIED");
		Lua::pushEnum<BlendMode>(L, BlendMode::SCREEN);
		Lua::setField(L, -2, "SCREEN");
		Lua::pushEnum<BlendMode>(L, BlendMode::REPLACE);
		Lua::setField(L, -2, "REPLACE");
		Lua::finishEnum(L, "BlendMode");
	}
}
