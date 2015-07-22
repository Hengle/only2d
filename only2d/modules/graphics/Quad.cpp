#include "Quad.h"
#include "DefaultShader.h"

#include "common/Console.h"

namespace only2d
{
	Quad::Quad(int32_t width, int32_t height) :
		vertices(4),
		width(width),
		height(height)
	{
		shader = DefaultShader::getShader(ShaderType::QuadShader);
		vertices[0].position.set(0.0f, 0.0f);
		vertices[1].position.set(0.0f, static_cast<float>(height));
		vertices[2].position.set(static_cast<float>(width), 0.0f);
		vertices[3].position.set(static_cast<float>(width), static_cast<float>(height));
		vertices[0].texcoord.set(0.0f, 1.0f);
		vertices[1].texcoord.set(0.0f, 0.0f);
		vertices[2].texcoord.set(1.0f, 1.0f);
		vertices[3].texcoord.set(1.0f, 0.0f);
	}

	Quad::~Quad()
	{
		shader.reset();
	}

	void Quad::draw()
	{
		if (visible)
		{
			Drawable::draw();
			shader->attach();
			shader->setAttributeData(attribute_POSITION, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), &vertices.data()[0].position);
			shader->setAttributeData(attribute_TEXCOORD, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), &vertices.data()[0].texcoord);
			static std::vector<float> colorData(4);
			colorData[0] = color.r / 255.0f;
			colorData[1] = color.g / 255.0f;
			colorData[2] = color.b / 255.0f;
			colorData[3] = color.a / 255.0f;
			shader->setUniformFloatData(uniform_COLOR, colorData);
			static std::vector<float> alphaData(1);
			alphaData[0] = alpha;
			shader->setUniformFloatData(uniform_ALPHA, alphaData);
			shader->setUniformMatrixData(uniform_MVP_MATRIX, getMatrix());
			shader->drawArrays(GL_TRIANGLE_STRIP, 0, 4);
			shader->detach();
		}
	}

	int32_t Quad::getHeight() const
	{
		return height;
	}

	void Quad::setHeight(int32_t height)
	{
		this->height = height;
		updateVertices();
	}

	int32_t Quad::getWidth() const
	{
		return width;
	}

	void Quad::setWidth(int32_t width)
	{
		this->width = width;
		updateVertices();
	}

	void Quad::updateVertices()
	{
		vertices[1].position.set(0.0f, static_cast<float>(width));
		vertices[2].position.set(static_cast<float>(width), 0.0f);
		vertices[3].position.set(static_cast<float>(width), static_cast<float>(height));
	}
}