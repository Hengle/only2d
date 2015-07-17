//
// Created by Xavier Jiang on 15/7/14.
//

#include "LuaObject.h"

namespace only2d
{
	LuaObject::LuaObject() :
		type(LuaType::MinInvalid),
		object(nullptr)
	{
	}

	LuaObject::~LuaObject()
	{
	}
}
