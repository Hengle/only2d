//
// Created by leafnsand on 2015/5/28.
//

#ifndef ONLY2D_ONLY2D_H
#define ONLY2D_ONLY2D_H

#include "common/Module.h"

namespace only2d
{
    struct WindowSettings;

    class Only2D : public Module
    {
    public:
        Only2D();

        virtual ~Only2D();

        virtual ModuleType getType() const override;

        virtual const char *getName() const override;

        int32_t run(int32_t argc, char *argv[]);

        void quit();

    private:
        bool running;
    };
}

#endif //ONLY2D_ONLY2D_H
