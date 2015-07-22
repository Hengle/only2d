//
// Created by leafnsand on 2015/6/1.
//

#pragma once

#include <cstdint>

namespace only2d
{
	class Viewport
	{
	public:
		Viewport();

		Viewport(int32_t x, int32_t y, int32_t width, int32_t height);

		Viewport(Viewport &viewport);

		~Viewport();

		bool operator==(const Viewport &viewport) const;

		int32_t x;
		int32_t y;
		int32_t width;
		int32_t height;
	};
}