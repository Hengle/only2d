//
// Created by leafnsand on 2015/5/29.
//

#ifndef ONLY2D_DATA_H
#define ONLY2D_DATA_H

#include <cstdint>
#include <vector>

namespace only2d
{
    class Data
    {
    public:
        explicit Data(size_t size);

        virtual ~Data();

        void assign(uint8_t *begin, uint8_t *end);

        uint8_t *getBuffer();

        size_t getSize();

        uint8_t &operator[](size_t index);

    private:
        std::vector<uint8_t> data;
    };
}

#endif //ONLY2D_DATA_H
