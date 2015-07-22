#include "Shader.h"
#include "Graphics.h"

#include "common/Console.h"
#include "common/Module.h"

namespace only2d
{
	Shader::Shader(std::string &vertex, std::string &fragment) :
		vertex(vertex),
		fragment(fragment),
		program(0)
	{
		auto graphics = Module::getInstance<Graphics>(ModuleType::GRAPHICS);
		if (!graphics)
		{
			Console::error << "[Shader] module graphics not found!" << Console::endl;
		}
		else
		{
			gl = graphics->getOpenGL();
		}
		graphics.reset();
		if (vertex.empty() || fragment.empty())
		{
			Console::error << "[Shader] vertex for fragment shader source is empty!" << Console::endl;
		}
		load();
	}

	Shader::~Shader()
	{
		unload();
		gl.reset();
	}

	bool Shader::match(const std::string &vertex, const std::string &fragment)
	{
		return this->vertex == vertex && this->fragment == fragment;
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
			position = gl->getProgramAttributeLocation(program, name);
			attributes.insert(std::pair<const std::string, GLint>(name, position));
			if (position != -1)
			{
				gl->enableProgramAttribute(static_cast<GLuint>(position));
			}
		}
		else
		{
			position = attributes.at(name);
		}
		if (position != -1)
		{
			gl->setProgramAttributePointer(static_cast<GLuint>(position), size, type, normalized, stride, pointer);
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
			position = gl->getProgramUniformLocation(program, name);
			uniforms.insert(std::pair<const std::string, GLint>(name, position));
		}
		else
		{
			position = uniforms.at(name);
		}
		if (position != -1)
		{
			gl->setProgramIntUniformData(static_cast<GLuint>(position), data);
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
			position = gl->getProgramUniformLocation(program, name);
			uniforms.insert(std::pair<const std::string, GLint>(name, position));
		}
		else
		{
			position = uniforms.at(name);
		}
		if (position != -1)
		{
			gl->setProgramFloatUniformData(static_cast<GLuint>(position), data);
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
			position = gl->getProgramUniformLocation(program, name);
			uniforms.insert(std::pair<const std::string, GLint>(name, position));
		}
		else
		{
			position = uniforms.at(name);
		}
		if (position != -1)
		{
			gl->setProgramMatrixUniformData(static_cast<GLuint>(position), matrix);
		}
	}

    void Shader::drawArrays(GLenum mode, GLint first, GLsizei count)
    {
		gl->drawArrays(mode, first, count);
    }

    void Shader::drawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid *buffer)
    {
		gl->drawElements(mode, count, type, buffer);
    }

    void Shader::attach()
	{
		if (program != 0)
		{
			gl->useProgram(program);
		}
	}

	void Shader::detach()
	{
		gl->useProgram(0);
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
		program = gl->createProgram();
		if (program == 0)
		{
			Console::error << "[Shader] create program error." << Console::endl;
		}
		gl->attachShader(program, vertexShader);
		gl->attachShader(program, fragmentShader);
		if (!gl->linkProgram(program))
		{
			gl->deleteProgram(program);
			program = 0;
		}
		gl->deleteShader(vertexShader);
		gl->deleteShader(fragmentShader);
	}

	void Shader::unload()
	{
		if (program != 0)
		{
			gl->deleteProgram(program);
		}
	}

	GLuint Shader::compile(GLenum type, const std::string &source)
	{
		auto shader = gl->createShader(type);
		if (shader == 0)
		{
			Console::error << "[Shader] create " << ((type == GL_VERTEX_SHADER) ? "vertex" : "fragment")
				<< " shader fail." << Console::endl;
		}
		gl->setShaderSource(shader, source);
		if (!gl->compileShader(shader))
		{
			gl->deleteShader(shader);
			return 0;
		}
		return shader;
	}
}
