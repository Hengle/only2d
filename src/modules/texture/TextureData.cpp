//
// Created by leafnsand on 2015/5/29.
//

#include "TextureData.h"
#include "TextureParser.h"

#include "common/Console.h"

namespace only2d
{
    TextureData::TextureData(std::shared_ptr<Data> data) :
            Data(*data),
            width(0),
            height(0),
            encoded(true)
    {
        decode();
    }

    TextureData::TextureData(int32_t width, int32_t height, const Color &color) :
            Data(width * height * sizeof(Pixel)),
            width(width),
            height(height),
            encoded(false)
    {
        auto pointer = (Pixel *) getBuffer();
        for (auto i = 0; i < width * height; ++i)
        {
            *pointer = color;
            ++pointer;
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