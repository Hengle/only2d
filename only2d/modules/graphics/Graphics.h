//
// Created by leafnsand on 2015/5/28.
//

#pragma once

#include "OpenGL.h"
#include "Image.h"
#include "QuadBatch.h"
#include "ImageData.h"

#include "common/Color.h"
#include "common/Module.h"

namespace only2d
{
	class Graphics : public Module
	{
	public:
		Graphics();

		virtual ~Graphics();

		void setResolution(int32_t width, int32_t height);

		void clear();

		void checkOpenGLError();

		std::shared_ptr<Shader> createShader(std::string &vertex, std::string fragment);

		std::shared_ptr<ImageData> createImageData(int32_t width, int32_t height, std::shared_ptr<Data> data);

		std::shared_ptr<Image> createImage(std::shared_ptr<ImageData> data);

		std::shared_ptr<QuadBatch> createQuadBatch();

		Color getBackgroundColor() const;

		void setBackgroundColor(const Color &backgroundColor);

		const Matrix &getProjectionMatrix() const;

		std::shared_ptr<OpenGL> &getOpenGL();

	private:
		std::shared_ptr<OpenGL> gl;
		FloatColor backgroundColor;
		Viewport viewport;
		Matrix projectionMatrix;
	};
}