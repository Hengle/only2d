//
// Created by leafnsand on 2015/5/28.
//

#ifndef ONLY2D_OPENGL_H
#define ONLY2D_OPENGL_H

#include <GL/glew.h>

namespace only2d
{
    class OpenGL
    {
    public:
        OpenGL();

        virtual ~OpenGL();

        void initContext();
    };
}

#endif //ONLY2D_OPENGL_H
