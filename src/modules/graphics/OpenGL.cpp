//
// Created by leafnsand on 2015/5/28.
//

#include "ImageData.h"
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
        glGetIntegerv(GL_MAX_TEXTURE_SIZE, &maxTextureSize);
        glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &maxTextureCount);
        glEnable(GL_BLEND);
    }

    void OpenGL::clear(float r, float g, float b, float a)
    {
        glClearColor(r, g, b, a);
        glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void OpenGL::generateTexture(GLuint &texture)
    {
        glGenTextures(1, &texture);
    }

    void OpenGL::deleteTexture(GLuint &texture)
    {
        glDeleteTextures(1, &texture);
    }

    void OpenGL::bindTexture(const GLuint &texture)
    {
        glBindTexture(GL_TEXTURE_2D, texture);
    }

    void OpenGL::setTextureFilter(const ImageDataFilter &filter)
    {
        auto glFilterMode = [](ImageDataFilterMode filterMode) -> GLint
        {
            switch (filterMode)
            {
                case ImageDataFilterMode::LINEAR:
                    return GL_LINEAR;
                case ImageDataFilterMode::NEAREST:
                    return GL_NEAREST;
            }
        };
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, glFilterMode(filter.min));
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, glFilterMode(filter.mag));
    }

    void OpenGL::setTextureWrap(const ImageDataWrap &wrap)
    {
        auto glWrapMode = [](ImageDataWrapMode wrapMode) -> GLint
        {
            switch (wrapMode)
            {
                case ImageDataWrapMode::CLAMP:
                    return GL_CLAMP_TO_EDGE;
                case ImageDataWrapMode::REPEAT:
                    return GL_REPEAT;
                case ImageDataWrapMode::MIRRORED_REPEAT:
                    return GL_MIRRORED_REPEAT;
            }
        };
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, glWrapMode(wrap.s));
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, glWrapMode(wrap.t));
    }

    bool OpenGL::setTextureData(GLsizei width, GLsizei height, std::shared_ptr<Data> data)
    {
        if (data)
        {
            cleanErrors();
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data->getBuffer());
            if (glGetError() == GL_NO_ERROR)
            {
                return true;
            }
        }
        return false;
    }

    void OpenGL::cleanErrors()
    {
        while (glGetError() != GL_NO_ERROR);
    }

    GLuint OpenGL::createShader(GLenum type)
    {
        return glCreateShader(type);
    }

    void OpenGL::deleteShader(GLuint shader)
    {
        glDeleteShader(shader);
    }

    void OpenGL::setShaderSource(GLuint shader, const std::string &source)
    {
        const char *src = source.c_str();
        GLint len = (GLint) source.length();
        glShaderSource(shader, 1, &src, &len);
    }

    bool OpenGL::compileShader(GLuint shader)
    {
        glCompileShader(shader);
        GLint status;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
        if (status == GL_FALSE)
        {
            GLint errorLength = 0;
            glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &errorLength);
            if (errorLength > 0)
            {
                GLchar *error = new GLchar[errorLength];
                glGetShaderInfoLog(shader, errorLength, nullptr, error);
                Console::log << "[OpenGL] compile shader log: " << error << Console::endl;
                delete[] error;
            }
            return false;
        }
        return true;
    }

    GLuint OpenGL::createProgram()
    {
        return glCreateProgram();
    }

    void OpenGL::deleteProgram(GLuint program)
    {
        glDeleteProgram(program);
    }

    void OpenGL::attachShader(GLuint program, GLuint shader)
    {
        glAttachShader(program, shader);
    }

    bool OpenGL::linkProgram(GLuint program)
    {
        glLinkProgram(program);
        GLint status;
        glGetProgramiv(program, GL_LINK_STATUS, &status);
        if (status == GL_FALSE)
        {
            GLint errorLength = 0;
            glGetProgramiv(program, GL_INFO_LOG_LENGTH, &errorLength);
            if (errorLength > 0)
            {
                GLchar *error = new GLchar[errorLength];
                glGetProgramInfoLog(program, errorLength, nullptr, error);
                Console::log << "[OpenGL] link program log: " << error << Console::endl;
                delete[] error;
            }
            return false;
        }
        return true;
    }

    void OpenGL::useProgram(GLuint program)
    {
        glUseProgram(program);
    }

    int32_t OpenGL::getMaxTextureSize() const
    {
        return maxTextureSize;
    }

    int32_t OpenGL::getMaxTextureCount() const
    {
        return maxTextureCount;
    }

    void OpenGL::setViewport(const Viewport &viewport)
    {
        this->viewport = viewport;
        glViewport(this->viewport.x, this->viewport.y, this->viewport.width, this->viewport.height);
        setScissor(this->scissor);
    }

    const Viewport &OpenGL::getViewport() const
    {
        return viewport;
    }

    void OpenGL::setScissor(const Viewport &scissor)
    {
        this->scissor = scissor;
        glScissor(this->scissor.x, this->scissor.y, this->scissor.width, this->scissor.height);
    }

    const Viewport &OpenGL::getScissor() const
    {
        return scissor;
    }
}