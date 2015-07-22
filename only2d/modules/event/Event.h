#pragma once

namespace only2d
{
	class Event
	{
	public:
		Event();

		virtual ~Event();

		void pollEvent();
	};
}