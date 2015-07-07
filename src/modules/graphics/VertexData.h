//
// Created by leafnsand on 2015/6/15.
//

#ifndef ONLY2D_VERTEXDATA_H
#define ONLY2D_VERTEXDATA_H

#include "OpenGLData.h"

#include "common/Vertex.h"

namespace only2d
{
    class VertexData : public OpenGLData
    {
    public:
        VertexData();

        virtual ~VertexData();

        virtual void syncBuffer() override;

        void add(std::vector<Vertex> vertices);

        void clear();

    private:
        int32_t size;
        int32_t capacity;
    };
}

#endif //ONLY2D_VERTEXDATA_H
