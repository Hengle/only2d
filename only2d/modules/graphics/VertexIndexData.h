//
// Created by leafnsand on 2015/6/15.
//

#pragma once

#include "OpenGLData.h"

namespace only2d
{
	class VertexIndexData : public OpenGLData
	{
	public:
		VertexIndexData();

		virtual ~VertexIndexData();

		virtual void syncBuffer() override;

		void add(int32_t count);

		void remove(int32_t count);

		void clear();

		int32_t getIndexCount() const;

	private:
		void expand();

		void fill(int32_t length, int32_t offset = 0);

	private:
		int32_t size;
		int32_t capacity;
	};
}