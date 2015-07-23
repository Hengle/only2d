#pragma once

#include "Drawable.h"
#include "ImageData.h"

#include <memory>

namespace only2d
{
	class Image : public Drawable
	{
	public:
		explicit Image(std::shared_ptr<ImageData> imageData);

		Image(float width, float height, const Color &color);

		virtual ~Image();

		virtual void draw() override;

		void onMatrixChange(const Matrix &matrix) override;

		void onColorChange() override;

		const std::shared_ptr<ImageData> &getImageData() const;

		void setImageData(const std::shared_ptr<ImageData> &imageData);

		float getHeight() const;

		void setHeight(float height);

		float getWidth() const;

		void setWidth(float width);

	private:
		Image(std::shared_ptr<ImageData> imageData, float width, float height, const Color &color);

		void updateVertices();

	protected:
		std::shared_ptr<ImageData> imageData;
		std::vector<Vertex> vertices;
		float width;
		float height;

		friend class ImageBatch;
	};
}