//
// Created by leafnsand on 2015/5/28.
//

#pragma once

#include <iostream>

namespace only2d
{
	class Console
	{
	public:
		template <typename T>
		const Console &operator<<(T t) const
		{
			std::cout << t;
			return *this;
		}

		const Console &operator<<(const std::string &endl) const
		{
			std::cout << endl.c_str();
			if (this == &error && endl == Console::endl)
			{
				exit(1);
			}
			return *this;
		}

		static const std::string endl;

		static const Console debug;
		static const Console log;
		static const Console error;
	};
}