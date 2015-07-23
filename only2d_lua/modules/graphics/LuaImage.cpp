#include "LuaImage.h"

#include "modules/graphics/Image.h"

namespace only2d
{
	const luaL_Reg LuaImage::functions[] =
	{
		{ "draw", draw },
		{ "getImageData", getImageData },
		{ "setImageData", setImageData },
		{ "getHeight", getHeight },
		{ "setHeight", setHeight },
		{ "getWidth", getWidth },
		{ "setWidth", setWidth },
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

	int32_t LuaImage::getImageData(lua_State *L)
	{
		auto image = Lua::getObject<Image>(L, 1, LuaType::Image);
		Lua::pushObject(L, LuaType::ImageData, image->getImageData());
		return 1;
	}

	int32_t LuaImage::setImageData(lua_State *L)
	{
		auto image = Lua::getObject<Image>(L, 1, LuaType::Image);
		auto imageData = Lua::getObject<ImageData>(L, 2, LuaType::ImageData);
		image->setImageData(imageData);
		return 0;
	}

	int32_t LuaImage::getHeight(lua_State *L)
	{
		auto image = Lua::getObject<Image>(L, 1, LuaType::Image);
		Lua::pushNumber(L, image->getHeight());
		return 1;
	}

	int32_t LuaImage::setHeight(lua_State *L)
	{
		auto image = Lua::getObject<Image>(L, 1, LuaType::Image);
		auto height = static_cast<float>(Lua::getNumber(L, 2));
		image->setHeight(height);
		return 0;
	}

	int32_t LuaImage::getWidth(lua_State *L)
	{
		auto image = Lua::getObject<Image>(L, 1, LuaType::Image);
		Lua::pushNumber(L, image->getWidth());
		return 1;
	}

	int32_t LuaImage::setWidth(lua_State *L)
	{
		auto image = Lua::getObject<Image>(L, 1, LuaType::Image);
		auto width = static_cast<float>(Lua::getNumber(L, 2));
		image->setWidth(width);
		return 0;
	}
}
