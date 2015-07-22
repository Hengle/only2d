#pragma once

#include "common/Data.h"

#include <string>

namespace only2d
{
	class FileData : public Data
	{
	public:
		FileData(size_t size, const std::string &filename);

		virtual ~FileData();

		const std::string &getFilename() const;

		std::string getExtention();

	private:
		std::string filename;
	};
}