//
// Created by leafnsand on 2015/6/1.
//

#ifndef ONLY2D_SHADER_H
#define ONLY2D_SHADER_H

#include "OpenGL.h"

#include "common/Vertex.h"

#include <map>
#include <string>

namespace only2d
{
    class DefaultShaderAttribute
    {
    public:
        static const std::string POSITION;
        static const std::string TEXCOORD;
        static const std::string COLOR;
    };

    class DefaultShaderUniform
    {
    public:
        static const std::string MVP_MATRIX;
        static const std::string ALPHA;
        static const std::string TEXTURE;
    };

    class Shader
    {
    public:
        Shader(std::string &vertex, std::string &fragment);

        ~Shader();

        bool match(const std::string &vertex, const std::string &fragment);

        void setVertexData(const std::vector<Vertex> &vertices);

        void setAttributeData(const std::string &name, GLint size, GLenum type, GLboolean normalized, GLsizei stride,
                              const GLvoid *pointer);

        void attach();

        void detach();

        void draw();

    private:
        void load();

        void unload();

        GLuint compile(GLenum type, const std::string &source);

    protected:
        std::string vertex;
        std::string fragment;
        GLuint program;
        std::map<const std::string, GLint> attributes;
        std::map<const std::string, GLint> uniforms;
        std::shared_ptr<OpenGL> gl;
    };
}

#endif //ONLY2D_SHADER_H
