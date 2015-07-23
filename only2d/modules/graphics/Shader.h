#pragma once

#include "OpenGL.h"

#include "common/Color.h"
#include "common/Vertex.h"

#include <map>
#include <string>

namespace only2d
{
	class Shader
	{
	public:
		Shader(const std::string &vertex, const std::string &fragment);

		virtual ~Shader();

		bool match(const std::string &vertex, const std::string &fragment);

		void setBlendMode(const BlendMode &mode);

		void setAttributeData(const std::string &name, GLint size, GLenum type, GLboolean normalized, GLsizei stride,
		                      const GLvoid *pointer);

		void setUniformIntData(const std::string &name, const std::vector<int32_t> &data);

		void setUniformFloatData(const std::string &name, const std::vector<float> &data);

		void setUniformMatrixData(const std::string &name, const Matrix &matrix);

		void drawArrays(GLenum mode, GLint first, GLsizei count);

		void drawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid *buffer);

		void attach();

		void detach();

	private:
		void load();

		void unload();

		GLuint compile(GLenum type, const std::string &source);

	protected:
		const std::string vertex;
		const std::string fragment;
		GLuint program;
		std::map<const std::string, GLint> attributes;
		std::map<const std::string, GLint> uniforms;
	};
}