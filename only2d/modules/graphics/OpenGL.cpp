//
// Created by leafnsand on 2015/5/28.
//

#include "ImageData.h"
#include "common/Console.h"

namespace only2d
{
	OpenGL::OpenGL() :
		drawCalls(0),
		textureCount(0),
		currentBlendMode(BlendMode::MinInvalid)
	{
	}

	OpenGL::~OpenGL()
	{
	}

	void OpenGL::initContext()
	{
		if (!gladLoadGL())
		{
			Console::error << "[OpenGL] initialize glew fail." << Console::endl;
		}
		glGetIntegerv(GL_MAX_TEXTURE_SIZE, &maxTextureSize);
		glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &maxTextureCount);
		glEnable(GL_BLEND);
	}

	void OpenGL::clear(float r, float g, float b, float a)
	{
		glClearColor(r, g, b, a);
		glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void OpenGL::generateTexture(GLuint &texture)
	{
		if (textureCount < maxTextureCount)
		{
			++textureCount;
			glGenTextures(1, &texture);
		}
		else
		{
			Console::error << "[OpenGL] too many textures!" << Console::endl;
		}
	}

	void OpenGL::deleteTexture(GLuint &texture)
	{
		--textureCount;
		glDeleteTextures(1, &texture);
	}

	void OpenGL::bindTexture(const GLuint &texture)
	{
		glBindTexture(GL_TEXTURE_2D, texture);
	}

	void OpenGL::setTextureFilter(const ImageDataFilter &filter)
	{
		auto glFilterMode = [](ImageDataFilterMode filterMode) -> GLint
			{
				switch (filterMode)
				{
				case ImageDataFilterMode::LINEAR:
					return GL_LINEAR;
				case ImageDataFilterMode::NEAREST:
					return GL_NEAREST;
				}
				return GL_LINEAR;
			};
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, glFilterMode(filter.min));
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, glFilterMode(filter.mag));
	}

	void OpenGL::setTextureWrap(const ImageDataWrap &wrap)
	{
		auto glWrapMode = [](ImageDataWrapMode wrapMode) -> GLint
			{
				switch (wrapMode)
				{
				case ImageDataWrapMode::CLAMP:
					return GL_CLAMP_TO_EDGE;
				case ImageDataWrapMode::REPEAT:
					return GL_REPEAT;
				case ImageDataWrapMode::MIRRORED_REPEAT:
					return GL_MIRRORED_REPEAT;
				}
				return GL_CLAMP_TO_EDGE;
			};
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, glWrapMode(wrap.s));
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, glWrapMode(wrap.t));
	}

	bool OpenGL::setTextureData(GLsizei width, GLsizei height, std::shared_ptr<Data> data)
	{
		if (data)
		{
			checkErrors();
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data->getBuffer());
			if (glGetError() == GL_NO_ERROR)
			{
				return true;
			}
		}
		return false;
	}

	void OpenGL::checkErrors()
	{
		GLenum error;
		while ((error = glGetError()) != GL_NO_ERROR)
		{
			switch (error)
			{
			case GL_NO_ERROR:
				Console::debug << "GL_NO_ERROR" << Console::endl;
				break;
			case GL_INVALID_ENUM:
				Console::debug << "GL_INVALID_ENUM" << Console::endl;
				break;
			case GL_INVALID_OPERATION:
				Console::debug << "GL_INVALID_OPERATION" << Console::endl;
				break;
			case GL_INVALID_VALUE:
				Console::debug << "GL_INVALID_VALUE" << Console::endl;
				break;
			case GL_INVALID_FRAMEBUFFER_OPERATION:
				Console::debug << "GL_INVALID_FRAMEBUFFER_OPERATION" << Console::endl;
				break;
			case GL_OUT_OF_MEMORY:
				Console::debug << "GL_OUT_OF_MEMORY" << Console::endl;
				break;
			default:
				Console::debug << "UNKNOWN_ERROR" << Console::endl;
			}
		}
	}

	GLuint OpenGL::createShader(GLenum type)
	{
		return glCreateShader(type);
	}

	void OpenGL::deleteShader(GLuint shader)
	{
		glDeleteShader(shader);
	}

	void OpenGL::setShaderSource(GLuint shader, const std::string &source)
	{
		auto src = source.c_str();
		auto len = static_cast<GLint>(source.length());
		glShaderSource(shader, 1, &src, &len);
	}

	bool OpenGL::compileShader(GLuint shader)
	{
		glCompileShader(shader);
		GLint status;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
		if (status == GL_FALSE)
		{
			auto errorLength = 0;
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &errorLength);
			if (errorLength > 0)
			{
				auto error = new GLchar[errorLength];
				glGetShaderInfoLog(shader, errorLength, nullptr, error);
				Console::log << "[OpenGL] compile shader log: " << error << Console::endl;
				delete[] error;
			}
			return false;
		}
		return true;
	}

	GLuint OpenGL::createProgram()
	{
		return glCreateProgram();
	}

	void OpenGL::deleteProgram(GLuint program)
	{
		glDeleteProgram(program);
	}

	void OpenGL::attachShader(GLuint program, GLuint shader)
	{
		glAttachShader(program, shader);
	}

	bool OpenGL::linkProgram(GLuint program)
	{
		glLinkProgram(program);
		GLint status;
		glGetProgramiv(program, GL_LINK_STATUS, &status);
		if (status == GL_FALSE)
		{
			auto errorLength = 0;
			glGetProgramiv(program, GL_INFO_LOG_LENGTH, &errorLength);
			if (errorLength > 0)
			{
				auto error = new GLchar[errorLength];
				glGetProgramInfoLog(program, errorLength, nullptr, error);
				Console::log << "[OpenGL] link program log: " << error << Console::endl;
				delete[] error;
			}
			return false;
		}
		return true;
	}

	void OpenGL::useProgram(GLuint program)
	{
		glUseProgram(program);
	}

	GLint OpenGL::getProgramAttributeLocation(GLuint shader, const std::string &name)
	{
		return glGetAttribLocation(shader, name.c_str());
	}

	void OpenGL::enableProgramAttribute(GLuint position)
	{
		glEnableVertexAttribArray(position);
	}

	void OpenGL::setProgramAttributePointer(GLuint position, GLint size, GLenum type, GLboolean normalized,
	                                        GLsizei stride, const GLvoid *pointer)
	{
		glVertexAttribPointer(position, size, type, normalized, stride, pointer);
	}

	GLint OpenGL::getProgramUniformLocation(GLuint shader, const std::string &name)
	{
		return glGetUniformLocation(shader, name.c_str());
	}

	void OpenGL::setProgramIntUniformData(GLuint position, const std::vector<int32_t> &data)
	{
		switch (data.size())
		{
		case 1:
			glUniform1i(position, data[0]);
			break;
		case 2:
			glUniform2i(position, data[0], data[1]);
			break;
		case 3:
			glUniform3i(position, data[0], data[1], data[2]);
			break;
		case 4:
			glUniform4i(position, data[0], data[1], data[2], data[3]);
			break;
		default:
			Console::error << "[OpenGL] wrong int uniform data size." << Console::endl;
			break;
		}
	}

	void OpenGL::setProgramFloatUniformData(GLuint position, const std::vector<float> &data)
	{
		switch (data.size())
		{
		case 1:
			glUniform1f(position, data[0]);
			break;
		case 2:
			glUniform2f(position, data[0], data[1]);
			break;
		case 3:
			glUniform3f(position, data[0], data[1], data[2]);
			break;
		case 4:
			glUniform4f(position, data[0], data[1], data[2], data[3]);
			break;
		default:
			Console::error << "[OpenGL] wrong float uniform data size." << Console::endl;
			break;
		}
	}

	void OpenGL::setProgramMatrixUniformData(GLuint position, const Matrix &matrix)
	{
		glUniformMatrix4fv(position, 1, GL_FALSE, matrix.getBuffer());
	}

	void OpenGL::generateBuffer(GLuint &buffer)
	{
		return glGenBuffers(1, &buffer);
	}

	void OpenGL::deleteBuffer(GLuint &buffer)
	{
		glDeleteBuffers(1, &buffer);
	}

	void OpenGL::bindBuffer(GLenum target, GLuint buffer)
	{
		glBindBuffer(target, buffer);
	}

	void OpenGL::setBufferData(GLenum target, GLsizeiptr size, const GLvoid *data, GLenum usage)
	{
		glBufferData(target, size, data, usage);
	}

	void OpenGL::drawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid *buffer)
	{
		glDrawElements(mode, count, type, buffer);
		++drawCalls;
	}

	void OpenGL::drawArrays(GLenum mode, GLint first, GLsizei count)
	{
		glDrawArrays(mode, first, count);
		++drawCalls;
	}

	int32_t OpenGL::getDrawCalls() const
	{
		return drawCalls;
	}

	int32_t OpenGL::getTextureCount() const
	{
		return textureCount;
	}

	int32_t OpenGL::getMaxTextureSize() const
	{
		return maxTextureSize;
	}

	void OpenGL::setViewport(const Viewport &viewport)
	{
		this->viewport = viewport;
		glViewport(this->viewport.x, this->viewport.y, this->viewport.width, this->viewport.height);
		setScissor(this->scissor);
	}

	const Viewport &OpenGL::getViewport() const
	{
		return viewport;
	}

	void OpenGL::setScissor(const Viewport &scissor)
	{
		this->scissor = scissor;
		glScissor(this->scissor.x, this->scissor.y, this->scissor.width, this->scissor.height);
	}

	const Viewport &OpenGL::getScissor() const
	{
		return scissor;
	}

	const BlendMode &OpenGL::getCurrentBlendMode() const
	{
		return currentBlendMode;
	}

	void OpenGL::setCurrentBlendMode(const BlendMode &mode)
	{
		if (mode == BlendMode::MinInvalid || mode == currentBlendMode)
		{
			return;
		}
		currentBlendMode = mode;
		GLenum func = GL_FUNC_ADD;
		GLenum srcRGB = GL_ONE;
		GLenum srcA = GL_ONE;
		GLenum dstRGB = GL_ZERO;
		GLenum dstA = GL_ZERO;
		switch (currentBlendMode)
		{
		case BlendMode::ALPHA:
			srcRGB = GL_SRC_ALPHA;
			srcA = GL_ONE;
			dstRGB = dstA = GL_ONE_MINUS_SRC_ALPHA;
			break;
		case BlendMode::MULTIPLY:
			srcRGB = srcA = GL_DST_COLOR;
			dstRGB = dstA = GL_ZERO;
			break;
		case BlendMode::PRE_MULTIPLIED:
			srcRGB = srcA = GL_ONE;
			dstRGB = dstA = GL_ONE_MINUS_SRC_ALPHA;
			break;
		case BlendMode::SUBTRACT:
			func = GL_FUNC_REVERSE_SUBTRACT;
		case BlendMode::ADD:
			srcRGB = srcA = GL_SRC_ALPHA;
			dstRGB = dstA = GL_ONE;
			break;
		case BlendMode::SCREEN:
			srcRGB = srcA = GL_ONE;
			dstRGB = dstA = GL_ONE_MINUS_SRC_COLOR;
			break;
		case BlendMode::REPLACE:
		default:
			srcRGB = srcA = GL_ONE;
			dstRGB = dstA = GL_ZERO;
			break;
		}
		glBlendEquation(func);
		glBlendFuncSeparate(srcRGB, dstRGB, srcA, dstA);
	}
}
