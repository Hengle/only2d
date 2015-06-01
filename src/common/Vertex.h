//
// Created by leafnsand on 2015/6/1.
//

#ifndef ONLY2D_VERTEX_H
#define ONLY2D_VERTEX_H

#include "Color.h"
#include "Vector.h"

namespace only2d
{
    class Vertex
    {
    public:
        Vector position;
        Vector texture;
        Color color;
    };
}

#endif //ONLY2D_VERTEX_H
