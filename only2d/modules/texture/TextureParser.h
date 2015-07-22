#pragma once

#include "TextureData.h"

namespace only2d
{
	class TextureParser
	{
	public:
		static bool recognize(TextureData &texture, std::shared_ptr<Data> data);

		static void parse(TextureData &texture, std::shared_ptr<Data> data);
	};
}