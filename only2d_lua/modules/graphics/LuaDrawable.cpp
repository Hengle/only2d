//
// Created by leafnsand on 2015/7/16.
//

#include "LuaDrawable.h"
#include "LuaBlendMode.h"

#include "modules/graphics/Drawable.h"

namespace only2d
{
	const luaL_Reg LuaDrawable::functions[] =
	{
		{ "getX", getX },
		{ "setX", setX },
		{ "getY", getY },
		{ "setY", setY },
		{ "getRotation", getRotation },
		{ "setRotation", setRotation },
		{ "getScaleX", getScaleX },
		{ "setScaleX", setScaleX },
		{ "getScaleY", getScaleY },
		{ "setScaleY", setScaleY },
		{ "getOffsetX", getOffsetX },
		{ "setOffsetX", setOffsetX },
		{ "getOffsetY", getOffsetY },
		{ "setOffsetY", setOffsetY },
		{ "getSkewX", getSkewX },
		{ "setSkewX", setSkewX },
		{ "getSkewY", getSkewY },
		{ "setSkewY", setSkewY },
		{ "getAlpha", getAlpha },
		{ "setAlpha", setAlpha },
		{ "isVisible", isVisible },
		{ "setVisible", setVisible },
		{ "getColor", getColor },
		{ "setColor", setColor },
		{ "getBlendMode", getBlendMode },
		{ "setBlendMode", setBlendMode },
		{ nullptr, nullptr }
	};

	void LuaDrawable::openType(lua_State *L)
	{
		Lua::beginType(L, LuaType::Drawable);
		Lua::pushFunctions(L, functions);
		Lua::finishType(L);
	}

	int32_t LuaDrawable::getX(lua_State *L)
	{
		auto drawable = Lua::getObject<Drawable>(L, 1, LuaType::Drawable);
		Lua::pushNumber(L, drawable->getX());
		return 1;
	}

	int32_t LuaDrawable::setX(lua_State *L)
	{
		auto drawable = Lua::getObject<Drawable>(L, 1, LuaType::Drawable);
		auto x = static_cast<float>(Lua::getNumber(L, 2));
		drawable->setX(x);
		return 0;
	}

	int32_t LuaDrawable::getY(lua_State *L)
	{
		auto drawable = Lua::getObject<Drawable>(L, 1, LuaType::Drawable);
		Lua::pushNumber(L, drawable->getY());
		return 1;
	}

	int32_t LuaDrawable::setY(lua_State *L)
	{
		auto drawable = Lua::getObject<Drawable>(L, 1, LuaType::Drawable);
		auto y = static_cast<float>(Lua::getNumber(L, 2));
		drawable->setY(y);
		return 0;
	}

	int32_t LuaDrawable::getRotation(lua_State *L)
	{
		auto drawable = Lua::getObject<Drawable>(L, 1, LuaType::Drawable);
		Lua::pushNumber(L, drawable->getRotation());
		return 1;
	}

	int32_t LuaDrawable::setRotation(lua_State *L)
	{
		auto drawable = Lua::getObject<Drawable>(L, 1, LuaType::Drawable);
		auto rotation = static_cast<float>(Lua::getNumber(L, 2));
		drawable->setRotation(rotation);
		return 0;
	}

	int32_t LuaDrawable::getScaleX(lua_State *L)
	{
		auto drawable = Lua::getObject<Drawable>(L, 1, LuaType::Drawable);
		Lua::pushNumber(L, drawable->getScaleX());
		return 1;
	}

	int32_t LuaDrawable::setScaleX(lua_State *L)
	{
		auto drawable = Lua::getObject<Drawable>(L, 1, LuaType::Drawable);
		auto scaleX = static_cast<float>(Lua::getNumber(L, 2));
		drawable->setScaleX(scaleX);
		return 0;
	}

	int32_t LuaDrawable::getScaleY(lua_State *L)
	{
		auto drawable = Lua::getObject<Drawable>(L, 1, LuaType::Drawable);
		Lua::pushNumber(L, drawable->getScaleY());
		return 1;
	}

	int32_t LuaDrawable::setScaleY(lua_State *L)
	{
		auto drawable = Lua::getObject<Drawable>(L, 1, LuaType::Drawable);
		auto scaleY = static_cast<float>(Lua::getNumber(L, 2));
		drawable->setScaleY(scaleY);
		return 0;
	}

