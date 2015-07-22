//
// Created by leafnsand on 2015/6/12.
//

#pragma once

#include "OpenGL.h"

#include "common/Data.h"

namespace only2d
{
	class OpenGLData : public Data
	{
	public:
		OpenGLData(GLenum target, GLenum usage, size_t size);

		virtual ~OpenGLData();

		virtual void syncBuffer();

		void bind();

		void unbind();

	private:
		void load();

		void unload();

	protected:
		GLenum target;
		GLenum usage;
		GLuint buffer;
		std::shared_ptr<OpenGL> gl;
	};
}