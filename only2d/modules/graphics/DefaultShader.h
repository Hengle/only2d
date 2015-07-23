#pragma once

#include "Shader.h"

namespace only2d
{
	enum class DefaultShaderType : int32_t
	{
		Texture,
		NoTexture,
		MaxCount
	};

    class DefaultShader
    {
	public:
		static std::shared_ptr<Shader> getInstance(DefaultShaderType type);

	public:
		static const std::string attribute_POSITION;
		static const std::string attribute_TEXCOORD;
		static const std::string attribute_COLOR;
		static const std::string uniform_PROJECTION_MATRIX;

	private:
		static const std::string textureVertexSource;
		static const std::string textureFragmentSource;

		static const std::string noTextureVertexSource;
		static const std::string noTextureFragmentSource;

		static std::shared_ptr<Shader> shaders[static_cast<int32_t>(DefaultShaderType::MaxCount)];
    };
}