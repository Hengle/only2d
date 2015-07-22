//
// Created by leafnsand on 2015/7/10.
//

#pragma once

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