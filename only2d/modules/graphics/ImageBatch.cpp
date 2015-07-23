#include "ImageBatch.h"
#include "DefaultShader.h"

namespace only2d
{
	std::shared_ptr<ImageBatch> ImageBatch::instance(nullptr);

	std::shared_ptr<ImageBatch> ImageBatch::getInstance()
	{
		if (!instance)
		{
			instance = std::make_shared<ImageBatch>();
		}
		return instance;
	}

    ImageBatch::ImageBatch():
		imageData(nullptr),
		blendMode(BlendMode::MinInvalid)
    {
    }

    ImageBatch::~ImageBatch()
    {
		imageData.reset();
    }

	void ImageBatch::add(const std::shared_ptr<ImageData> imageData, const BlendMode &blendMode, const Matrix &matrix, const std::vector<Vertex> &vertices)
	{
		if (this->imageData != imageData || this->blendMode != blendMode)
		{
			draw();
		}
		this->blendMode = blendMode;
		this->imageData = imageData;
		this->vertices.add(vertices);
		this->indices.add(1);
	}

	void ImageBatch::clear()
    {
		imageData.reset();
		blendMode = BlendMode::MinInvalid;
		vertices.clear();
		indices.clear();
    }

    void ImageBatch::draw()
    {
		if (vertices.size > 0)
		{
			auto shader = imageData ? DefaultShader::getInstance(DefaultShaderType::Texture) : DefaultShader::getInstance(DefaultShaderType::NoTexture);

			if (imageData)
			{
				imageData->bind();
			}
			vertices.bind();
			indices.bind();
			shader->attach();

			vertices.syncBuffer();
			indices.syncBuffer();

			shader->setBlendMode(blendMode);
			shader->setAttributeData(DefaultShader::attribute_POSITION, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<GLvoid *>(offsetof(Vertex, position)));
			shader->setAttributeData(DefaultShader::attribute_TEXCOORD, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<GLvoid *>(offsetof(Vertex, texcoord)));
			shader->setAttributeData(DefaultShader::attribute_COLOR, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), reinterpret_cast<GLvoid *>(offsetof(Vertex, color)));
			shader->drawElements(GL_TRIANGLES, indices.getIndexCount(), GL_UNSIGNED_SHORT, nullptr);

			if (imageData)
			{
				imageData->unbind();
			}
			vertices.unbind();
			indices.unbind();
			shader->detach();

			clear();
		}
    }
}