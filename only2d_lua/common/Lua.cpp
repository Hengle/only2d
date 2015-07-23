#include "Lua.h"
#include "LuaData.h"

#include "common/Console.h"

#include "modules/application/LuaApplication.h"
#include "modules/event/LuaEvent.h"
#include "modules/filesystem/LuaFileSystem.h"
#include "modules/graphics/LuaGraphics.h"
#include "modules/keyboard/LuaKeyboard.h"
#include "modules/texture/LuaTexture.h"
#include "modules/timer/LuaTimer.h"
#include "modules/window/LuaWindow.h"

namespace only2d
{
	const std::string Lua::invalid = "Invalid";

	bool Lua::isValid(LuaType type)
	{
		return type > LuaType::MinInvalid && type < LuaType::MaxInvalid;
	}

	bool Lua::isValid(LuaModule module)
	{
		return module > LuaModule::MinInvalid && module < LuaModule::MaxInvalid;
	}

	const std::string &Lua::getName(LuaType type)
	{
		auto iterator = type2name.find(type);
		if (iterator != type2name.end())
		{
			return iterator->second;
		}
		return invalid;
	}

	const std::string &Lua::getName(LuaModule module)
	{
		auto iterator = module2name.find(module);
		if (iterator != module2name.end())
		{
			return iterator->second;
		}
		return invalid;
	}

	const std::map<LuaType, std::string> Lua::type2name =
	{
		{ LuaType::Data, "only2d.Data" },
		{ LuaType::File, "only2d.File" },
		{ LuaType::FileData, "only2d.FileData" },
		{ LuaType::Drawable, "only2d.Drawable" },
		{ LuaType::Image, "only2d.Image" },
		{ LuaType::ImageData, "only2d.ImageData" },
		{ LuaType::Shader, "only2d.Shader" },
		{ LuaType::TextureData, "only2d.TextureData" },
	};

	const std::map<LuaModule, std::string> Lua::module2name =
	{
		{ LuaModule::Only2D, "only2d" },
		{ LuaModule::Application, "application" },
		{ LuaModule::Event, "event" },
		{ LuaModule::FileSystem, "filesystem" },
		{ LuaModule::Graphics, "graphics" },
		{ LuaModule::Keyboard, "keyboard" },
		{ LuaModule::Texture, "texture" },
		{ LuaModule::Timer, "timer" },
		{ LuaModule::Window, "window" },
	};

	void Lua::protectedCall(lua_State *L)
	{
		auto lua_error = lua_pcall(L, 0, 0, 0);
		switch (lua_error)
		{
		case LUA_OK:
			break;
		case LUA_ERRRUN:
			Console::error << "[Lua] lua runtime error: " << lua_tostring(L, -1) << Console::endl;
			break;
		case LUA_ERRMEM:
			Console::error << "[Lua] lua memory error" << Console::endl;
			break;
		case LUA_ERRERR:
			Console::error << "[Lua] lua error" << Console::endl;
			break;
		case LUA_ERRGCMM:
			Console::error << "[Lua] lua gc error" << Console::endl;
			break;
		default:
			Console::error << "[Lua] lua unknown error" << Console::endl;
			break;
		};
	}

	bool Lua::checkMetaTable(lua_State *L, int32_t index)
	{
		if (lua_getmetatable(L, -1) == 0)
		{
			return false;
		}
		return lua_rawequal(L, -1, index) == 1 || checkMetaTable(L, index);
	}

	int32_t Lua::newIndex(lua_State *L)
	{
		lua_getglobal(L, getName(LuaModule::Only2D).c_str());
		auto equal = (lua_rawequal(L, 1, -1) == 1);
		lua_pop(L, 1);
		if (equal)
		{
			std::string key = lua_tostring(L, 2);
			if (key == "initialize" || key == "finalize" || key == "update")
			{
				lua_getmetatable(L, 1);
				lua_pushstring(L, key.c_str());
				lua_pushvalue(L, 3);
				lua_rawset(L, -3);
				lua_pop(L, 1);
				return 0;
			}
		}
		return luaL_error(L, "try to add new index of system table");
	}

