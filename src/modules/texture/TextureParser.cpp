//
// Created by leafnsand on 2015/5/30.
//

#include "TextureParser.h"

#include "common/Color.h"

#include "library/stb/stb_image.h"

namespace only2d
{
    bool TextureParser::recognize(TextureData &data)
    {
        auto width = 0;
        auto height = 0;
        auto components = 0;
        auto status = stbi_info_from_memory(data.getBuffer(), static_cast<int32_t>(data.getSize()), &width, &height,
                                            &components);
        if (status == 1 && width > 0 && height > 0)
        {
            data.setWidth(width);
            data.setHeight(height);
            return true;
        }
        return false;
    }

    void TextureParser::parse(TextureData &data)
    {
        auto width = 0;
        auto height = 0;
        auto components = 0;
        auto buffer = stbi_load_from_memory(data.getBuffer(), static_cast<int32_t>(data.getSize()), &width, &height,
                                            &components, 4);
        data.assign(buffer, buffer + data.getWidth() * data.getHeight() * sizeof(Pixel));
        delete[] buffer;
    }
}