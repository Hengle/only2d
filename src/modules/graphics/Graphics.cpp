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
        projectionMatrix.setOrthographic(0.0f, static_cast<float>(width), 0.0f, static_cast<float>(height));
        imageShader = std::make_shared<ImageShader>();
        imageBatchShader = std::make_shared<ImageBatchShader>();
    }

    void Graphics::clear()
    {
        gl->clear(backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a);
    }

    void Graphics::checkOpenGLError()
    {
        gl->checkErrors();
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

    std::shared_ptr<ImageBatch> Graphics::createImageBatch()
    {
        return std::make_shared<ImageBatch>();
    }

    std::shared_ptr<ImageShader> Graphics::getImageShader()
    {
        return imageShader;
    }

    std::shared_ptr<ImageBatchShader> Graphics::getImageBatchShader()
    {
        return imageBatchShader;
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
}