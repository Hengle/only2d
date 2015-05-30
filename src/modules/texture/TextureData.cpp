//
// Created by leafnsand on 2015/5/29.
//

#include "TextureData.h"
#include "TextureParser.h"

#include "common/Color.h"
#include "common/Console.h"

namespace only2d
{
    TextureData::TextureData(Data &data) :
            Data(data),
            width(0),
            height(0),
            encoded(true)
    {
        decode();
    }

    TextureData::TextureData(int32_t width, int32_t height) :
            Data(width * height * sizeof(Pixel)),
            width(width),
            height(height),
            encoded(false)
    {
    }

    TextureData::TextureData(int32_t width, int32_t height, Data &data) :
            Data(data),
            width(width),
            height(height),
            encoded(false)
    {
        if (data.getSize() < width * height * sizeof(Pixel))
        {
            Console::error << "invalid texture data" << Console::endl;
        }
    }

    TextureData::~TextureData()
    {
    }

    void TextureData::encode()
    {
        if (encoded)
        {
            Console::debug << "texture already encoded!" << Console::endl;
            return;
        }
    }

    void TextureData::decode()
    {
        if (!encoded)
        {
            Console::debug << "texture already decoded!" << Console::endl;
            return;
        }
        if (!TextureParser::recognize(*this))
        {
            Console::debug << "could not recognize data!" << Console::endl;
            return;
        }
        TextureParser::parse(*this);
        encoded = false;
    }

    void TextureData::setWidth(int32_t width)
    {
        this->width = width;
    }

    int32_t TextureData::getWidth() const
    {
        return width;
    }

    void TextureData::setHeight(int32_t height)
    {
        this->height = height;
    }

    int32_t TextureData::getHeight() const
    {
        return height;
    }
}