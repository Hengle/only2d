//
// Created by leafnsand on 2015/6/15.
//

#ifndef ONLY2D_QUADBATCH_H
#define ONLY2D_QUADBATCH_H

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

#endif //ONLY2D_QUADBATCH_H

