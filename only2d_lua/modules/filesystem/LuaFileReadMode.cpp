#include "LuaFileReadMode.h"

#include "common/Lua.h"

#include "modules/filesystem/File.h"

namespace only2d
{
	void LuaFileReadMode::openEnum(lua_State *L)
	{
		Lua::beginEnum(L);
		Lua::pushEnum<FileReadMode>(L, FileReadMode::BLOCK);
		Lua::setField(L, -2, "BLOCK");
		Lua::pushEnum<FileReadMode>(L, FileReadMode::ALL);
		Lua::setField(L, -2, "ALL");
		Lua::finishEnum(L, "FileReadMode");
	}
}
