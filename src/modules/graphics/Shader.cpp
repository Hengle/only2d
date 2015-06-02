//
// Created by leafnsand on 2015/6/1.
//

#include "Shader.h"
#include "Graphics.h"

#include "common/Console.h"

namespace only2d
{
    const std::string DefaultShaderAttribute::POSITION = "aPosition";
    const std::string DefaultShaderAttribute::TEXCOORD = "aTexcoord";
    const std::string DefaultShaderAttribute::COLOR = "aColor";
    const std::string DefaultShaderUniform::MVP_MATRIX = "uMVPMatrix";
    const std::string DefaultShaderUniform::ALPHA = "uAlpha";
    const std::string DefaultShaderUniform::TEXTURE = "uTexture";

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
        if (vertex.empty() || fragment.empty())
        {
            Console::error << "[Shader] vertex for fragment shader source is empty!" << Console::endl;
        }
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

    void Shader::setVertexData(const std::vector<Vertex> &vertices)
    {
        setAttributeData(DefaultShaderAttribute::POSITION, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                         &vertices.data()[0].position);
        setAttributeData(DefaultShaderAttribute::TEXCOORD, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                         &vertices.data()[0].texcoord);
        setAttributeData(DefaultShaderAttribute::COLOR, 2, GL_UNSIGNED_BYTE, GL_FALSE, sizeof(Vertex),
                         &vertices.data()[0].color);
    }

    void Shader::setAttributeData(const std::string &name, GLint size, GLenum type, GLboolean normalized,
                                  GLsizei stride, const GLvoid *pointer)
    {
        if (program == 0)
        {
            return;
        }
        GLint position = 0;
        if (attributes.find(name) == attributes.end())
        {
            position = gl->getProgramAttributeLocation(program, name);
            attributes.insert(std::pair<const std::string, GLint>(name, position));
            if (position != -1)
            {
                gl->enableProgrameAttribute(static_cast<GLuint>(position));
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

    void Shader::draw()
    {
        gl->drawArrays(GL_TRIANGLE_STRIP, 0, 4);
    }

    void Shader::load()
    {
        GLuint vertexShader = compile(GL_VERTEX_SHADER, vertex);
        GLuint fragmentShader = compile(GL_FRAGMENT_SHADER, fragment);
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
        GLuint shader = gl->createShader(type);
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