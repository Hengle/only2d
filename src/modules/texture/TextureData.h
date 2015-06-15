//
// Created by leafnsand on 2015/5/29.
//

#ifndef ONLY2D_TEXTUREDATA_H
#define ONLY2D_TEXTUREDATA_H

#include "common/Color.h"
#include "common/Data.h"

#include <cstdint>
#include <memory>

namespace only2d
{
    class TextureData : public Data
    {
    public:
        explicit TextureData(std::shared_ptr<Data> data);

        TextureData(int32_t width, int32_t height, const Color &color);

        virtual ~TextureData();

        void encode(std::shared_ptr<Data> data);

        void decode(std::shared_ptr<Data> data);

        int32_t getWidth() const;

        int32_t getHeight() const;

    private:
        int32_t width;
        int32_t height;
        bool encoded;

        friend class TextureParser;
    };
}

#endif //ONLY2D_TEXTUREDATA_H
