//
// Created by leafnsand on 2015/5/30.
//

#include "Data.h"

namespace only2d
{
    Data::Data(size_t size)
    {
        data.reserve(size);
    }

    Data::~Data()
    {
        data.clear();
    }

    void Data::assign(char *begin, char *end)
    {
        data.assign(begin, end);
    }

    char *Data::getBuffer()
    {
        return data.data();
    }

    size_t Data::getSize()
    {
        return data.size();
    }

    char &Data::operator[](size_t index)
    {
        return data[index];
    }
}