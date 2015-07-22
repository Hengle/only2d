#pragma once

#include <cstdint>
#include <memory>

namespace only2d
{
	enum class ModuleType : int32_t
	{
		APPLICATION,
		EVENT,
		FILESYSTEM,
		GRAPHICS,
		KEYBOARD,
		TEXTURE,
		TIMER,
		WINDOW,
		MAX_COUNT
	};

	class Module
	{
	public:
		template <typename T>
		static std::shared_ptr<T> open(ModuleType type)
		{
			auto index = static_cast<int32_t>(type);
			if (modules[index] == nullptr)
			{
				modules[index] = std::make_shared<T>();
			}
			return std::static_pointer_cast<T>(modules[index]);
		}

		static void close(ModuleType type);

		template <typename T>
		static std::shared_ptr<T> getInstance(ModuleType type)
		{
			return std::static_pointer_cast<T>(modules[static_cast<int32_t>(type)]);
		}

	private:
		static std::shared_ptr<void> modules[static_cast<int32_t>(ModuleType::MAX_COUNT)];
	};
}