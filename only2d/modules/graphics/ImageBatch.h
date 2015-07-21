//
// Created by leafnsand on 2015/7/21.
//

#ifndef ONLY2D_IMAGEBATCH_H
#define ONLY2D_IMAGEBATCH_H

#include "Image.h"
#include "QuadBatch.h"

namespace only2d
{
    class ImageBatch : public QuadBatch
    {
    public:
	    ImageBatch();

	    virtual ~ImageBatch();

	    virtual void clear() override;

	    virtual void draw() override;

	    void addImage(std::shared_ptr<Image> image);

    protected:
	    std::shared_ptr<ImageData> data;
    };
}

#endif //ONLY2D_IMAGEBATCH_H
