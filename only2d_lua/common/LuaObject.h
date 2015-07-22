//
// Created by Xavier Jiang on 15/7/14.
//

#pragma once

#include "LuaType.h"

#include <memory>

namespace only2d
{
	class LuaObject
	{
	public:
		LuaObject();

		~LuaObject();

		LuaType type;

		std::shared_ptr<void> object;
	};
}