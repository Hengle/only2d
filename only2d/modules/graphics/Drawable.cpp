#include "Drawable.h"
#include "Graphics.h"

#include "common/Console.h"
#include "common/Module.h"

namespace only2d
{
	Drawable::Drawable() :
		x(0.0f),
		y(0.0f),
		rotation(0.0f),
		scaleX(1.0f),
		scaleY(1.0f),
		offsetX(0.0f),
		offsetY(0.0f),
		skewX(0.0f),
		skewY(0.0f),
		alpha(1.0f),
		color(255, 255, 255, 255),
		visible(true),
		update(true),
		mode(BlendMode::ALPHA)
	{
		auto graphics = Module::getInstance<Graphics>(ModuleType::GRAPHICS);
		if (!graphics)
		{
			Console::error << "[Drawable] module graphics not found!" << Console::endl;
		}
		else
		{
			gl = graphics->getOpenGL();
		}
		graphics.reset();
	}

	Drawable::~Drawable()
	{
	}

	void Drawable::draw()
	{
		gl->setCurrentBlendMode(mode);
	}

	float Drawable::getX() const
	{
		return x;
	}

	void Drawable::setX(float x)
	{
		update = true;
		this->x = x;
	}

	float Drawable::getY() const
	{
		return y;
	}

	void Drawable::setY(float y)
	{
		update = true;
		this->y = y;
	}

	float Drawable::getRotation() const
	{
		return rotation;
	}

	void Drawable::setRotation(float rotation)
	{
		update = true;
		this->rotation = rotation;
	}

	float Drawable::getScaleX() const
	{
		return scaleX;
	}

	void Drawable::setScaleX(float scaleX)
	{
		update = true;
		this->scaleX = scaleX;
	}

	float Drawable::getScaleY() const
	{
		return scaleY;
	}

	void Drawable::setScaleY(float scaleY)
	{
		update = true;
		this->scaleY = scaleY;
	}

	float Drawable::getOffsetX() const
	{
		return offsetX;
	}

	void Drawable::setOffsetX(float offsetX)
	{
		update = true;
		this->offsetX = offsetX;
	}

	float Drawable::getOffsetY() const
	{
		return offsetY;
	}

	void Drawable::setOffsetY(float offsetY)
	{
		update = true;
		this->offsetY = offsetY;
	}

	float Drawable::getSkewX() const
	{
		return skewX;
	}

	void Drawable::setSkewX(float skewX)
	{
		update = true;
		this->skewX = skewX;
	}

	float Drawable::getSkewY() const
	{
		return skewY;
	}

	void Drawable::setSkewY(float skewY)
	{
		update = true;
		this->skewY = skewY;
	}

	float Drawable::getAlpha() const
	{
		return alpha;
	}

	void Drawable::setAlpha(float alpha)
	{
		this->alpha = alpha;
	}

	bool Drawable::isVisible() const
	{
		return visible;
	}

	void Drawable::setVisible(bool visible)
	{
		this->visible = visible;
	}

	const Matrix &Drawable::getMatrix()
	{
		if (update)
		{
			matrix.setTransformation(x, y, rotation, scaleX, scaleY, offsetX, offsetY, skewX, skewY);
			update = false;
		}
		return matrix;
	}

	const Color &Drawable::getColor() const
	{
		return color;
	}

	void Drawable::setColor(const Color &color)
	{
		this->color = color;
	}

	const BlendMode &Drawable::getBlendMode() const
	{
		return mode;
	}

	void Drawable::setBlendMode(const BlendMode &mode)
	{
		this->mode = mode;
	}
}
