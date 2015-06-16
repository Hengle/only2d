//
// Created by leafnsand on 2015/6/15.
//

#include "VertexData.h"

#include "common/Console.h"

namespace only2d
{
    VertexData::VertexData() :
            OpenGLData(GL_ARRAY_BUFFER, GL_DYNAMIC_DRAW, 4 * 16 * sizeof(Vertex)),
            size(0),
            capacity(16)
    {
    }

    VertexData::~VertexData()
    {
    }

    void VertexData::syncBuffer()
    {
        gl->setBufferData(target, 4 * size * sizeof(Vertex), getBuffer(), usage);
    }

    void VertexData::add(const std::vector<Vertex> vertices)
    {
        if (vertices.size() != 4)
        {
            Console::error << "[VertexData] vertices vector size must be 4!" << Console::endl;
            return;
        }
        if (size == capacity)
        {
            capacity *= 2;
            assign(nullptr, 4 * size * sizeof(Vertex), 4 * size * sizeof(Vertex));
        }
        assign((uint8_t *) vertices.data(), 4 * sizeof(Vertex), 4 * size * sizeof(Vertex));
        ++size;
    }

    void VertexData::clear()
    {
        size = 0;
    }
}