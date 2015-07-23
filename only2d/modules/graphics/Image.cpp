#include "Image.h"
#include "ImageBatch.h"

namespace only2d
{
	Image::Image(std::shared_ptr<ImageData> imageData) :
		Image(imageData, static_cast<float>(imageData->getWidth()), static_cast<float>(imageData->getHeight()), ColorWhite)
	{
	}

	Image::Image(float width, float height, const Color &color) :
		Image(nullptr, width, height, color)
	{
	}

	Image::Image(std::shared_ptr<ImageData> imageData, float width, float height, const Color &color) :
		imageData(imageData),
		width(width),
		height(height)
	{
		vertices = 
		{
			{ { 0.0f, 0.0f }, { 0.0f, 1.0f }, color }, 
			{ { 0.0f, height }, { 0.0f, 0.0f }, color },
			{ { width, 0.0f }, { 1.0f, 1.0f }, color },
			{ { width, height }, { 1.0f, 0.0f }, color }
		};
	}

	Image::~Image()
	{
		imageData.reset();
	}

	void Image::draw()
	{
		ImageBatch::getInstance()->add(imageData, mode, getMatrix(), vertices);
	}

	void Image::onMatrixChange(const Matrix &matrix)
	{
		for (auto i = 0; i < 4; ++i)
		{
			vertices[i].position = matrix.transform(vertices[i].position);
		}
	}

	void Image::onColorChange()
	{
		for (auto i = 0; i < 4; ++i)
		{
			vertices[i].color = color;
		}
	}

	const std::shared_ptr<ImageData> &Image::getImageData() const
    {
	    return imageData;
    }

    void Image::setImageData(const std::shared_ptr<ImageData> &imageData)
    {
		this->imageData = imageData;
    }

	float Image::getHeight() const
	{
		return height;
	}

	void Image::setHeight(float height)
	{
		this->height = height;
		updateVertices();
	}

	float Image::getWidth() const
	{
		return width;
	}

	void Image::setWidth(float width)
	{
		this->width = width;
		updateVertices();
	}

	void Image::updateVertices()
	{
		vertices[1].position.set(0.0f, width);
		vertices[2].position.set(width, 0.0f);
		vertices[3].position.set(width, height);
	}
}
