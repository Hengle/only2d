//
// Created by leafnsand on 2015/7/20.
//

#include "LuaKeyboard.h"
#include "LuaKey.h"

#include "modules/keyboard/Keyboard.h"

namespace only2d
{
	const luaL_Reg LuaKeyboard::functions[] =
	{
		{ "isPressed", isPressed },
		{ nullptr, nullptr }
	};

	void LuaKeyboard::openModule(lua_State *L)
	{
		Lua::beginModule(L, LuaModule::Keyboard);
		Lua::pushFunctions(L, functions);
		LuaKey::openEnum(L);
		Lua::finishModule(L, LuaModule::Keyboard);
	}

	int32_t LuaKeyboard::isPressed(lua_State *L)
	{
		auto keyboard = Module::getInstance<Keyboard>(ModuleType::KEYBOARD);
		auto size = Lua::getStackSize(L);
		std::vector<Key> keys;
		for (auto i = 0; i < size; ++i)
		{
			keys.push_back(Lua::getEnum<Key>(L, 1 + i));
		}
		Lua::pushBoolean(L, keyboard->isPressed(keys));
		return 1;
	}
}