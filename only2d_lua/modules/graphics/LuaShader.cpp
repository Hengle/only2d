#include "LuaShader.h"

#include "modules/graphics/Shader.h"

namespace only2d
{
	const luaL_Reg LuaShader::functions[] =
	{
		{ "match", match },
		{ "setAttributeData", setAttributeData },
		{ "setUniformIntData", setUniformIntData },
		{ "setUniformFloatData", setUniformFloatData },
		{ "setUniformMatrixData", setUniformMatrixData },
		{ "attach", attach },
		{ "detach", detach },
		{ nullptr, nullptr }
	};

	void LuaShader::openType(lua_State *L)
	{
		Lua::beginType(L, LuaType::Shader);
		Lua::pushFunctions(L, functions);
		Lua::finishType(L);
	}

	int32_t LuaShader::match(lua_State *L)
	{
		auto shader = Lua::getObject<Shader>(L, 1, LuaType::Shader);
		auto vertex = Lua::getString(L, 2);
		auto fragment = Lua::getString(L, 3);
		Lua::pushBoolean(L, shader->match(vertex, fragment));
		return 1;
	}

	int32_t LuaShader::setAttributeData(lua_State *L)
	{
		auto shader = Lua::getObject<Shader>(L, 1, LuaType::Shader);
		auto name = Lua::getString(L, 2);
		auto size = static_cast<GLint>(Lua::getInteger(L, 3));
		auto type = static_cast<GLenum>(Lua::getInteger(L, 4));
		auto normalized = Lua::getBoolean(L, 5);
		auto stride = static_cast<GLsizei>(Lua::getInteger(L, 6));
		auto data = Lua::getObject<Data>(L, 7, LuaType::Data);
		shader->setAttributeData(name, size, type, normalized, stride, data->getBuffer());
		return 0;
	}

	int32_t LuaShader::setUniformIntData(lua_State *L)
	{
		auto shader = Lua::getObject<Shader>(L, 1, LuaType::Shader);
		auto name = Lua::getString(L, 2);
		auto size = Lua::getStackSize(L) - 1;
		std::vector<int32_t> data;
		for (auto offset = 0; offset < size; ++offset)
		{
			data.push_back(static_cast<int32_t>(Lua::getInteger(L, 3 + offset)));
		}
		shader->setUniformIntData(name, data);
		return 0;
	}

	int32_t LuaShader::setUniformFloatData(lua_State *L)
	{
		auto shader = Lua::getObject<Shader>(L, 1, LuaType::Shader);
		auto name = Lua::getString(L, 2);
		auto size = Lua::getStackSize(L) - 1;
		std::vector<float> data;
		for (auto offset = 0; offset < size; ++offset)
		{
			data.push_back(static_cast<float>(Lua::getNumber(L, 3 + offset)));
		}
		shader->setUniformFloatData(name, data);
		return 0;
	}

	int32_t LuaShader::setUniformMatrixData(lua_State *L)
	{
		auto shader = Lua::getObject<Shader>(L, 1, LuaType::Shader);
		auto name = Lua::getString(L, 2);
		auto data = Lua::getNumberVector<float>(L, 3, 16);
		Matrix matrix;
		matrix.assign(data.data());
		shader->setUniformMatrixData(name, matrix);
		return 0;
	}

	int32_t LuaShader::attach(lua_State *L)
	{
		auto shader = Lua::getObject<Shader>(L, 1, LuaType::Shader);
		shader->attach();
		return 0;
	}

	int32_t LuaShader::detach(lua_State *L)
	{
		auto shader = Lua::getObject<Shader>(L, 1, LuaType::Shader);
		shader->detach();
		return 0;
	}
}
