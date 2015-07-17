//
// Created by leafnsand on 2015/7/13.
//

#include "LuaTexture.h"
#include "LuaTextureData.h"

#include "modules/texture/Texture.h"

namespace only2d
{
	const luaL_Reg LuaTexture::functions[] =
	{
		{ "createTextureData", createTextureData },
		{ nullptr, nullptr }
	};

	void LuaTexture::openModule(lua_State *L)
	{
		Lua::beginModule(L, LuaModule::Texture);
		Lua::pushFunctions(L, functions);
		Lua::finishModule(L, LuaModule::Texture);
		LuaTextureData::openType(L);
	}

	int32_t LuaTexture::createTextureData(lua_State *L)
	{
		auto texture = Module::getInstance<Texture>(ModuleType::TEXTURE);
		auto data = Lua::optionalObject<Data>(L, 1, LuaType::Data);
		if (data == nullptr)
		{
			auto width = static_cast<int32_t>(Lua::getInteger(L, 1));
			auto height = static_cast<int32_t>(Lua::getInteger(L, 2));
			auto color = static_cast<int32_t>(Lua::getInteger(L, 3));
			Lua::pushObject(L, LuaType::TextureData, texture->createTextureData(width, height, intToColor(color)));
		}
		else
		{
			Lua::pushObject(L, LuaType::TextureData, texture->createTextureData(data));
		}
		return 1;
	}
}