	int32_t Lua::gc(lua_State *L)
	{
		auto luaObject = static_cast<LuaObject *>(lua_touserdata(L, 1));
		if (luaObject != nullptr)
		{
			luaObject->object.reset();
		}
		return 0;
	}

	int32_t Lua::toModuleString(lua_State *L)
	{
		auto luaModule = static_cast<LuaModule *>(lua_touserdata(L, 1));
		if (luaModule != nullptr)
		{
			auto name = getName(*luaModule);
			lua_pushstring(L, name.c_str());
		}
		else
		{
			lua_pushstring(L, "unknown module");
		}
		return 1;
	}

	int32_t Lua::toTypeString(lua_State *L)
	{
		auto luaObject = static_cast<LuaObject *>(lua_touserdata(L, 1));
		if (luaObject != nullptr)
		{
			auto name = getName(luaObject->type);
			lua_pushstring(L, name.c_str());
		}
		else
		{
			lua_pushstring(L, "unknown type");
		}
		return 1;
	}

	int32_t Lua::equal(lua_State *L)
	{
		auto luaObject1 = static_cast<LuaObject *>(lua_touserdata(L, 1));
		auto luaObject2 = static_cast<LuaObject *>(lua_touserdata(L, 2));
		lua_pushboolean(L, luaObject1 && luaObject2 && luaObject1->object == luaObject2->object);
		return 1;
	}

	void Lua::open(lua_State *L)
	{
		auto function = [](lua_State *l) -> int32_t
			{
				luaL_openlibs(l);

				beginGlobal(l, LuaModule::Only2D);

				LuaData::openType(l);

				LuaApplication::openModule(l);
				LuaEvent::openModule(l);
				LuaFileSystem::openModule(l);
				LuaGraphics::openModule(l);
				LuaKeyboard::openModule(l);
				LuaTexture::openModule(l);
				LuaTimer::openModule(l);
				LuaWindow::openModule(l);

				finishGlobal(l, LuaModule::Only2D);

				return 0;
			};
		lua_pushcfunction(L, function);
		protectedCall(L);
	}

	void Lua::run(lua_State *L, const std::string &filename)
	{
		auto lua_error = luaL_loadfile(L, filename.c_str());
		switch (lua_error)
		{
		case LUA_OK:
			protectedCall(L);
			break;
		case LUA_ERRSYNTAX:
			Console::error << "[Lua] load main.lua, syntax error." << Console::endl;
			break;
		case LUA_ERRMEM:
			Console::error << "[Lua] load main.lua error, no enough memory." << Console::endl;
			break;
		case LUA_ERRGCMM:
			Console::error << "[Lua] load main.lua, gc error." << Console::endl;
			break;
		default:
			Console::error << "[Lua] load main.lua, unknown error." << Console::endl;
			break;
		}
	}

	void Lua::call(lua_State *L, const std::string &name)
	{
		lua_getglobal(L, getName(LuaModule::Only2D).c_str());
		luaL_getmetafield(L, -1, name.c_str());
		if (lua_isfunction(L, -1))
		{
			protectedCall(L);
		}
		lua_pop(L, 1);
		dump(L);
	}

	int32_t Lua::getStackSize(lua_State *L)
	{
		return lua_gettop(L);
	}

