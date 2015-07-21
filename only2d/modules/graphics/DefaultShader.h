//
// Created by leafnsand on 2015/7/21.
//

#ifndef ONLY2D_DEFAULTSHADER_H
#define ONLY2D_DEFAULTSHADER_H

#include "Shader.h"

static const std::string attribute_POSITION = "aPosition";
static const std::string attribute_TEXCOORD = "aTexcoord";
static const std::string uniform_PROJECTION_MATRIX = "uProjectionMatrix";
static const std::string uniform_MVP_MATRIX = "uMVPMatrix";
static const std::string uniform_COLOR = "uColor";
static const std::string uniform_ALPHA = "uAlpha";

static std::string textureVertexSource = "#ifndef GL_ES\n"
"#define lowp\n"
"#define mediump\n"
"#define highp\n"
"#endif\n"
"#ifdef GL_ES\n"
"precision mediump float;\n"
"#endif\n"
"attribute vec4 aPosition;\n"
"attribute vec2 aTexcoord;\n"
"uniform mat4 uMVPMatrix;\n"
"uniform mat4 uProjectionMatrix;\n"
"varying vec2 vTexcoord;\n"
"void main() {\n"
"\tvTexcoord = aTexcoord;\n"
"\tgl_Position = uProjectionMatrix * uMVPMatrix * aPosition;\n"
"}";
static std::string textureFragmentSource = "#ifndef GL_ES\n"
"#define lowp\n"
"#define mediump\n"
"#define highp\n"
"#endif\n"
"#ifdef GL_ES\n"
"precision mediump float;\n"
"#endif\n"
"varying vec2 vTexcoord;\n"
"uniform vec4 uColor;\n"
"uniform float uAlpha;\n"
"uniform sampler2D uTexture;\n"
"void main() {\n"
"\tvec4 color = uColor;\n"
"\tcolor.a = color.a * uAlpha;\n"
"\tgl_FragColor = texture2D(uTexture, vTexcoord) * color;\n"
"}";
static std::string noTextureVertexSource = "#ifndef GL_ES\n"
"#define lowp\n"
"#define mediump\n"
"#define highp\n"
"#endif\n"
"#ifdef GL_ES\n"
"precision mediump float;\n"
"#endif\n"
"attribute vec4 aPosition;\n"
"uniform mat4 uMVPMatrix;\n"
"uniform mat4 uProjectionMatrix;\n"
"void main() {\n"
"\tgl_Position = uProjectionMatrix * uMVPMatrix * aPosition;\n"
"}";
static std::string noTextureFragmentSource = "#ifndef GL_ES\n"
"#define lowp\n"
"#define mediump\n"
"#define highp\n"
"#endif\n"
"#ifdef GL_ES\n"
"precision mediump float;\n"
"#endif\n"
"uniform vec4 uColor;\n"
"uniform float uAlpha;\n"
"void main() {\n"
"\tvec4 color = uColor;\n"
"\tcolor.a = color.a * uAlpha;\n"
"\tgl_FragColor = color;\n"
"}";

namespace only2d
{
	enum class ShaderType : int32_t
	{
		QuadShader,
		ImageShader,
		MaxCount
	};

    class DefaultShader
    {
    public:
	    static std::shared_ptr<Shader> getShader(ShaderType type);

    private:
	    static std::shared_ptr<Shader> cache[static_cast<int32_t>(ShaderType::MaxCount)];
    };
}

#endif //ONLY2D_DEFAULTSHADER_H
