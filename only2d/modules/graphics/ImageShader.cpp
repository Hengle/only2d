//
// Created by leafnsand on 2015/6/5.
//

#include "ImageShader.h"
#include "Graphics.h"

#include "common/Console.h"

namespace only2d
{
	static const std::string attribute_POSITION = "aPosition";
	static const std::string attribute_TEXCOORD = "aTexcoord";
	static const std::string uniform_PROJECTION_MATRIX = "uProjectionMatrix";
	static const std::string uniform_MVP_MATRIX = "uMVPMatrix";
	static const std::string uniform_COLOR = "uColor";
	static const std::string uniform_ALPHA = "uAlpha";

	static std::string vertexSource = "#ifndef GL_ES\n"
	"#define lowp\n"
	"#define mediump\n"
	"#define highp\n"
	"#endif\n"
	"#ifdef GL_ES\n"
	"precision mediump float;\n"
	"#endif\n"
	"attribute vec4 aPosition;\n"
	"attribute vec2 aTexcoord;\n"
	"uniform mat4 uMVPMatrix;\n"
	"uniform mat4 uProjectionMatrix;\n"
	"varying vec2 vTexcoord;\n"
	"void main() {\n"
	"\tvTexcoord = aTexcoord;\n"
	"\tgl_Position = uProjectionMatrix * uMVPMatrix * aPosition;\n"
	"}";
	static std::string fragmentSource = "#ifndef GL_ES\n"
	"#define lowp\n"
	"#define mediump\n"
	"#define highp\n"
	"#endif\n"
	"#ifdef GL_ES\n"
	"precision mediump float;\n"
	"#endif\n"
	"varying vec2 vTexcoord;\n"
	"uniform vec4 uColor;\n"
	"uniform float uAlpha;\n"
	"uniform sampler2D uTexture;\n"
	"void main() {\n"
	"\tvec4 color = uColor;\n"
	"\tcolor.a = color.a * uAlpha;\n"
	"\tgl_FragColor = texture2D(uTexture, vTexcoord) * color;\n"
	"}";

	ImageShader::ImageShader() :
		Shader(vertexSource, fragmentSource)
	{
		attach();
		auto graphics = Module::getInstance<Graphics>(ModuleType::GRAPHICS);
		if (!graphics)
		{
			Console::error << "[ImageBatchShader] module graphics not found!" << Console::endl;
		}
		else
		{
			setUniformMatrixData(uniform_PROJECTION_MATRIX, graphics->getProjectionMatrix());
		}
		graphics.reset();
		detach();
	}

	ImageShader::~ImageShader()
	{
	}

	void ImageShader::setVertexData(const std::vector<Vertex> &vertices)
	{
		setAttributeData(attribute_POSITION, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), &vertices.data()[0].position);
		setAttributeData(attribute_TEXCOORD, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), &vertices.data()[0].texcoord);
	}

	void ImageShader::setColor(const Color &color)
	{
		static std::vector<float> data(4);
		data[0] = color.r / 255.0f;
		data[1] = color.g / 255.0f;
		data[2] = color.b / 255.0f;
		data[3] = color.a / 255.0f;
		setUniformFloatData(uniform_COLOR, data);
	}

	void ImageShader::setAlpha(const float &alpha)
	{
		static std::vector<float> data(1);
		data[0] = alpha;
		setUniformFloatData(uniform_ALPHA, data);
	}

	void ImageShader::setMVPMatrix(const Matrix &matrix)
	{
		setUniformMatrixData(uniform_MVP_MATRIX, matrix);
	}

	void ImageShader::draw()
	{
		gl->drawArrays(GL_TRIANGLE_STRIP, 0, 4);
	}
}
