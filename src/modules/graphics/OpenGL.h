//
// Created by leafnsand on 2015/5/28.
//

#ifndef ONLY2D_OPENGL_H
#define ONLY2D_OPENGL_H

#include "Viewport.h"

#include "common/Data.h"

#include <GL/glew.h>
#include <memory>

namespace only2d
{
    struct ImageDataWrap;
    struct ImageDataFilter;

    class OpenGL
    {
    public:
        OpenGL();

        virtual ~OpenGL();

        void initContext();

        void clear(float r, float g, float b, float a);

        void generateTexture(GLuint &texture);

        void deleteTexture(GLuint &texture);

        void bindTexture(const GLuint &texture);

        void setTextureFilter(const ImageDataFilter &filter);

        void setTextureWrap(const ImageDataWrap &wrap);

        bool setTextureData(GLsizei width, GLsizei height, std::shared_ptr<Data> data);

        void cleanErrors();

        int32_t getMaxTextureSize() const;

        int32_t getMaxTextureCount() const;

        void setViewport(const Viewport &viewport);

        const Viewport &getViewport() const;

        void setScissor(const Viewport &scissor);

        const Viewport &getScissor() const;

    private:
        int32_t maxTextureSize;
        int32_t maxTextureCount;
        Viewport viewport;
        Viewport scissor;
    };
}

#endif //ONLY2D_OPENGL_H
