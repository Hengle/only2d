//
// Created by leafnsand on 2015/7/15.
//

#include "LuaData.h"

#include "common/Data.h"

namespace only2d
{
	const luaL_Reg LuaData::functions[] =
	{
		{ "assign", assign },
		{ "getBuffer", getBuffer },
		{ "getSize", getSize },
		{ "at", at },
		{ nullptr, nullptr }
	};

	void LuaData::openType(lua_State *L)
	{
		Lua::beginType(L, LuaType::Data);
		Lua::pushFunctions(L, functions);
		Lua::finishType(L);
	}

	int32_t LuaData::assign(lua_State *L)
	{
		auto data = Lua::getObject<Data>(L, 1, LuaType::Data);
		size_t size;
		auto buffer = Lua::getBuffer(L, 2, size);
		auto offset = static_cast<size_t>(Lua::optionalInteger(L, 3));
		data->assign(buffer, size, offset);
		return 0;
	}

	int32_t LuaData::getBuffer(lua_State *L)
	{
		auto data = Lua::getObject<Data>(L, 1, LuaType::Data);
		auto offset = static_cast<size_t>(Lua::optionalInteger(L, 2));
		auto buffer = data->getBuffer(offset);
		Lua::pushBuffer(L, buffer, data->getSize() - offset);
		return 1;
	}

	int32_t LuaData::getSize(lua_State *L)
	{
		auto data = Lua::getObject<Data>(L, 1, LuaType::Data);
		Lua::pushInteger(L, data->getSize());
		return 1;
	}

	int32_t LuaData::at(lua_State *L)
	{
		auto data = Lua::getObject<Data>(L, 1, LuaType::Data);
		auto index = static_cast<size_t>(Lua::optionalInteger(L, 2));
		Lua::pushBuffer(L, &data->operator[](index), 1);
		return 1;
	}
}
