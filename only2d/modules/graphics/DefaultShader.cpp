//
// Created by leafnsand on 2015/7/21.
//

#include "DefaultShader.h"
#include "Graphics.h"

namespace only2d
{
    std::shared_ptr<Shader> DefaultShader::cache[] = {};

    std::shared_ptr<Shader> DefaultShader::getShader(ShaderType type)
    {
	    auto index = static_cast<int32_t>(type);
		if (cache[index] == nullptr)
		{
			auto graphics = Module::getInstance<Graphics>(ModuleType::GRAPHICS);
			switch (type)
			{
				case ShaderType::QuadShader:
					cache[index] = std::make_shared<Shader>(noTextureVertexSource, noTextureFragmentSource);
					break;
				case ShaderType::ImageShader:
					cache[index] = std::make_shared<Shader>(textureVertexSource, textureFragmentSource);
					break;
				default:
					break;
			}
			cache[index]->attach();
			cache[index]->setUniformMatrixData(uniform_PROJECTION_MATRIX, graphics->getProjectionMatrix());
			cache[index]->detach();
			graphics.reset();
		}
	    return cache[index];
    }
}