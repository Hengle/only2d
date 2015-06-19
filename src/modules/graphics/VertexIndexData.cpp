//
// Created by leafnsand on 2015/6/15.
//

#include "VertexIndexData.h"

#include "common/Console.h"

#include <limits>

namespace only2d
{
    VertexIndexData::VertexIndexData() :
            OpenGLData(GL_ELEMENT_ARRAY_BUFFER, GL_STATIC_DRAW, 6 * 16 * sizeof(GLushort)),
            size(0),
            capacity(16)
    {
        fill(capacity);
    }

    VertexIndexData::~VertexIndexData()
    {
    }

    void VertexIndexData::syncBuffer()
    {
        gl->setBufferData(target, 6 * size * sizeof(GLushort), getBuffer(), usage);
    }

    void VertexIndexData::add(int32_t count)
    {
        if (size + count > capacity)
        {
            expand();
        }
        size += count;
    }

    void VertexIndexData::remove(int32_t count)
    {
        size -= count;
    }

    void VertexIndexData::clear()
    {
        size = 0;
    }

    int32_t VertexIndexData::getIndexCount() const
    {
        return 6 * size;
    }

    void VertexIndexData::expand()
    {
        if (capacity > std::numeric_limits<GLushort>::max() / 2)
        {
            Console::error << "[VertexIndexData] too many vertex." << Console::endl;
        }
        fill(capacity, capacity);
        capacity *= 2;
    }

    void VertexIndexData::fill(int32_t length, int32_t offset)
    {
        auto data = new GLushort[6 * length];
        for (int32_t i = 0; i < length; ++i)
        {
            data[i * 6 + 0] = static_cast<GLushort>(i * 4 + 0);
            data[i * 6 + 1] = static_cast<GLushort>(i * 4 + 1);
            data[i * 6 + 2] = static_cast<GLushort>(i * 4 + 2);
            data[i * 6 + 3] = static_cast<GLushort>(i * 4 + 2);
            data[i * 6 + 4] = static_cast<GLushort>(i * 4 + 1);
            data[i * 6 + 5] = static_cast<GLushort>(i * 4 + 3);
        }
        assign((uint8_t *) data, 6 * length * sizeof(GLushort), 6 * offset * sizeof(GLushort));
        delete[] data;
    }
}