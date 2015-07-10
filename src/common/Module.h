//
// Created by leafnsand on 2015/5/28.
//

#ifndef ONLY2D_MODULE_H
#define ONLY2D_MODULE_H

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
        TEXTURE,
        TIMER,
        WINDOW,
        MAX_COUNT
    };

    class Module
    {
    public:
        virtual ~Module();

        virtual ModuleType getType() const = 0;

        virtual const char *getName() const = 0;

		template<typename T>
        static std::shared_ptr<T> open(ModuleType type)
		{
			auto index = static_cast<int32_t>(type);
			if (modules[index] == nullptr)
			{
				modules[index] = std::make_shared<T>();
			}
			return std::dynamic_pointer_cast<T>(modules[index]);
		}

		template<typename T>
        static void close(ModuleType type)
		{
			auto index = static_cast<int32_t>(type);
			if (modules[index])
			{
				modules[index].reset();
			}
		}

        template<typename T>
        static std::shared_ptr<T> getInstance(ModuleType type)
        {
            return std::dynamic_pointer_cast<T>(modules[static_cast<int32_t>(type)]);
        }

    private:
        static std::shared_ptr<Module> modules[static_cast<int32_t>(ModuleType::MAX_COUNT)];
    };
}

#endif //ONLY2D_MODULE_H