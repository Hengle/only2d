#pragma once

#include <cstdint>

namespace only2d
{
	enum class LuaModule : int32_t
	{
		// invalid
		MinInvalid,
		// common
		Only2D,
		// application
		Application,
		// event
		Event,
		// filesystem
		FileSystem,
		// graphics
		Graphics,
		// keyboard,
		Keyboard,
		// texture
		Texture,
		// timer
		Timer,
		// window
		Window,
		// invalid
		MaxInvalid
	};

	enum class LuaType : int32_t
	{
		// invalid
		MinInvalid,
		// common
		Data,
		// filesystem
		File,
		FileData,
		// graphics
		Drawable,
		Image,
		ImageBatch,
		ImageData,
		Quad,
		QuadBatch,
		Shader,
		// texture
		TextureData,
		// invalid
		MaxInvalid
	};
}