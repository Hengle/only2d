//
// Created by leafnsand on 2015/6/1.
//

#ifndef ONLY2D_SHADER_H
#define ONLY2D_SHADER_H

#include "OpenGL.h"

#include <string>

namespace only2d
{
    class Shader
    {
    public:
        Shader(std::string &vertex, std::string &fragment);

        ~Shader();

        void attach();

        void detach();

    private:
        void load();

        void unload();

        GLuint compile(GLenum type, const std::string &source);

    protected:
        std::string vertex;
        std::string fragment;
        GLuint program;
        std::shared_ptr<OpenGL> gl;
    };
}

#endif //ONLY2D_SHADER_H
