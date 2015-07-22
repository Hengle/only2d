#pragma once

#include "TextureData.h"

#include <memory>

namespace only2d
{
	class Texture
	{
	public:
		Texture();

		virtual ~Texture();

		std::shared_ptr<TextureData> createTextureData(std::shared_ptr<Data> data);

		std::shared_ptr<TextureData> createTextureData(int32_t width, int32_t height, const Color &color);
	};
}