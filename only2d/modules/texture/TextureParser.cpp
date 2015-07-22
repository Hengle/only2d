#include "TextureParser.h"

#include "library/stb/stb_image.h"

namespace only2d
{
	bool TextureParser::recognize(TextureData &texture, std::shared_ptr<Data> data)
	{
		auto width = 0;
		auto height = 0;
		auto components = 0;
		auto status = stbi_info_from_memory(data->getBuffer(), static_cast<int32_t>(data->getSize()), &width, &height,
		                                    &components);
		if (status == 1 && width > 0 && height > 0)
		{
			texture.width = width;
			texture.height = height;
			return true;
		}
		return false;
	}

	void TextureParser::parse(TextureData &texture, std::shared_ptr<Data> data)
	{
		auto width = 0;
		auto height = 0;
		auto components = 0;
		auto buffer = stbi_load_from_memory(data->getBuffer(), static_cast<int32_t>(data->getSize()), &width, &height,
		                                    &components, 4);
		texture.assign(buffer, width * height * sizeof(Pixel));
		delete[] buffer;
	}
}
