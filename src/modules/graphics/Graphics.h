//
// Created by leafnsand on 2015/5/28.
//

#ifndef ONLY2D_GRAPHICS_H
#define ONLY2D_GRAPHICS_H

#include "OpenGL.h"
#include "Shader.h"
#include "Image.h"
#include "ImageData.h"

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

        OpenGL &getOpenGL();

    private:
        OpenGL gl;
        std::vector<Shader> shaders;
        Color backgroundColor;
    };
}

#endif //ONLY2D_GRAPHICS_H
