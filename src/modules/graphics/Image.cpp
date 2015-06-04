//
// Created by leafnsand on 2015/6/1.
//

#include "Image.h"
#include "Graphics.h"

#include "common/Console.h"

namespace only2d
{
    Image::Image(std::shared_ptr<ImageData> data) :
            data(data)
    {
        auto graphics = Module::getInstance<Graphics>(ModuleType::GRAPHICS);
        if (!graphics)
        {
            Console::error << "[Image] module graphics not found!" << Console::endl;
        }
        else
        {
            shader = graphics->getDefaultShader();
        }
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
            shader->setVertexData(data->getVertices());
            shader->setColor(color);
            shader->setTexture(data->getTexture());
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
}