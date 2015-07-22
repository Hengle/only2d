#include "LuaFile.h"

#include "modules/filesystem/File.h"

namespace only2d
{
	const luaL_Reg LuaFile::functions[] =
	{
		{ "good", good },
		{ "getSize", getSize },
		{ "read", read },
		{ "write", write },
		{ "flush", flush },
		{ "eof", eof },
		{ "tell", tell },
		{ "available", available },
		{ "seek", seek },
		{ nullptr, nullptr }
	};

	void LuaFile::openType(lua_State *L)
	{
		Lua::beginType(L, LuaType::File);
		Lua::pushFunctions(L, functions);
		Lua::finishType(L);
	}

	int32_t LuaFile::good(lua_State *L)
	{
		auto file = Lua::getObject<File>(L, 1, LuaType::File);
		Lua::pushBoolean(L, file->good());
		return 1;
	}

	int32_t LuaFile::getSize(lua_State *L)
	{
		auto file = Lua::getObject<File>(L, 1, LuaType::File);
		Lua::pushInteger(L, static_cast<int64_t>(file->getSize()));
		return 1;
	}

	int32_t LuaFile::read(lua_State *L)
	{
		auto file = Lua::getObject<File>(L, 1, LuaType::File);
		auto mode = Lua::optionalEnum<FileReadMode>(L, 2, FileReadMode::MinInvalid);
		if (mode > FileReadMode::MinInvalid && mode < FileReadMode::MaxInvalid)
		{
			auto size = Lua::optionalInteger(L, 3, 0);
			auto data = file->read(mode, static_cast<size_t>(size));
			Lua::pushObject(L, LuaType::FileData, data);
		}
		else
		{
			std::string line;
			if (file->read(line))
			{
				Lua::pushString(L, line);
			}
			else
			{
				Lua::pushNil(L);
			}
		}
		return 1;
	}

	int32_t LuaFile::write(lua_State *L)
	{
		auto file = Lua::getObject<File>(L, 1, LuaType::File);
		auto data = Lua::optionalObject<FileData>(L, 2, LuaType::FileData);
		if (data)
		{
			Lua::pushBoolean(L, file->write(data));
		}
		else
		{
			auto line = Lua::optionalString(L, 2);
			Lua::pushBoolean(L, file->write(line));
		}
		return 1;
	}

	int32_t LuaFile::flush(lua_State *L)
	{
		auto file = Lua::getObject<File>(L, 1, LuaType::File);
		Lua::pushBoolean(L, file->flush());
		return 1;
	}

	int32_t LuaFile::eof(lua_State *L)
	{
		auto file = Lua::getObject<File>(L, 1, LuaType::File);
		Lua::pushBoolean(L, file->eof());
		return 1;
	}

	int32_t LuaFile::tell(lua_State *L)
	{
		auto file = Lua::getObject<File>(L, 1, LuaType::File);
		Lua::pushInteger(L, static_cast<int64_t>(file->tell()));
		return 1;
	}

	int32_t LuaFile::available(lua_State *L)
	{
		auto file = Lua::getObject<File>(L, 1, LuaType::File);
		Lua::pushInteger(L, static_cast<int64_t>(file->available()));
		return 1;
	}

	int32_t LuaFile::seek(lua_State *L)
	{
		auto file = Lua::getObject<File>(L, 1, LuaType::File);
		auto pos = static_cast<size_t>(Lua::getInteger(L, 2));
		Lua::pushBoolean(L, file->seek(pos));
		return 1;
	}
}
