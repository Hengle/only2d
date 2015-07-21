//
// Created by leafnsand on 2015/7/16.
//

#include "LuaQuadBatch.h"

#include "modules/graphics/QuadBatch.h"

namespace only2d
{
	const luaL_Reg LuaQuadBatch::functions[] =
	{
		{ "addQuad", addQuad },
		{ "clear", clear },
		{ "draw", draw },
		{ nullptr, nullptr }
	};

	void LuaQuadBatch::openType(lua_State *L)
	{
		Lua::beginType(L, LuaType::QuadBatch);
		Lua::pushFunctions(L, functions);
		Lua::finishType(L, LuaType::Drawable);
	}

	int32_t LuaQuadBatch::addQuad(lua_State *L)
	{
		auto quadBatch = Lua::getObject<QuadBatch>(L, 1, LuaType::QuadBatch);
		auto quad = Lua::getObject<Quad>(L, 2, LuaType::Quad);
		quadBatch->addQuad(quad);
		return 0;
	}

	int32_t LuaQuadBatch::clear(lua_State *L)
	{
		auto quadBatch = Lua::getObject<QuadBatch>(L, 1, LuaType::QuadBatch);
		quadBatch->clear();
		return 0;
	}

	int32_t LuaQuadBatch::draw(lua_State *L)
	{
		auto quadBatch = Lua::getObject<QuadBatch>(L, 1, LuaType::QuadBatch);
		quadBatch->draw();
		return 0;
	}
}
