//
// Created by leafnsand on 2015/5/28.
//

#ifndef ONLY2D_EVENT_H
#define ONLY2D_EVENT_H

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

#endif //ONLY2D_EVENT_H

