//
// Created by leafnsand on 2015/5/29.
//

#ifndef ONLY2D_TEXTUREDATA_H
#define ONLY2D_TEXTUREDATA_H

#include "common/Data.h"

#include <cstdint>
#include <memory>

namespace only2d
{
    class TextureData : public Data
    {
    public:
        TextureData(Data &data);

        TextureData(int32_t width, int32_t height);

        TextureData(int32_t width, int32_t height, Data &data);

        virtual ~TextureData();

        void encode();

        void decode();

        void setWidth(int32_t width);

        int32_t getWidth() const;

        void setHeight(int32_t height);

        int32_t getHeight() const;

    private:
        int32_t width;
        int32_t height;
        bool encoded;
    };
}

#endif //ONLY2D_TEXTUREDATA_H
