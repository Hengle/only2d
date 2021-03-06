#pragma once

#include <cstdint>
#include <vector>

namespace only2d
{
	class Data
	{
	public:
		explicit Data(size_t size);

		virtual ~Data();

		void assign(const uint8_t *buffer, size_t length = 0, size_t offset = 0);

		uint8_t *getBuffer(size_t offset = 0);

		size_t getSize();

		uint8_t &operator[](size_t index);

	private:
		std::vector<uint8_t> data;
	};
}