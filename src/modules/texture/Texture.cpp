//
// Created by leafnsand on 2015/5/29.
//

#include "Texture.h"

namespace only2d
{
    ModuleType Texture::getType() const
    {
        return ModuleType::TEXTURE;
    }

    const char *Texture::getName() const
    {
        return "Texture";
    }

    Texture::Texture()
    {
        registerModule(this);
    }

    Texture::~Texture()
    {
        deregisterModule(this);
    }

    std::shared_ptr<TextureData> Texture::createTextureData(std::shared_ptr<Data> data)
    {
        return std::make_shared<TextureData>(data);
    }

    std::shared_ptr<TextureData> Texture::createTextureData(int32_t width, int32_t height, const Color &color)
    {
        return std::make_shared<TextureData>(width, height, color);
    }
}