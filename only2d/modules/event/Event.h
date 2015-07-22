//
// Created by leafnsand on 2015/5/28.
//

#pragma once

#include "common/Module.h"

namespace only2d
{
	class Event : public Module
	{
	public:
		Event();

		virtual ~Event();

		void pollEvent();
	};
}