//
// Created by leafnsand on 2015/6/1.
//

#pragma once

#include "OpenGL.h"

#include "common/Data.h"
#include "common/Vertex.h"

#include <cstdint>
#include <memory>

namespace only2d
{
	enum class ImageDataWrapMode
	{
		MinInvalid,
		CLAMP,
		REPEAT,
		MIRRORED_REPEAT,
		MaxInvalid
	};

	enum class ImageDataFilterMode
	{
		MinInvalid,
		LINEAR,
		NEAREST,
		MaxInvalid
	};

	struct ImageDataWrap
	{
		ImageDataWrapMode s = ImageDataWrapMode::CLAMP;
		ImageDataWrapMode t = ImageDataWrapMode::CLAMP;
	};

	struct ImageDataFilter
	{
		ImageDataFilterMode min = ImageDataFilterMode::LINEAR;
		ImageDataFilterMode mag = ImageDataFilterMode::LINEAR;
	};

	class ImageData
	{
	public:
		ImageData(int32_t width, int32_t height, std::shared_ptr<Data> data);

		virtual ~ImageData();

		void bind();

		void unbind();

		int32_t getWidth() const;

		void setWidth(int32_t width);

		int32_t getHeight() const;

		void setHeight(int32_t height);

		const GLuint &getGLTexture() const;

		const ImageDataWrap &getWrap() const;

		void setWrap(const ImageDataWrap &wrap);

		const ImageDataFilter &getFilter() const;

		void setFilter(const ImageDataFilter &filter);

	private:
		void loadData();

		void loadDefaultData();

		void unloadData();

	protected:
		int32_t width;
		int32_t height;
		GLuint texture;
		ImageDataWrap wrap;
		ImageDataFilter filter;
		std::shared_ptr<Data> data;
		std::shared_ptr<OpenGL> gl;
		bool usingDefaultData;
	};
}