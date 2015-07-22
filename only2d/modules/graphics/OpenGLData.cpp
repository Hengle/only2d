#include "OpenGLData.h"
#include "Graphics.h"

#include "common/Console.h"
#include "common/Module.h"

namespace only2d
{
	OpenGLData::OpenGLData(GLenum target, GLenum usage, size_t size) :
		Data(size),
		target(target),
		usage(usage)
	{
		auto graphics = Module::getInstance<Graphics>(ModuleType::GRAPHICS);
		if (!graphics)
		{
			Console::error << "[OpenGLData] module graphics not found!" << Console::endl;
		}
		else
		{
			gl = graphics->getOpenGL();
		}
		graphics.reset();
		load();
	}

	OpenGLData::~OpenGLData()
	{
		unload();
		gl.reset();
	}

	void OpenGLData::syncBuffer()
	{
		gl->setBufferData(target, getSize(), getBuffer(), usage);
	}

	void OpenGLData::bind()
	{
		gl->bindBuffer(target, buffer);
	}

	void OpenGLData::unbind()
	{
		gl->bindBuffer(target, 0);
	}

	void OpenGLData::load()
	{
		gl->generateBuffer(buffer);
	}

	void OpenGLData::unload()
	{
		gl->deleteBuffer(buffer);
		buffer = 0;
	}
}
