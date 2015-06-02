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
        data->bind();
        shader->attach();
        shader->setVertexData(data->getVertices());
        shader->draw();
    }
}