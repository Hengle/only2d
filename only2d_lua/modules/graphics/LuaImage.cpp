//
// Created by leafnsand on 2015/7/16.
//

#include "LuaImage.h"

#include "modules/graphics/Image.h"

namespace only2d
{
	const luaL_Reg LuaImage::functions[] =
	{
		{ "draw", draw },
		{ "getWidth", getWidth },
		{ "setWidth", setWidth },
		{ "getHeight", getHeight },
		{ "setHeight", setHeight },
		{ nullptr, nullptr }
	};

	void LuaImage::openType(lua_State *L)
	{
		Lua::beginType(L, LuaType::Image);
		Lua::pushFunctions(L, functions);
		Lua::finishType(L, LuaType::Drawable);
	}

	int32_t LuaImage::draw(lua_State *L)
	{
		auto image = Lua::getObject<Image>(L, 1, LuaType::Image);
		image->draw();
		return 0;
	}

	int32_t LuaImage::getWidth(lua_State *L)
	{
		auto image = Lua::getObject<Image>(L, 1, LuaType::Image);
		Lua::pushInteger(L, image->getWidth());
		return 1;
	}

	int32_t LuaImage::setWidth(lua_State *L)
	{
		auto image = Lua::getObject<Image>(L, 1, LuaType::Image);
		auto width = static_cast<int32_t>(Lua::getInteger(L, 2));
		image->setWidth(width);
		return 0;
	}

	int32_t LuaImage::getHeight(lua_State *L)
	{
		auto image = Lua::getObject<Image>(L, 1, LuaType::Image);
		Lua::pushInteger(L, image->getHeight());
		return 1;
	}

	int32_t LuaImage::setHeight(lua_State *L)
	{
		auto image = Lua::getObject<Image>(L, 1, LuaType::Image);
		auto height = static_cast<int32_t>(Lua::getInteger(L, 2));
		image->setHeight(height);
		return 0;
	}
}