	int32_t LuaDrawable::getOffsetX(lua_State *L)
	{
		auto drawable = Lua::getObject<Drawable>(L, 1, LuaType::Drawable);
		Lua::pushNumber(L, drawable->getOffsetX());
		return 1;
	}

	int32_t LuaDrawable::setOffsetX(lua_State *L)
	{
		auto drawable = Lua::getObject<Drawable>(L, 1, LuaType::Drawable);
		auto offsetX = static_cast<float>(Lua::getNumber(L, 2));
		drawable->setOffsetX(offsetX);
		return 0;
	}

	int32_t LuaDrawable::getOffsetY(lua_State *L)
	{
		auto drawable = Lua::getObject<Drawable>(L, 1, LuaType::Drawable);
		Lua::pushNumber(L, drawable->getOffsetY());
		return 1;
	}

	int32_t LuaDrawable::setOffsetY(lua_State *L)
	{
		auto drawable = Lua::getObject<Drawable>(L, 1, LuaType::Drawable);
		auto offsetY = static_cast<float>(Lua::getNumber(L, 2));
		drawable->setOffsetY(offsetY);
		return 0;
	}

	int32_t LuaDrawable::getSkewX(lua_State *L)
	{
		auto drawable = Lua::getObject<Drawable>(L, 1, LuaType::Drawable);
		Lua::pushNumber(L, drawable->getSkewX());
		return 1;
	}

	int32_t LuaDrawable::setSkewX(lua_State *L)
	{
		auto drawable = Lua::getObject<Drawable>(L, 1, LuaType::Drawable);
		auto skewX = static_cast<float>(Lua::getNumber(L, 2));
		drawable->setSkewX(skewX);
		return 0;
	}

	int32_t LuaDrawable::getSkewY(lua_State *L)
	{
		auto drawable = Lua::getObject<Drawable>(L, 1, LuaType::Drawable);
		Lua::pushNumber(L, drawable->getSkewY());
		return 1;
	}

	int32_t LuaDrawable::setSkewY(lua_State *L)
	{
		auto drawable = Lua::getObject<Drawable>(L, 1, LuaType::Drawable);
		auto skewY = static_cast<float>(Lua::getNumber(L, 2));
		drawable->setSkewY(skewY);
		return 0;
	}

	int32_t LuaDrawable::getAlpha(lua_State *L)
	{
		auto drawable = Lua::getObject<Drawable>(L, 1, LuaType::Drawable);
		Lua::pushNumber(L, drawable->getAlpha());
		return 1;
	}

	int32_t LuaDrawable::setAlpha(lua_State *L)
	{
		auto drawable = Lua::getObject<Drawable>(L, 1, LuaType::Drawable);
		auto alpha = static_cast<float>(Lua::getNumber(L, 2));
		drawable->setAlpha(alpha);
		return 0;
	}

	int32_t LuaDrawable::isVisible(lua_State *L)
	{
		auto drawable = Lua::getObject<Drawable>(L, 1, LuaType::Drawable);
		Lua::pushBoolean(L, drawable->isVisible());
		return 1;
	}

	int32_t LuaDrawable::setVisible(lua_State *L)
	{
		auto drawable = Lua::getObject<Drawable>(L, 1, LuaType::Drawable);
		auto visible = Lua::getBoolean(L, 2);
		drawable->setVisible(visible);
		return 0;
	}

	int32_t LuaDrawable::getColor(lua_State *L)
	{
		auto drawable = Lua::getObject<Drawable>(L, 1, LuaType::Drawable);
		Lua::pushInteger(L, colorToInt(drawable->getColor()));
		return 1;
	}

	int32_t LuaDrawable::setColor(lua_State *L)
	{
		auto drawable = Lua::getObject<Drawable>(L, 1, LuaType::Drawable);
		auto color = static_cast<int32_t>(Lua::getInteger(L, 2));
		drawable->setColor(intToColor(color));
		return 0;
	}

	int32_t LuaDrawable::getBlendMode(lua_State *L)
	{
		auto drawable = Lua::getObject<Drawable>(L, 1, LuaType::Drawable);
		Lua::pushEnum<BlendMode>(L, drawable->getBlendMode());
		return 1;
	}

	int32_t LuaDrawable::setBlendMode(lua_State *L)
	{
		auto drawable = Lua::getObject<Drawable>(L, 1, LuaType::Drawable);
		auto blendMode = Lua::getEnum<BlendMode>(L, 2);
		drawable->setBlendMode(blendMode);
		return 0;
	}
}
