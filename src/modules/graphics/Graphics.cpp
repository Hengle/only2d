//
// Created by leafnsand on 2015/5/28.
//

#include "Graphics.h"

namespace only2d
{
    ModuleType Graphics::getType() const
    {
        return ModuleType::GRAPHICS;
    }

    const char *Graphics::getName() const
    {
        return "Graphics";
    }

    Graphics::Graphics()
    {
        registerModule(this);
        gl.initContext();
    }

    Graphics::~Graphics()
    {
        deregisterModule(this);
    }

    void Graphics::clear()
    {
        glClearColor(backgroundColor.r / 255.0f, backgroundColor.g / 255.0f, backgroundColor.b / 255.0f,
                     backgroundColor.a / 255.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    const Color &Graphics::getBackgroundColor() const
    {
        return backgroundColor;
    }

    void Graphics::setBackgroundColor(const Color &backgroundColor)
    {
        this->backgroundColor = backgroundColor;
    }
}