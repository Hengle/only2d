//
// Created by Xavier Jiang on 15/7/14.
//

#ifndef ONLY2D_LUAOBJECT_H
#define ONLY2D_LUAOBJECT_H

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

#endif //ONLY2D_LUAOBJECT_H

