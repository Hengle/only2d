//
// Created by leafnsand on 2015/5/30.
//

#include "Data.h"

#include <cstring>

namespace only2d
{
    Data::Data(size_t size) :
            data(size)
    {
    }

    Data::~Data()
    {
        data.clear();
    }

    void Data::assign(uint8_t *buffer, size_t length, size_t offset)
    {
        if (length == 0)
        {
            length = data.size();
        }
        if (length + offset > data.size())
        {
            data.reserve(length + offset);
        }
        if (buffer)
        {
            std::memcpy(data.data() + offset, buffer, length);
        }
    }

    uint8_t *Data::getBuffer(size_t offset)
    {
        return data.data() + offset;
    }

    size_t Data::getSize()
    {
        return data.size();
    }

    uint8_t &Data::operator[](size_t index)
    {
        return data[index];
    }
}