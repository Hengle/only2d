//
// Created by leafnsand on 2015/7/15.
//

#include "LuaFileData.h"

#include "modules/filesystem/FileData.h"

namespace only2d
{
	const luaL_Reg LuaFileData::functions[] =
	{
		{ "getFilename", getFilename },
		{ "getExtention", getExtention },
		{ nullptr, nullptr }
	};

	void LuaFileData::openType(lua_State *L)
	{
		Lua::beginType(L, LuaType::FileData);
		Lua::pushFunctions(L, functions);
		Lua::finishType(L, LuaType::Data);
	}

	int32_t LuaFileData::getFilename(lua_State *L)
	{
		auto data = Lua::getObject<FileData>(L, 1, LuaType::FileData);
		Lua::pushString(L, data->getFilename());
		return 1;
	}

	int32_t LuaFileData::getExtention(lua_State *L)
	{
		auto data = Lua::getObject<FileData>(L, 1, LuaType::FileData);
		Lua::pushString(L, data->getExtention());
		return 1;
	}
}
