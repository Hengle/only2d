//
// Created by leafnsand on 2015/6/1.
//

#include "ImageData.h"
#include "Graphics.h"

#include "common/Console.h"

namespace only2d
{
    ImageData::ImageData(int32_t width, int32_t height, std::shared_ptr<Data> data) :
            width(width),
            height(height),
            vertices(4),
            texture(0),
            data(data),
            usingDefaultData(false)
    {
        auto graphics = Module::getInstance<Graphics>(ModuleType::GRAPHICS);
        if (!graphics)
        {
            Console::error << "[ImageData] module graphics not found!" << Console::endl;
        }
        else
        {
            gl = graphics->getOpenGL();
        }
        prepareVertices();
        loadData();
    }

    ImageData::~ImageData()
    {
        unloadData();
        data.reset();
    }

    void ImageData::bind()
    {
        gl->bindTexture(texture);
    }

    int32_t ImageData::getWidth() const
    {
        return width;
    }

    void ImageData::setWidth(int32_t width)
    {
        this->width = width;
    }

    int32_t ImageData::getHeight() const
    {
        return height;
    }

    void ImageData::setHeight(int32_t height)
    {
        this->height = height;
    }

    const std::vector<Vertex> &ImageData::getVertices() const
    {
        return vertices;
    }

    const GLuint &ImageData::getTexture() const
    {
        return texture;
    }

    const ImageDataWrap &ImageData::getWrap() const
    {
        return wrap;
    }

    void ImageData::setWrap(const ImageDataWrap &wrap)
    {
        this->wrap = wrap;
        gl->bindTexture(texture);
        gl->setTextureWrap(this->wrap);
    }

    const ImageDataFilter &ImageData::getFilter() const
    {
        return filter;
    }

    void ImageData::setFilter(const ImageDataFilter &filter)
    {
        this->filter = filter;
        gl->bindTexture(texture);
        gl->setTextureFilter(this->filter);
    }

    /**
     * 0----2
     * |  / |
     * | /  |
     * 1----3
     */
    void ImageData::prepareVertices()
    {
        vertices[0].position.set(0.0f, 0.0f);
        vertices[1].position.set(0.0f, static_cast<float>(height));
        vertices[2].position.set(static_cast<float>(width), 0.0f);
        vertices[3].position.set(static_cast<float>(width), static_cast<float>(height));

        vertices[0].texcoord.set(0.0f, 0.0f);
        vertices[1].texcoord.set(0.0f, 1.0f);
        vertices[2].texcoord.set(1.0f, 0.0f);
        vertices[3].texcoord.set(1.0f, 1.0f);
    }

    void ImageData::loadData()
    {
        gl->generateTexture(texture);
        gl->bindTexture(texture);
        setFilter(filter);
        setWrap(wrap);
        if (width > gl->getMaxTextureSize() || height > gl->getMaxTextureSize())
        {
            loadDefaultData();
            return;
        }
        if (!gl->setTextureData(width, height, data))
        {
            Console::log << "[ImageData] update texture data fail." << Console::endl;
            unloadData();
        }
    }

    void ImageData::loadDefaultData()
    {
        Console::log << "[ImageData] using default image data!" << Console::endl;
        usingDefaultData = true;
        gl->bindTexture(texture);
        setFilter(filter);
        Data defaultData(16);
        defaultData[0] = 0xFF;
        defaultData[1] = 0xFF;
        defaultData[2] = 0xFF;
        defaultData[3] = 0xFF;
        defaultData[4] = 0xFF;
        defaultData[5] = 0xC0;
        defaultData[6] = 0xC0;
        defaultData[7] = 0xFF;
        defaultData[8] = 0xFF;
        defaultData[9] = 0xC0;
        defaultData[10] = 0xC0;
        defaultData[11] = 0xFF;
        defaultData[12] = 0xFF;
        defaultData[13] = 0xFF;
        defaultData[14] = 0xFF;
        defaultData[15] = 0xFF;
        if (!gl->setTextureData(2, 2, std::shared_ptr<Data>(&defaultData)))
        {
            Console::log << "[ImageData] update texture data fail." << Console::endl;
            unloadData();
        }
    }

    void ImageData::unloadData()
    {
        if (texture != 0)
        {
            gl->deleteTexture(texture);
            texture = 0;
        }
    }
}