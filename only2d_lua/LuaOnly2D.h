//
// Created by leafnsand on 2015/7/10.
//

#ifndef ONLY2D_LUAONLY2D_H
#define ONLY2D_LUAONLY2D_H

#include "Only2D.h"

#include "library/lua/lua.hpp"

namespace only2d
{
	class LuaOnly2D : public Application
	{
	public:
		LuaOnly2D();

		virtual ~LuaOnly2D();

		virtual void initialize() override;

		virtual void update(float delta) override;

		virtual void finalize() override;

	private:
		lua_State *L;
	};
}

#endif //ONLY2D_LUAONLY2D_H

