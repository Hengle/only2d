//
// Created by leafnsand on 2015/5/28.
//

#include <common/Console.h>
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

    Graphics::Graphics() :
            gl(new OpenGL)
    {
        registerModule(this);
        gl->initContext();
    }

    Graphics::~Graphics()
    {
        deregisterModule(this);
    }

    void Graphics::setResolution(int32_t width, int32_t height)
    {
        viewport.x = viewport.y = 0;
        viewport.width = width;
        viewport.height = height;
        gl->setViewport(viewport);
        if (defaultShader)
        {
            defaultShader.reset();
        }
        projectionMatrix.setOrthographic(0, width, 0, height);
        createDefaultShader();
    }

    void Graphics::clear()
    {
        gl->clear(backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a);
    }

    std::shared_ptr<Shader> Graphics::createShader(std::string &vertex, std::string fragment)
    {
        return std::make_shared<Shader>(vertex, fragment);
    }

    std::shared_ptr<ImageData> Graphics::createImageData(int32_t width, int32_t height, std::shared_ptr<Data> data)
    {
        return std::make_shared<ImageData>(width, height, data);
    }

    std::shared_ptr<Image> Graphics::createImage(std::shared_ptr<ImageData> data)
    {
        return std::make_shared<Image>(data);
    }

    std::shared_ptr<Shader> &Graphics::getDefaultShader()
    {
        return defaultShader;
    }

    Color Graphics::getBackgroundColor() const
    {
        return Color(static_cast<uint8_t>(backgroundColor.r * 255),
                     static_cast<uint8_t>(backgroundColor.g * 255),
                     static_cast<uint8_t>(backgroundColor.b * 255),
                     static_cast<uint8_t>(backgroundColor.a * 255));
    }

    void Graphics::setBackgroundColor(const Color &backgroundColor)
    {
        this->backgroundColor.set(backgroundColor.r / 255.0f, backgroundColor.g / 255.0f, backgroundColor.b / 255.0f,
                                  backgroundColor.a / 255.0f);
    }

    const Matrix &Graphics::getProjectionMatrix() const
    {
        return projectionMatrix;
    }

    std::shared_ptr<OpenGL> &Graphics::getOpenGL()
    {
        return gl;
    }

    void Graphics::createDefaultShader()
    {
        std::string defaultVertexShader = "#ifndef GL_ES\n"
                "#define lowp\n"
                "#define mediump\n"
                "#define highp\n"
                "#endif\n"
                "#ifdef GL_ES\n"
                "precision mediump float;\n"
                "#endif\n"
                "attribute vec4 aPosition;\n"
                "attribute vec4 aTexcoord;\n"
                "attribute vec4 aColor;\n"
                "uniform mat4 uMVPMatrix;\n"
                "uniform mat4 uProjectionMatrix;\n"
                "uniform float uAlpha;\n"
                "varying vec4 vTexcoord;\n"
                "varying vec4 vColor;\n"
                "void main() {\n"
                "\tvTexcoord = aTexcoord;\n"
                "\tvColor = aColor;\n"
                "\tvColor.a = vColor.a * uAlpha;\n"
                "\tgl_Position = uProjectionMatrix * uMVPMatrix * aPosition;\n"
                "}";
        std::string defaultFragmentShader = "#ifndef GL_ES\n"
                "#define lowp\n"
                "#define mediump\n"
                "#define highp\n"
                "#endif\n"
                "#ifdef GL_ES\n"
                "precision mediump float;\n"
                "#endif\n"
                "varying vec4 vTexcoord;\n"
                "varying vec4 vColor;\n"
                "uniform sampler2D uTexture;\n"
                "void main() {\n"
                "\tgl_FragColor = texture2D(uTexture, vTexcoord) * vColor;\n"
                "}";
        defaultShader = std::make_shared<Shader>(defaultVertexShader, defaultFragmentShader);
    }
}