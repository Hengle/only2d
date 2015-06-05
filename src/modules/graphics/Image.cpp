//
// Created by leafnsand on 2015/6/1.
//

#include "Image.h"
#include "Graphics.h"

#include "common/Console.h"

namespace only2d
{
    Image::Image(std::shared_ptr<ImageData> data) :
            data(data),
            color(255, 255, 255, 255),
            vertices(4),
            width(data->getWidth()),
            height(data->getHeight())
    {
        auto graphics = Module::getInstance<Graphics>(ModuleType::GRAPHICS);
        if (!graphics)
        {
            Console::error << "[Image] module graphics not found!" << Console::endl;
        }
        else
        {
            shader = graphics->getImageShader();
        }
        vertices[0].position.set(0.0f, 0.0f);
        vertices[1].position.set(0.0f, static_cast<float>(height));
        vertices[2].position.set(static_cast<float>(width), 0.0f);
        vertices[3].position.set(static_cast<float>(width), static_cast<float>(height));
        vertices[0].texcoord.set(0.0f, 1.0f);
        vertices[1].texcoord.set(0.0f, 0.0f);
        vertices[2].texcoord.set(1.0f, 1.0f);
        vertices[3].texcoord.set(1.0f, 0.0f);
    }

    Image::~Image()
    {
        data.reset();
    }

    void only2d::Image::draw()
    {
        if (visible)
        {
            data->bind();
            shader->attach();
            shader->setVertexData(vertices);
            shader->setColor(color);
            shader->setAlpha(alpha);
            shader->setMVPMatrix(getMatrix());
            shader->draw();
        }
    }

    const Color &Image::getColor() const
    {
        return color;
    }

    void Image::setColor(const Color &color)
    {
        this->color = color;
    }

    int32_t Image::getHeight() const
    {
        return width;
    }

    void Image::setHeight(int32_t height)
    {
        this->height = height;
        updateVertices();
    }

    int32_t Image::getWidth() const
    {
        return height;
    }

    void Image::setWidth(int32_t width)
    {
        this->width = width;
        updateVertices();
    }

    void Image::updateVertices()
    {
        vertices[1].position.set(0.0f, static_cast<float>(width));
        vertices[2].position.set(static_cast<float>(width), 0.0f);
        vertices[3].position.set(static_cast<float>(width), static_cast<float>(height));
    }
}