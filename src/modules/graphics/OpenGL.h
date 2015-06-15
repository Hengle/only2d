//
// Created by leafnsand on 2015/5/28.
//

#ifndef ONLY2D_OPENGL_H
#define ONLY2D_OPENGL_H

#include "Viewport.h"

#include "common/Data.h"
#include "common/Matrix.h"

#include "library/glad/glad.h"

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

        GLuint createShader(GLenum type);

        void deleteShader(GLuint shader);

        void setShaderSource(GLuint shader, const std::string &source);

        bool compileShader(GLuint shader);

        GLuint createProgram();

        void deleteProgram(GLuint program);

        void attachShader(GLuint program, GLuint shader);

        bool linkProgram(GLuint program);

        void useProgram(GLuint program);

        GLint getProgramAttributeLocation(GLuint shader, const std::string &name);

        void enableProgramAttribute(GLuint position);

        void setProgramAttributePointer(GLuint position, GLint size, GLenum type, GLboolean normalized, GLsizei stride,
                                        const GLvoid *pointer);

        GLint getProgramUniformLocation(GLuint shader, const std::string &name);

        void setProgramIntUniformData(GLuint position, const std::vector<int32_t> &data);

        void setProgramFloatUniformData(GLuint position, const std::vector<float> &data);

        void setProgramMatrixUniformData(GLuint position, const Matrix &matrix);

        void generateBuffer(GLuint &buffer);

        void deleteBuffer(GLuint &buffer);

        void bindBuffer(GLenum target, GLuint buffer);

        void setBufferData(GLenum target, GLsizeiptr size, const GLvoid *data, GLenum usage);

        void drawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid *buffer);

        void drawArrays(GLenum mode, GLint first, GLsizei count);

        int32_t getDrawCalls() const;

        int32_t getTextureCount() const;

        int32_t getMaxTextureSize() const;

        void setViewport(const Viewport &viewport);

        const Viewport &getViewport() const;

        void setScissor(const Viewport &scissor);

        const Viewport &getScissor() const;

    private:
        int32_t drawCalls;
        int32_t textureCount;
        int32_t maxTextureSize;
        int32_t maxTextureCount;
        Viewport viewport;
        Viewport scissor;
    };
}

#endif //ONLY2D_OPENGL_H
