#include "Shader.h"

#include "common/Console.h"

namespace only2d
{
	Shader::Shader(const std::string &vertex, const std::string &fragment) :
		vertex(vertex),
		fragment(fragment),
		program(0)
	{
		load();
	}

	Shader::~Shader()
	{
		unload();
	}

	bool Shader::match(const std::string &vertex, const std::string &fragment)
	{
		return this->vertex == vertex && this->fragment == fragment;
	}

	void Shader::setBlendMode(const BlendMode& mode)
	{
		OpenGL::getInstance()->setCurrentBlendMode(mode);
	}

	void Shader::setAttributeData(const std::string &name, GLint size, GLenum type, GLboolean normalized,
	                              GLsizei stride, const GLvoid *pointer)
	{
		if (program == 0)
		{
			return;
		}
		auto position = 0;
		if (attributes.find(name) == attributes.end())
		{
			position = OpenGL::getInstance()->getProgramAttributeLocation(program, name);
			attributes.insert(std::pair<const std::string, GLint>(name, position));
			if (position != -1)
			{
				OpenGL::getInstance()->enableProgramAttribute(static_cast<GLuint>(position));
			}
		}
		else
		{
			position = attributes.at(name);
		}
		if (position != -1)
		{
			OpenGL::getInstance()->setProgramAttributePointer(static_cast<GLuint>(position), size, type, normalized, stride, pointer);
		}
	}

	void Shader::setUniformIntData(const std::string &name, const std::vector<int32_t> &data)
	{
		if (program == 0)
		{
			return;
		}
		auto position = 0;
		if (uniforms.find(name) == uniforms.end())
		{
			position = OpenGL::getInstance()->getProgramUniformLocation(program, name);
			uniforms.insert(std::pair<const std::string, GLint>(name, position));
		}
		else
		{
			position = uniforms.at(name);
		}
		if (position != -1)
		{
			OpenGL::getInstance()->setProgramIntUniformData(static_cast<GLuint>(position), data);
		}
	}

	void Shader::setUniformFloatData(const std::string &name, const std::vector<float> &data)
	{
		if (program == 0)
		{
			return;
		}
		auto position = 0;
		if (uniforms.find(name) == uniforms.end())
		{
			position = OpenGL::getInstance()->getProgramUniformLocation(program, name);
			uniforms.insert(std::pair<const std::string, GLint>(name, position));
		}
		else
		{
			position = uniforms.at(name);
		}
		if (position != -1)
		{
			OpenGL::getInstance()->setProgramFloatUniformData(static_cast<GLuint>(position), data);
		}
	}

	void Shader::setUniformMatrixData(const std::string &name, const Matrix &matrix)
	{
		if (program == 0)
		{
			return;
		}
		auto position = 0;
		if (uniforms.find(name) == uniforms.end())
		{
			position = OpenGL::getInstance()->getProgramUniformLocation(program, name);
			uniforms.insert(std::pair<const std::string, GLint>(name, position));
		}
		else
		{
			position = uniforms.at(name);
		}
		if (position != -1)
		{
			OpenGL::getInstance()->setProgramMatrixUniformData(static_cast<GLuint>(position), matrix);
		}
	}

    void Shader::drawArrays(GLenum mode, GLint first, GLsizei count)
    {
		OpenGL::getInstance()->drawArrays(mode, first, count);
    }

    void Shader::drawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid *buffer)
    {
		OpenGL::getInstance()->drawElements(mode, count, type, buffer);
    }

    void Shader::attach()
	{
		if (program != 0)
		{
			OpenGL::getInstance()->useProgram(program);
		}
	}

	void Shader::detach()
	{
		OpenGL::getInstance()->useProgram(0);
	}

	void Shader::load()
	{
		auto vertexShader = compile(GL_VERTEX_SHADER, vertex);
		auto fragmentShader = compile(GL_FRAGMENT_SHADER, fragment);
		if (vertexShader == 0 || fragmentShader == 0)
		{
			if (vertexShader == 0)
			{
				Console::log << "[Shader] compile vertex shader error: " << Console::endl
					<< vertex << Console::endl;
			}
			if (fragmentShader == 0)
			{
				Console::log << "[Shader] compile fragment shader error: " << Console::endl
					<< fragment << Console::endl;
			}
			return;
		}
		program = OpenGL::getInstance()->createProgram();
		if (program == 0)
		{
			Console::error << "[Shader] create program error." << Console::endl;
		}
		OpenGL::getInstance()->attachShader(program, vertexShader);
		OpenGL::getInstance()->attachShader(program, fragmentShader);
		if (!OpenGL::getInstance()->linkProgram(program))
		{
			OpenGL::getInstance()->deleteProgram(program);
			program = 0;
		}
		OpenGL::getInstance()->deleteShader(vertexShader);
		OpenGL::getInstance()->deleteShader(fragmentShader);
	}

	void Shader::unload()
	{
		if (program != 0)
		{
			OpenGL::getInstance()->deleteProgram(program);
		}
	}

	GLuint Shader::compile(GLenum type, const std::string &source)
	{
		auto shader = OpenGL::getInstance()->createShader(type);
		if (shader == 0)
		{
			Console::error << "[Shader] create " << ((type == GL_VERTEX_SHADER) ? "vertex" : "fragment")
				<< " shader fail." << Console::endl;
		}
		OpenGL::getInstance()->setShaderSource(shader, source);
		if (!OpenGL::getInstance()->compileShader(shader))
		{
			OpenGL::getInstance()->deleteShader(shader);
			return 0;
		}
		return shader;
	}
}
