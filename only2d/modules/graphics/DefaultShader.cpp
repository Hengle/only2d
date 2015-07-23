#include "DefaultShader.h"
#include "Graphics.h"

#include "common/Module.h"

namespace only2d
{
	const std::string DefaultShader::attribute_POSITION = "aPosition";
	const std::string DefaultShader::attribute_TEXCOORD = "aTexcoord";
	const std::string DefaultShader::attribute_COLOR = "aColor";
	const std::string DefaultShader::uniform_PROJECTION_MATRIX = "uProjectionMatrix";

	const std::string DefaultShader::textureVertexSource =
		"#ifndef GL_ES\n"
		"#define lowp\n"
		"#define mediump\n"
		"#define highp\n"
		"#endif\n"
		"#ifdef GL_ES\n"
		"precision mediump float;\n"
		"#endif\n"
		"attribute vec4 aPosition;\n"
		"attribute vec2 aTexcoord;\n"
		"attribute vec4 aColor;\n"
		"uniform mat4 uProjectionMatrix;\n"
		"varying vec2 vTexcoord;\n"
		"varying vec4 vColor;\n"
		"void main() {\n"
		"\tvTexcoord = aTexcoord;\n"
		"\tvColor = aColor;\n"
		"\tgl_Position = uProjectionMatrix * aPosition;\n"
		"}";
	const std::string DefaultShader::textureFragmentSource =
		"#ifndef GL_ES\n"
		"#define lowp\n"
		"#define mediump\n"
		"#define highp\n"
		"#endif\n"
		"#ifdef GL_ES\n"
		"precision mediump float;\n"
		"#endif\n"
		"uniform sampler2D uTexture;\n"
		"varying vec2 vTexcoord;\n"
		"varying vec4 vColor;\n"
		"void main() {\n"
		"\tgl_FragColor = texture2D(uTexture, vTexcoord) * vColor;\n"
		"}";

	const std::string DefaultShader::noTextureVertexSource =
		"#ifndef GL_ES\n"
		"#define lowp\n"
		"#define mediump\n"
		"#define highp\n"
		"#endif\n"
		"#ifdef GL_ES\n"
		"precision mediump float;\n"
		"#endif\n"
		"attribute vec4 aPosition;\n"
		"attribute vec4 aColor;\n"
		"uniform mat4 uProjectionMatrix;\n"
		"varying vec4 vColor;\n"
		"void main() {\n"
		"\tvColor = aColor;\n"
		"\tgl_Position = uProjectionMatrix * aPosition;\n"
		"}";
	const std::string DefaultShader::noTextureFragmentSource =
		"#ifndef GL_ES\n"
		"#define lowp\n"
		"#define mediump\n"
		"#define highp\n"
		"#endif\n"
		"#ifdef GL_ES\n"
		"precision mediump float;\n"
		"#endif\n"
		"varying vec4 vColor;\n"
		"void main() {\n"
		"\tgl_FragColor = vColor;\n"
		"}";

	std::shared_ptr<Shader> DefaultShader::shaders[] = {};

	std::shared_ptr<Shader> DefaultShader::getInstance(DefaultShaderType type)
	{
		auto index = static_cast<int32_t>(type);
		if (!shaders[index])
		{
			switch (type)
			{
			case DefaultShaderType::Texture:
				shaders[index] = std::make_shared<Shader>(textureVertexSource, textureFragmentSource);
				break;
			case DefaultShaderType::NoTexture:
				shaders[index] = std::make_shared<Shader>(noTextureVertexSource, noTextureFragmentSource);
				break;
			default:
				break;
			}
			shaders[index]->attach();
			shaders[index]->setUniformMatrixData(uniform_PROJECTION_MATRIX, Module::getInstance<Graphics>(ModuleType::GRAPHICS)->getProjectionMatrix());
			shaders[index]->detach();
		}
		return shaders[index];
	}
}