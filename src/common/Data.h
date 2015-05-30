//
// Created by leafnsand on 2015/5/29.
//

#ifndef ONLY2D_DATA_H
#define ONLY2D_DATA_H

#include <cstddef>
#include <vector>

namespace only2d
{
    class Data
    {
    public:
        Data(size_t size);

        virtual ~Data();

        void assign(char *begin, char *end);

        char *getBuffer();

        size_t getSize();

    private:
        std::vector<char> data;
    };
}

#endif //ONLY2D_DATA_H
