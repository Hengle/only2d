//
// Created by leafnsand on 2015/5/28.
//

#ifndef ONLY2D_GRAPHICS_H
#define ONLY2D_GRAPHICS_H

#include "OpenGL.h"

#include "common/Color.h"
#include "common/Module.h"

namespace only2d
{
    class Graphics : public Module
    {
    public:
        Graphics();

        virtual ~Graphics();

        virtual ModuleType getType() const;

        virtual const char *getName() const;

        void clear();

        const Color &getBackgroundColor() const;

        void setBackgroundColor(const Color &backgroundColor);

    private:
        OpenGL gl;
        Color backgroundColor;
    };
}

#endif //ONLY2D_GRAPHICS_H
