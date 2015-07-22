//
// Created by leafnsand on 2015/5/28.
//

#include "Module.h"

namespace only2d
{
	std::shared_ptr<Module> Module::modules[] = {};

	Module::~Module()
	{
	}

	void Module::close(ModuleType type)
	{
		auto index = static_cast<int32_t>(type);
		if (modules[index])
		{
			modules[index].reset();
		}
	}
}