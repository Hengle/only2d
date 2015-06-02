//
// Created by leafnsand on 2015/5/29.
//

#ifndef ONLY2D_TEXTURE_H
#define ONLY2D_TEXTURE_H

#include "TextureData.h"

#include "common/Module.h"

#include <memory>

namespace only2d
{
    class Texture : public Module
    {
    public:
        Texture();

        virtual ~Texture();

        virtual ModuleType getType() const override;

        virtual const char *getName() const override;

        std::shared_ptr<TextureData> createTextureData(std::shared_ptr<Data> data);

        std::shared_ptr<TextureData> createTextureData(int32_t width, int32_t height);

        std::shared_ptr<TextureData> createTextureData(int32_t width, int32_t height, std::shared_ptr<Data> data);
    };
}

#endif //ONLY2D_TEXTURE_H
