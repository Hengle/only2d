#include "Image.h"
#include "DefaultShader.h"

#include "common/Console.h"

namespace only2d
{
	Image::Image(std::shared_ptr<ImageData> imageData) :
		Quad(imageData->getWidth(), imageData->getHeight()),
		imageData(imageData)
	{
		shader = DefaultShader::getShader(ShaderType::ImageShader);
	}

	Image::~Image()
	{
		imageData.reset();
	}

	void Image::draw()
	{
		imageData->bind();
		Quad::draw();
		imageData->unbind();
	}

    const std::shared_ptr<ImageData> &Image::getImageData() const
    {
	    return imageData;
    }

    void Image::setImageData(const std::shared_ptr<ImageData> &imageData)
    {
		this->imageData = imageData;
    }
}
