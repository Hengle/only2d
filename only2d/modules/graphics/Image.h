//
// Created by leafnsand on 2015/6/1.
//

#ifndef ONLY2D_IMAGE_H
#define ONLY2D_IMAGE_H

#include "ImageData.h"
#include "Quad.h"

#include <memory>

namespace only2d
{
	class Image : public Quad
	{
	public:
		explicit Image(std::shared_ptr<ImageData> imageData);

		virtual ~Image();

		virtual void draw() override;

		const std::shared_ptr<ImageData> &getImageData() const;

		void setImageData(const std::shared_ptr<ImageData> &imageData);

	protected:
		std::shared_ptr<ImageData> imageData;
	};
}

#endif //ONLY2D_IMAGE_H

