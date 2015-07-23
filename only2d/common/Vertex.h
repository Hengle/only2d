#pragma once

#include "Color.h"
#include "Vector.h"

namespace only2d
{
	class Vertex
	{
	public:
		Vector position;
		Vector texcoord;
		Color color;
	};
}