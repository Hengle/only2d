//
// Created by leafnsand on 2015/6/15.
//

#include "ImageBatch.h"
#include "Graphics.h"

#include "common/Console.h"

namespace only2d
{
    ImageBatch::ImageBatch() :
            needSyncBuffer(true)
    {
        auto graphics = Module::getInstance<Graphics>(ModuleType::GRAPHICS);
        if (!graphics)
        {
            Console::error << "[Image] module graphics not found!" << Console::endl;
        }
        else
        {
            shader = graphics->getImageBatchShader();
        }
    }

    ImageBatch::~ImageBatch()
    {
		data.reset();
		shader.reset();
    }

    void ImageBatch::addImage(std::shared_ptr<Image> image)
    {
        if (!data)
        {
            data = image->data;
        }
        else if (image->data != data)
        {
            Console::debug << "[ImageBatch] add image with diffferent image data" << Console::endl;
        }
        needSyncBuffer = true;
        auto imageVertices(image->vertices);
        for (auto i = 0; i < 4; ++i)
        {
            imageVertices[i].position = image->getMatrix().transform(image->vertices[i].position);
        }
        vertices.add(imageVertices);
        indices.add(1);
    }

    void ImageBatch::clear()
    {
        vertices.clear();
        indices.clear();
        needSyncBuffer = true;
    }

    void ImageBatch::draw()
    {
        if (visible)
        {
            vertices.bind();
            indices.bind();
            if (needSyncBuffer)
            {
                vertices.syncBuffer();
                indices.syncBuffer();
                needSyncBuffer = false;
            }
            data->bind();
            shader->attach();
            shader->setVertexData(vertices);
            shader->setColor(color);
            shader->setAlpha(alpha);
            shader->setMVPMatrix(getMatrix());
            shader->draw(indices);
            vertices.unbind();
            indices.unbind();
            data->unbind();
            shader->detach();
        }
    }
}