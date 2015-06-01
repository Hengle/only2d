//
// Created by leafnsand on 2015/6/1.
//

#include "Image.h"

namespace only2d
{
    Image::Image(std::shared_ptr<ImageData> data) :
            data(data)
    {
    }

    Image::~Image()
    {
        data.reset();
    }

    void only2d::Image::draw()
    {

    }
}