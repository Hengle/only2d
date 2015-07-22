#include "LuaImageData.h"

#include "modules/graphics/ImageData.h"

namespace only2d
{
	const luaL_Reg LuaImageData::functions[] =
	{
		{ "bind", bind },
		{ "unbind", unbind },
		{ "getWidth", getWidth },
		{ "setWidth", setWidth },
		{ "getHeight", getHeight },
		{ "setHeight", setHeight },
		{ "getGLTexture", getGLTexture },
		{ "getWrap", getWrap },
		{ "setWrap", setWrap },
		{ "getFilter", getFilter },
		{ "setFilter", setFilter },
		{ nullptr, nullptr }
	};

	void LuaImageData::openType(lua_State *L)
	{
		Lua::beginType(L, LuaType::ImageData);
		Lua::pushFunctions(L, functions);
		Lua::finishType(L);
	}

	int32_t LuaImageData::bind(lua_State *L)
	{
		auto imageData = Lua::getObject<ImageData>(L, 1, LuaType::ImageData);
		imageData->bind();
		return 0;
	}

	int32_t LuaImageData::unbind(lua_State *L)
	{
		auto imageData = Lua::getObject<ImageData>(L, 1, LuaType::ImageData);
		imageData->unbind();
		return 0;
	}

	int32_t LuaImageData::getWidth(lua_State *L)
	{
		auto imageData = Lua::getObject<ImageData>(L, 1, LuaType::ImageData);
		Lua::pushInteger(L, imageData->getWidth());
		return 1;
	}

	int32_t LuaImageData::setWidth(lua_State *L)
	{
		auto imageData = Lua::getObject<ImageData>(L, 1, LuaType::ImageData);
		auto width = static_cast<int32_t>(Lua::getInteger(L, 2));
		imageData->setWidth(width);
		return 0;
	}

	int32_t LuaImageData::getHeight(lua_State *L)
	{
		auto imageData = Lua::getObject<ImageData>(L, 1, LuaType::ImageData);
		Lua::pushInteger(L, imageData->getHeight());
		return 1;
	}

	int32_t LuaImageData::setHeight(lua_State *L)
	{
		auto imageData = Lua::getObject<ImageData>(L, 1, LuaType::ImageData);
		auto height = static_cast<int32_t>(Lua::getInteger(L, 2));
		imageData->setHeight(height);
		return 0;
	}

	int32_t LuaImageData::getGLTexture(lua_State *L)
	{
		auto imageData = Lua::getObject<ImageData>(L, 1, LuaType::ImageData);
		Lua::pushInteger(L, imageData->getGLTexture());
		return 1;
	}

	int32_t LuaImageData::getWrap(lua_State *L)
	{
		auto imageData = Lua::getObject<ImageData>(L, 1, LuaType::ImageData);
		auto wrap = imageData->getWrap();
		Lua::pushEnum<ImageDataWrapMode>(L, wrap.s);
		Lua::pushEnum<ImageDataWrapMode>(L, wrap.t);
		return 2;
	}

	int32_t LuaImageData::setWrap(lua_State *L)
	{
		auto imageData = Lua::getObject<ImageData>(L, 1, LuaType::ImageData);
		ImageDataWrap wrap;
		wrap.s = Lua::getEnum<ImageDataWrapMode>(L, 2);
		wrap.t = Lua::getEnum<ImageDataWrapMode>(L, 3);
		imageData->setWrap(wrap);
		return 0;
	}

	int32_t LuaImageData::getFilter(lua_State *L)
	{
		auto imageData = Lua::getObject<ImageData>(L, 1, LuaType::ImageData);
		auto filter = imageData->getFilter();
		Lua::pushEnum<ImageDataFilterMode>(L, filter.min);
		Lua::pushEnum<ImageDataFilterMode>(L, filter.mag);
		return 2;
	}

	int32_t LuaImageData::setFilter(lua_State *L)
	{
		auto imageData = Lua::getObject<ImageData>(L, 1, LuaType::ImageData);
		ImageDataFilter filter;
		filter.min = Lua::getEnum<ImageDataFilterMode>(L, 2);
		filter.mag = Lua::getEnum<ImageDataFilterMode>(L, 3);
		imageData->setFilter(filter);
		return 0;
	}
}
