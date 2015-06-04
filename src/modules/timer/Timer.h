//
// Created by leafnsand on 2015/6/4.
//

#ifndef ONLY2D_TIMER_H
#define ONLY2D_TIMER_H

#include "common/Module.h"

namespace only2d
{
    class Timer : public Module
    {
    public:
        Timer();

        virtual ~Timer();

        virtual ModuleType getType() const override;

        virtual const char *getName() const override;
    };
}

#endif //ONLY2D_TIMER_H
