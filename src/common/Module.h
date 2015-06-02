//
// Created by leafnsand on 2015/5/28.
//

#ifndef ONLY2D_MODULE_H
#define ONLY2D_MODULE_H

#include <cstdint>

namespace only2d
{
    enum class ModuleType : int32_t
    {
        EVENT,
        FILESYSTEM,
        GRAPHICS,
        ONLY2D,
        TEXTURE,
        WINDOW,
        MAX_COUNT
    };

    class Module
    {
    public:
        virtual ModuleType getType() const = 0;

        virtual const char *getName() const = 0;

    public:
        static void registerModule(Module *module);

        static void deregisterModule(Module *module);

        template<typename T>
        static T *getInstance(ModuleType type)
        {
            return static_cast<T *>(modules[static_cast<int32_t>(type)]);
        }

    private:
        static Module *modules[static_cast<int32_t>(ModuleType::MAX_COUNT)];
    };
}

#endif //ONLY2D_MODULE_H