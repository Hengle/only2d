#include "OpenGLData.h"

namespace only2d
{
	OpenGLData::OpenGLData(GLenum target, GLenum usage, size_t size) :
		Data(size),
		target(target),
		usage(usage)
	{
		load();
	}

	OpenGLData::~OpenGLData()
	{
		unload();
	}

	void OpenGLData::syncBuffer()
	{
		OpenGL::getInstance()->setBufferData(target, getSize(), getBuffer(), usage);
	}

	void OpenGLData::bind()
	{
		OpenGL::getInstance()->bindBuffer(target, buffer);
	}

	void OpenGLData::unbind()
	{
		OpenGL::getInstance()->bindBuffer(target, 0);
	}

	void OpenGLData::load()
	{
		OpenGL::getInstance()->generateBuffer(buffer);
	}

	void OpenGLData::unload()
	{
		OpenGL::getInstance()->deleteBuffer(buffer);
		buffer = 0;
	}
}