	void Lua::dump(lua_State *L)
	{
		auto top = lua_gettop(L);
		for (auto i = 1; i <= top; ++i)
		{
			auto type = lua_type(L, i);
			switch (type)
			{
			case LUA_TNIL:
				Console::debug << "[nil]" << Console::endl;
				break;
			case LUA_TNUMBER:
				Console::debug << "[number] " << lua_tonumber(L, i) << Console::endl;
				break;
			case LUA_TSTRING:
				Console::debug << "[string] " << lua_tostring(L, i) << Console::endl;
				break;
			case LUA_TTABLE:
				Console::debug << "[table]" << Console::endl;
				break;
			case LUA_TFUNCTION:
				Console::debug << "[function]" << Console::endl;
				break;
			case LUA_TUSERDATA:
				{
					auto luaObject = static_cast<LuaObject *>(lua_touserdata(L, i));
					Console::debug << "[userdata] " << getName(luaObject->type) << Console::endl;
					break;
				}
			case LUA_TBOOLEAN:
				Console::debug << "[boolean] " << lua_toboolean(L, i) << Console::endl;
				break;
			default:
				Console::debug << "[unknown] " << Console::endl;
				break;
			}
		}
	}

	void Lua::beginGlobal(lua_State *L, LuaModule module)
	{
		if (!isValid(module))
		{
			Console::error << "[Lua] open invalid global module " << getName(module) << Console::endl;
		}
		auto luaModule = static_cast<LuaModule *>(lua_newuserdata(L, sizeof(LuaModule)));
		*luaModule = module;
		auto name = getName(module);
		luaL_newmetatable(L, name.c_str());
	}

	void Lua::finishGlobal(lua_State *L, LuaModule module)
	{
		if (!isValid(module))
		{
			Console::error << "[Lua] close invalid global module " << getName(module) << Console::endl;
		}
		auto name = getName(module);
		lua_pushvalue(L, -1);
		lua_setfield(L, -2, "__index");
		lua_pushcfunction(L, newIndex);
		lua_setfield(L, -2, "__newindex");
		lua_pushcfunction(L, toModuleString);
		lua_setfield(L, -2, "__tostring");
		lua_setmetatable(L, -2);
		lua_setglobal(L, name.c_str());
	}

	void Lua::beginModule(lua_State *L, LuaModule module)
	{
		if (!isValid(module))
		{
			Console::error << "[Lua] open invalid module " << getName(module) << Console::endl;
		}
		auto luaModule = static_cast<LuaModule *>(lua_newuserdata(L, sizeof(LuaModule)));
		*luaModule = module;
		auto name = getName(module);
		luaL_newmetatable(L, name.c_str());
	}

	void Lua::finishModule(lua_State *L, LuaModule module)
	{
		if (!isValid(module))
		{
			Console::error << "[Lua] close invalid module " << getName(module) << Console::endl;
		}
		auto name = getName(module);
		lua_pushvalue(L, -1);
		lua_setfield(L, -2, "__index");
		lua_pushcfunction(L, newIndex);
		lua_setfield(L, -2, "__newindex");
		lua_pushcfunction(L, toModuleString);
		lua_setfield(L, -2, "__tostring");
		lua_setmetatable(L, -2);
		lua_setfield(L, -2, name.c_str());
	}

	void Lua::beginType(lua_State *L, LuaType type)
	{
		if (!isValid(type))
		{
			Console::error << "[Lua] open invalid type " << getName(type) << Console::endl;
		}
		auto name = getName(type);
		luaL_newmetatable(L, name.c_str());
	}

	void Lua::finishType(lua_State *L, LuaType base)
	{
		lua_pushvalue(L, -1);
		lua_setfield(L, -2, "__index");
		lua_pushcfunction(L, newIndex);
		lua_setfield(L, -2, "__newindex");
		lua_pushcfunction(L, gc);
		lua_setfield(L, -2, "__gc");
		lua_pushcfunction(L, equal);
		lua_setfield(L, -2, "__eq");
		lua_pushcfunction(L, toTypeString);
		lua_setfield(L, -2, "__tostring");
		if (isValid(base))
		{
			luaL_setmetatable(L, getName(base).c_str());
		}
		lua_pop(L, 1);
	}

	void Lua::beginEnum(lua_State *L)
	{
		lua_createtable(L, 0, 0);
	}

