//
// Created by leafnsand on 2015/6/1.
//

#ifndef ONLY2D_VIEWPORT_H
#define ONLY2D_VIEWPORT_H

#include <cstdint>

namespace only2d
{
    class Viewport
    {
    public:
        Viewport();

        Viewport(int32_t x, int32_t y, int32_t width, int32_t height);

        Viewport(Viewport &viewport);

        ~Viewport();

        bool operator==(const Viewport &viewport) const;

        int32_t x;
        int32_t y;
        int32_t width;
        int32_t height;
    };
}

#endif //ONLY2D_VIEWPORT_H
