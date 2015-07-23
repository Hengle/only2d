#pragma once

#include "OpenGL.h"
#include "Image.h"
#include "ImageData.h"
#include "Shader.h"

#include "common/Color.h"

namespace only2d
{
	class Graphics
	{
	public:
		Graphics();

		virtual ~Graphics();

		void setResolution(int32_t width, int32_t height);

		void clear();

		void finish();

		void checkOpenGLError();

		std::shared_ptr<Shader> createShader(std::string &vertex, std::string fragment);

		std::shared_ptr<ImageData> createImageData(int32_t width, int32_t height, std::shared_ptr<Data> data);

		std::shared_ptr<Image> createImage(std::shared_ptr<ImageData> data);

		std::shared_ptr<Image> createImage(float width, float height, const Color &color);

		Color getBackgroundColor() const;

		void setBackgroundColor(const Color &backgroundColor);

		const Matrix &getProjectionMatrix() const;

	private:
		FloatColor backgroundColor;
		Viewport viewport;
		Matrix projectionMatrix;
	};
}