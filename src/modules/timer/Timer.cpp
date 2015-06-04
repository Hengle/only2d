//
// Created by leafnsand on 2015/6/4.
//

#include "Timer.h"

namespace only2d
{
    ModuleType Timer::getType() const
    {
        return ModuleType::TIMER;
    }

    const char *Timer::getName() const
    {
        return "Timer";
    }

    Timer::Timer()
    {
        registerModule(this);
    }

    Timer::~Timer()
    {
        deregisterModule(this);
    }
}