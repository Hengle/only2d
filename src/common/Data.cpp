//
// Created by leafnsand on 2015/5/30.
//

#include "Data.h"

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

    void Data::assign(uint8_t *begin, uint8_t *end)
    {
        data.assign(begin, end);
    }

    uint8_t *Data::getBuffer()
    {
        return data.data();
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