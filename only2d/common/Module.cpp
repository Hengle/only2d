#include "Module.h"

namespace only2d
{
	std::shared_ptr<void> Module::modules[] = {};

	void Module::close(ModuleType type)
	{
		auto index = static_cast<int32_t>(type);
		if (modules[index])
		{
			modules[index].reset();
		}
	}
}