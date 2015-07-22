#include "Viewport.h"

namespace only2d
{
	Viewport::Viewport() :
		x(0),
		y(0),
		width(0),
		height(0)
	{
	}

	Viewport::Viewport(int32_t x, int32_t y, int32_t width, int32_t height) :
		x(x),
		y(y),
		width(width),
		height(height)
	{
	}

	Viewport::Viewport(Viewport &viewport) :
		x(viewport.x),
		y(viewport.y),
		width(viewport.width),
		height(viewport.height)
	{
	}

	Viewport::~Viewport()
	{
	}

	bool Viewport::operator==(const Viewport &viewport) const
	{
		return x == viewport.x && y == viewport.y && width == viewport.width && height == viewport.height;
	}
}
