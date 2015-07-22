#include "LuaFile.h"
#include "LuaFileData.h"
#include "LuaFileReadMode.h"
#include "LuaFileSystem.h"

#include "common/Module.h"

#include "modules/filesystem/FileSystem.h"

namespace only2d
{
	const luaL_Reg LuaFileSystem::functions[] =
	{
		{ "createFile", createFile },
		{ "createBinaryFile", createBinaryFile },
		{ "appendFile", appendFile },
		{ "appendBinaryFile", appendBinaryFile },
		{ "openFile", openFile },
		{ "openBinaryFile", openBinaryFile },
		{ "newFileData", newFileData },
		{ nullptr, nullptr }
	};

	void LuaFileSystem::openModule(lua_State *L)
	{
		Lua::beginModule(L, LuaModule::FileSystem);
		Lua::pushFunctions(L, functions);
		auto filesystem = Module::getInstance<FileSystem>(ModuleType::FILESYSTEM);
		Lua::pushString(L, filesystem->getAppdataDir());
		Lua::setField(L, -2, "appdataDir");
		Lua::pushString(L, filesystem->getSourceDir());
		Lua::setField(L, -2, "sourceDir");
		Lua::pushString(L, filesystem->getSeparator());
		Lua::setField(L, -2, "separator");
		LuaFileReadMode::openEnum(L);
		Lua::finishModule(L, LuaModule::FileSystem);
		LuaFile::openType(L);
		LuaFileData::openType(L);
	}

	int32_t LuaFileSystem::createFile(lua_State *L)
	{
		auto filesystem = Module::getInstance<FileSystem>(ModuleType::FILESYSTEM);
		auto file = filesystem->createFile(Lua::getString(L, 1));
		Lua::pushObject(L, LuaType::File, file);
		file.reset();
		return 1;
	}

	int32_t LuaFileSystem::createBinaryFile(lua_State *L)
	{
		auto filesystem = Module::getInstance<FileSystem>(ModuleType::FILESYSTEM);
		auto file = filesystem->createBinaryFile(Lua::getString(L, 1));
		Lua::pushObject(L, LuaType::File, file);
		file.reset();
		return 1;
	}

	int32_t LuaFileSystem::appendFile(lua_State *L)
	{
		auto filesystem = Module::getInstance<FileSystem>(ModuleType::FILESYSTEM);
		auto file = filesystem->appendFile(Lua::getString(L, 1));
		Lua::pushObject(L, LuaType::File, file);
		file.reset();
		return 1;
	}

	int32_t LuaFileSystem::appendBinaryFile(lua_State *L)
	{
		auto filesystem = Module::getInstance<FileSystem>(ModuleType::FILESYSTEM);
		auto file = filesystem->appendBinaryFile(Lua::getString(L, 1));
		Lua::pushObject(L, LuaType::File, file);
		file.reset();
		return 1;
	}

	int32_t LuaFileSystem::openFile(lua_State *L)
	{
		auto filesystem = Module::getInstance<FileSystem>(ModuleType::FILESYSTEM);
		auto file = filesystem->openFile(Lua::getString(L, 1));
		Lua::pushObject(L, LuaType::File, file);
		file.reset();
		return 1;
	}

	int32_t LuaFileSystem::openBinaryFile(lua_State *L)
	{
		auto filesystem = Module::getInstance<FileSystem>(ModuleType::FILESYSTEM);
		auto file = filesystem->openBinaryFile(Lua::getString(L, 1));
		Lua::pushObject(L, LuaType::File, file);
		file.reset();
		return 1;
	}

	int32_t LuaFileSystem::newFileData(lua_State *L)
	{
		auto filesystem = Module::getInstance<FileSystem>(ModuleType::FILESYSTEM);
		auto fileData = filesystem->newFileData(static_cast<size_t>(Lua::getInteger(L, 1)), Lua::getString(L, 2));
		Lua::pushObject(L, LuaType::FileData, fileData);
		fileData.reset();
		return 1;
	}
}
