//
// Created by leafnsand on 2015/5/28.
//

#include "OpenGL.h"
#include "common/Console.h"

namespace only2d
{
    OpenGL::OpenGL()
    {
    }

    OpenGL::~OpenGL()
    {
    }

    void OpenGL::initContext()
    {
        if (glewInit() != GLEW_OK)
        {
            Console::error << "initialize glew fail." << Console::endl;
        }
    }
}