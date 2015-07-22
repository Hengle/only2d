#pragma once

#include "Quad.h"
#include "Shader.h"
#include "VertexData.h"
#include "VertexIndexData.h"

namespace only2d
{
	class QuadBatch : public Drawable
	{
	public:
		QuadBatch();

		virtual ~QuadBatch();

		void addQuad(std::shared_ptr<Quad> quad);

		virtual void clear();

		virtual void draw() override;

	protected:
		std::shared_ptr<Shader> shader;
		VertexIndexData indices;
		VertexData vertices;
		bool needSyncBuffer;
	};
}