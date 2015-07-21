//
// Created by leafnsand on 2015/7/21.
//

#include "ImageBatch.h"
#include "DefaultShader.h"

namespace only2d
{
    ImageBatch::ImageBatch() :
        QuadBatch()
    {
		shader = DefaultShader::getShader(ShaderType::ImageShader);
    }

    ImageBatch::~ImageBatch()
    {
	    data.reset();
    }

    void ImageBatch::clear()
    {
	    data = nullptr;
	    QuadBatch::clear();
    }

    void ImageBatch::draw()
    {
	    data->bind();
	    QuadBatch::draw();
	    data->unbind();
    }

    void ImageBatch::addImage(std::shared_ptr<Image> image)
    {
	    if (data != image->getImageData())
	    {
		    data = image->getImageData();
	    }
	    addQuad(image);
    }
}