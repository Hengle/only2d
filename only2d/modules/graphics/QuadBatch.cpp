#include "QuadBatch.h"
#include "DefaultShader.h"

#include "common/Console.h"

namespace only2d
{
	QuadBatch::QuadBatch() :
		needSyncBuffer(true)
	{
		shader = DefaultShader::getShader(ShaderType::QuadShader);
	}

	QuadBatch::~QuadBatch()
	{
		shader.reset();
	}

	void QuadBatch::addQuad(std::shared_ptr<Quad> quad)
	{
		if (!quad->visible)
		{
			return;
		}
		needSyncBuffer = true;
		auto imageVertices(quad->vertices);
		for (auto i = 0; i < 4; ++i)
		{
			imageVertices[i].position = quad->getMatrix().transform(quad->vertices[i].position);
		}
		vertices.add(imageVertices);
		indices.add(1);
	}

	void QuadBatch::clear()
	{
		vertices.clear();
		indices.clear();
		needSyncBuffer = true;
	}

	void QuadBatch::draw()
	{
		if (visible)
		{
			Drawable::draw();
			vertices.bind();
			indices.bind();
			if (needSyncBuffer)
			{
				vertices.syncBuffer();
				indices.syncBuffer();
				needSyncBuffer = false;
			}
			shader->attach();
			shader->setAttributeData(attribute_POSITION, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<GLvoid *>(offsetof(Vertex, position)));
			shader->setAttributeData(attribute_TEXCOORD, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<GLvoid *>(offsetof(Vertex, texcoord)));
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
			shader->drawElements(GL_TRIANGLES, indices.getIndexCount(), GL_UNSIGNED_SHORT, nullptr);
			vertices.unbind();
			indices.unbind();
			shader->detach();
		}
	}
}
