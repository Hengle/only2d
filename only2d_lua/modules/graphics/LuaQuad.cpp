//
// Created by leafnsand on 2015/7/21.
//

#include "LuaQuad.h"

#include "modules/graphics/Quad.h"

namespace only2d
{
	const luaL_Reg LuaQuad::functions[] =
	{
		{ "draw", draw },
		{ "getWidth", getWidth },
		{ "setWidth", setWidth },
		{ "getHeight", getHeight },
		{ "setHeight", setHeight },
		{ nullptr, nullptr }
	};

	void LuaQuad::openType(lua_State *L)
	{
		Lua::beginType(L, LuaType::Quad);
		Lua::pushFunctions(L, functions);
		Lua::finishType(L, LuaType::Drawable);
	}

	int32_t LuaQuad::draw(lua_State *L)
	{
		auto image = Lua::getObject<Quad>(L, 1, LuaType::Quad);
		image->draw();
		return 0;
	}

	int32_t LuaQuad::getWidth(lua_State *L)
	{
		auto image = Lua::getObject<Quad>(L, 1, LuaType::Quad);
		Lua::pushInteger(L, image->getWidth());
		return 1;
	}

	int32_t LuaQuad::setWidth(lua_State *L)
	{
		auto image = Lua::getObject<Quad>(L, 1, LuaType::Quad);
		auto width = static_cast<int32_t>(Lua::getInteger(L, 2));
		image->setWidth(width);
		return 0;
	}

	int32_t LuaQuad::getHeight(lua_State *L)
	{
		auto image = Lua::getObject<Quad>(L, 1, LuaType::Quad);
		Lua::pushInteger(L, image->getHeight());
		return 1;
	}

	int32_t LuaQuad::setHeight(lua_State *L)
	{
		auto image = Lua::getObject<Quad>(L, 1, LuaType::Quad);
		auto height = static_cast<int32_t>(Lua::getInteger(L, 2));
		image->setHeight(height);
		return 0;
	}
}