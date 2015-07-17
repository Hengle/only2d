//
// Created by leafnsand on 2015/6/15.
//

#ifndef ONLY2D_IMAGEBATCHSHADER_H
#define ONLY2D_IMAGEBATCHSHADER_H

#include "Shader.h"
#include "VertexData.h"
#include "VertexIndexData.h"

namespace only2d
{
	class ImageBatchShader : public Shader
	{
	public:
		ImageBatchShader();

		virtual ~ImageBatchShader();

		void setVertexData(VertexData &vertices);

		void setColor(const Color &color);

		void setAlpha(const float &alpha);

		void setMVPMatrix(const Matrix &matrix);

		void draw(VertexIndexData &indices);
	};
}

#endif //ONLY2D_IMAGEBATCHSHADER_H

