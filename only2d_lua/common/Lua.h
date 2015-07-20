//
// Created by leafnsand on 2015/7/11.
//

#ifndef ONLY2D_LUA_H
#define ONLY2D_LUA_H

#include "LuaObject.h"

#include "library/lua/lua.hpp"

#include <map>
#include <string>
#include <memory>
#include <vector>

namespace only2d
{
	class Lua
	{
	public:
		static void open(lua_State *L);

		static void run(lua_State *L, const std::string &filename);

		static void call(lua_State *L, const std::string &name);

		static int32_t getStackSize(lua_State *L);

		static void dump(lua_State *L);

		static void beginGlobal(lua_State *L, LuaModule module);

		static void finishGlobal(lua_State *L, LuaModule module);

		static void beginModule(lua_State *L, LuaModule module);

		static void finishModule(lua_State *L, LuaModule module);

		static void beginType(lua_State *L, LuaType type);

		static void finishType(lua_State *L, LuaType base = LuaType::MinInvalid);

		static void beginEnum(lua_State *L);

		static void finishEnum(lua_State *L, const char *name);

		static void setField(lua_State *L, int32_t index, const char *name);

		static void pushNil(lua_State *L);

		static void pushFunctions(lua_State *L, const luaL_Reg functions[]);

		static void pushInteger(lua_State *L, int64_t value);

		static void pushBoolean(lua_State *L, bool value);

		static void pushNumber(lua_State *L, double value);

		static void pushString(lua_State *L, const std::string &string);

		static void pushBuffer(lua_State *L, const uint8_t *buffer, size_t size);

		static void pushObject(lua_State *L, LuaType type, std::shared_ptr<void> object);

		template <typename T>
		static void pushEnum(lua_State *L, T value)
		{
			lua_pushinteger(L, static_cast<lua_Integer>(value));
		}

		static int64_t getInteger(lua_State *L, int32_t index);

		static bool getBoolean(lua_State *L, int32_t index);

		static double getNumber(lua_State *L, int32_t index);

		static std::string getString(lua_State *L, int32_t index);

		static std::vector<std::pair<std::string, std::string>> getStringTable(lua_State *L, int32_t index);

		template <typename T>
		static std::vector<T> getIntegerVector(lua_State *L, int32_t index, int32_t minSize = 0)
		{
			std::vector<T> result(minSize);
			auto toInteger = [&](int32_t i) -> int64_t
				{
					lua_pushvalue(L, i);
					auto value = luaL_checkinteger(L, -1);
					lua_pop(L, 1);
					return value;
				};
			if (lua_type(L, index) == LUA_TTABLE)
			{
				lua_pushnil(L);
				while (lua_next(L, index) != 0)
				{
					auto key = static_cast<size_t>(toInteger(-2));
					if (key > result.size())
					{
						result.resize(key);
					}
					result[key - 1] = static_cast<T>(toInteger(-1));
					lua_pop(L, 1);
				}
			}
			else
			{
				luaL_argerror(L, index, "expect table");
			}
			return result;
		}

		template <typename T>
		static std::vector<T> getNumberVector(lua_State *L, int32_t index, int32_t minSize = 0)
		{
			std::vector<T> result(minSize);
			auto toInteger = [&](int32_t i) -> int64_t
				{
					lua_pushvalue(L, i);
					auto value = luaL_checkinteger(L, -1);
					lua_pop(L, 1);
					return value;
				};
			auto toNumber = [&](int32_t i) -> double
				{
					lua_pushvalue(L, i);
					auto value = luaL_checknumber(L, -1);
					lua_pop(L, 1);
					return value;
				};
			if (lua_type(L, index) == LUA_TTABLE)
			{
				lua_pushnil(L);
				while (lua_next(L, index) != 0)
				{
					auto key = static_cast<size_t>(toInteger(-2));
					if (key > result.size())
					{
						result.resize(key);
					}
					result[key - 1] = static_cast<T>(toNumber(-1));
					lua_pop(L, 1);
				}
			}
			else
			{
				luaL_argerror(L, index, "expect table");
			}
			return result;
		}

		static const uint8_t *getBuffer(lua_State *L, int32_t index, size_t &size);

		template <typename T>
		static std::shared_ptr<T> getObject(lua_State *L, int32_t index, LuaType type)
		{
			auto object = optionalObject<T>(L, index, type);
			if (object == nullptr)
			{
				std::string error = "expect ";
				error += getName(type).c_str();
				luaL_argerror(L, index, error.c_str());
			}
			return object;
		}

		template <typename T>
		static T getEnum(lua_State *L, int32_t index)
		{
			auto invalid = static_cast<T>(0);
			auto value = optionalEnum<T>(L, index, invalid);
			if (value == invalid)
			{
				luaL_argerror(L, index, "expect enum");
			}
			return static_cast<T>(value);
		}

		static int64_t optionalInteger(lua_State *L, int32_t index, int64_t value = 0);

		static bool optionalBoolean(lua_State *L, int32_t index, bool value = false);

		static double optionalNumber(lua_State *L, int32_t index, double value = 0.0);

		static std::string optionalString(lua_State *L, int32_t index, const char *value = "");

		template <typename T>
		static std::shared_ptr<T> optionalObject(lua_State *L, int32_t index, LuaType type, std::shared_ptr<T> value = nullptr)
		{
			if (!lua_isnoneornil(L, index) && isValid(type))
			{
				auto name = getName(type);
				auto luaObject = static_cast<LuaObject *>(lua_touserdata(L, index));
				if (luaObject != nullptr)
				{
					auto top = lua_gettop(L);
					luaL_getmetatable(L, name.c_str());
					lua_pushvalue(L, index);
					if (checkMetaTable(L, top + 1))
					{
						value = std::static_pointer_cast<T>(luaObject->object);
					}
					lua_settop(L, top);
				}
			}
			return value;
		}

		template <typename T>
		static T optionalEnum(lua_State *L, int32_t index, T value)
		{
			auto rawValue = luaL_optinteger(L, index, -1);
			if (rawValue == -1)
			{
				return value;
			}
			return static_cast<T>(rawValue);
		}

		static bool isValid(LuaType type);

		static bool isValid(LuaModule module);

		static const std::string &getName(LuaType type);

		static const std::string &getName(LuaModule module);

		static LuaType getType(const std::string &name);

	protected:
		static int32_t newIndex(lua_State *L);

		static int32_t gc(lua_State *L);

		static int32_t toModuleString(lua_State *L);

		static int32_t toTypeString(lua_State *L);

		static int32_t equal(lua_State *L);

	private:
		static void protectedCall(lua_State *L);

		static bool checkMetaTable(lua_State *L, int32_t index);

	private:
		static const std::map<LuaType, std::string> type2name;

		static const std::map<LuaModule, std::string> module2name;

		static const std::map<std::string, LuaType> name2type;

		static const std::string invalid;
	};
}

#endif //ONLY2D_LUA_H

