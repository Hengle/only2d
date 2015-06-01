//
// Created by leafnsand on 2015/6/1.
//

#ifndef ONLY2D_IMAGE_H
#define ONLY2D_IMAGE_H

#include "Drawable.h"
#include "ImageData.h"

#include <memory>

namespace only2d
{
    class Image : public Drawable
    {
    public:
        Image(std::shared_ptr<ImageData> data);

        ~Image();

        virtual void draw() override;

    protected:
        std::shared_ptr<ImageData> data;
    };
}

#endif //ONLY2D_IMAGE_H
