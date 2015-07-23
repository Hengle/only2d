#pragma once

#include "ImageData.h"
#include "VertexData.h"
#include "VertexIndexData.h"

namespace only2d
{
    class ImageBatch
    {
    public:
		ImageBatch();

		virtual ~ImageBatch();

		void add(const std::shared_ptr<ImageData> imageData, const BlendMode &blendMode, const Matrix &matrix, const std::vector<Vertex> &vertices);

		void clear();

		void draw();

		static std::shared_ptr<ImageBatch> getInstance();

    protected:
	    std::shared_ptr<ImageData> imageData;
		BlendMode blendMode;
		VertexIndexData indices;
		VertexData vertices;

		static std::shared_ptr<ImageBatch> instance;
    };
}