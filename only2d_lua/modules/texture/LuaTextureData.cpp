//
// Created by leafnsand on 2015/7/16.
//

#include "LuaTextureData.h"

#include "modules/texture/TextureData.h"

namespace only2d
{
	const luaL_Reg LuaTextureData::functions[] =
	{
		{ "encode", encode },
		{ "decode", decode },
		{ "getWidth", getWidth },
		{ "getHeight", getHeight },
		{ nullptr, nullptr }
	};

	void LuaTextureData::openType(lua_State *L)
	{
		Lua::beginType(L, LuaType::TextureData);
		Lua::pushFunctions(L, functions);
		Lua::finishType(L, LuaType::Data);
	}

	int32_t LuaTextureData::encode(lua_State *L)
	{
		auto textureData = Lua::getObject<TextureData>(L, 1, LuaType::TextureData);
		auto data = Lua::getObject<Data>(L, 1, LuaType::Data);
		textureData->encode(data);
		return 0;
	}

	int32_t LuaTextureData::decode(lua_State *L)
	{
		auto textureData = Lua::getObject<TextureData>(L, 1, LuaType::TextureData);
		auto data = Lua::getObject<Data>(L, 1, LuaType::Data);
		textureData->decode(data);
		return 0;
	}

	int32_t LuaTextureData::getWidth(lua_State *L)
	{
		auto textureData = Lua::getObject<TextureData>(L, 1, LuaType::TextureData);
		Lua::pushInteger(L, textureData->getWidth());
		return 1;
	}

	int32_t LuaTextureData::getHeight(lua_State *L)
	{
		auto textureData = Lua::getObject<TextureData>(L, 1, LuaType::TextureData);
		Lua::pushInteger(L, textureData->getHeight());
		return 1;
	}
}
