//
// Created by leafnsand on 2015/5/29.
//

#ifndef ONLY2D_TEXTUREPARSER_H
#define ONLY2D_TEXTUREPARSER_H

#include "TextureData.h"

namespace only2d
{
    class TextureParser
    {
    public:
        static bool recognize(TextureData &data);

        static void parse(TextureData &data);
    };
}

#endif //ONLY2D_TEXTUREPARSER_H