	void Lua::finishEnum(lua_State *L, const char *name)
	{
		lua_setfield(L, -2, name);
	}

	void Lua::setField(lua_State *L, int32_t index, const char *name)
	{
		lua_setfield(L, index, name);
	}

	void Lua::pushNil(lua_State *L)
	{
		lua_pushnil(L);
	}

	void Lua::pushFunctions(lua_State *L, const luaL_Reg functions[])
	{
		luaL_setfuncs(L, functions, 0);
	}

	void Lua::pushInteger(lua_State *L, int64_t value)
	{
		lua_pushinteger(L, value);
	}

	void Lua::pushBoolean(lua_State *L, bool value)
	{
		lua_pushboolean(L, value);
	}

	void Lua::pushNumber(lua_State *L, double value)
	{
		lua_pushnumber(L, value);
	}

	void Lua::pushString(lua_State *L, const std::string &string)
	{
		lua_pushstring(L, string.c_str());
	}

	void Lua::pushBuffer(lua_State *L, const uint8_t *buffer, size_t size)
	{
		lua_pushlstring(L, reinterpret_cast<const char *>(buffer), size);
	}

	void Lua::pushObject(lua_State *L, LuaType type, std::shared_ptr<void> object)
	{
		if (isValid(type))
		{
			auto name = getName(type);
			auto luaObject = static_cast<LuaObject *>(lua_newuserdata(L, sizeof(LuaObject)));
			new(luaObject) LuaObject();
			luaObject->type = type;
			luaObject->object = object;
			luaL_setmetatable(L, name.c_str());
		}
		else
		{
			lua_pushnil(L);
		}
	}

	int64_t Lua::getInteger(lua_State *L, int32_t index)
	{
		return luaL_checkinteger(L, index);
	}

	bool Lua::getBoolean(lua_State *L, int32_t index)
	{
		return 0 != lua_toboolean(L, index);
	}

	double Lua::getNumber(lua_State *L, int32_t index)
	{
		return luaL_checknumber(L, index);
	}

	std::string Lua::getString(lua_State *L, int32_t index)
	{
		return luaL_checkstring(L, index);
	}

	std::vector<std::pair<std::string, std::string>> Lua::getStringTable(lua_State *L, int32_t index)
	{
		std::vector<std::pair<std::string, std::string>> result;
		auto toString = [&](int32_t i) -> std::string
			{
				std::string string;
				lua_pushvalue(L, i);
				switch (lua_type(L, -1))
				{
				case LUA_TBOOLEAN:
					string = (lua_toboolean(L, -1) == 0) ? "false" : "true";
					break;
				case LUA_TNUMBER:
				case LUA_TSTRING:
					string = lua_tostring(L, -1);
					break;
				default:
					break;
				}
				lua_pop(L, 1);
				return string;
			};
		if (lua_type(L, index) == LUA_TTABLE)
		{
			lua_pushnil(L);
			while (lua_next(L, index) != 0)
			{
				result.push_back(std::pair<std::string, std::string>(toString(-2), toString(-1)));
				lua_pop(L, 1);
			}
		}
		else
		{
			luaL_argerror(L, index, "expect table");
		}
		return result;
	}

	const uint8_t *Lua::getBuffer(lua_State *L, int32_t index, size_t &size)
	{
		return reinterpret_cast<const uint8_t *>(luaL_checklstring(L, index, &size));
	}

	int64_t Lua::optionalInteger(lua_State *L, int32_t index, int64_t value)
	{
		return luaL_optinteger(L, index, value);
	}

	bool Lua::optionalBoolean(lua_State *L, int32_t index, bool value)
	{
		return 0 != luaL_opt(L, lua_toboolean, index, value);
	}

	double Lua::optionalNumber(lua_State *L, int32_t index, double value)
	{
		return luaL_optnumber(L, index, value);
	}

	std::string Lua::optionalString(lua_State *L, int32_t index, const char *value)
	{
		return luaL_optstring(L, index, value);
	}
}
