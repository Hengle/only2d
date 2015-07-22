#include "LuaOnly2D.h"

#include "common/Lua.h"

namespace only2d
{
	LuaOnly2D::LuaOnly2D()
	{
	}

	LuaOnly2D::~LuaOnly2D()
	{
	}

	void LuaOnly2D::initialize()
	{
		auto filesystem = Module::getInstance<FileSystem>(ModuleType::FILESYSTEM);
		auto filename = filesystem->getSourceDir() + "main.lua";
		filesystem.reset();
		L = luaL_newstate();
		if (L == nullptr)
		{
			Console::error << "[LuaOnly2D] create lua vm fail." << Console::endl;
		}
		Lua::open(L);
		Lua::run(L, filename);
		Lua::call(L, "initialize");
	}

	void LuaOnly2D::update(float delta)
	{
		Lua::call(L, "update");
	}

	void LuaOnly2D::finalize()
	{
		Lua::call(L, "finalize");
		lua_close(L);
	}
}
