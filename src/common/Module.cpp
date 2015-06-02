//
// Created by leafnsand on 2015/5/28.
//

#include "Module.h"
#include "Console.h"

namespace only2d
{
    Module *Module::modules[] = {};

    void Module::registerModule(Module *module)
    {
        auto index = static_cast<int32_t>(module->getType());
        if (modules[index] == nullptr)
        {
            modules[index] = module;
        }
        else
        {
            Console::error << "multi register module, type: " << module->getName() << Console::endl;
        }
    }

    void Module::deregisterModule(Module *module)
    {
        auto index = static_cast<int32_t>(module->getType());
        if (modules[index] == module)
        {
            modules[index] = nullptr;
        }
        else
        {
            Console::error << "deregister an unregisted module, type: " << module->getName() << Console::endl;
        }
    }

    Module::~Module()
    {
    }
}