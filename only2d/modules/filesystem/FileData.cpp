#include "FileData.h"

namespace only2d
{
	FileData::FileData(size_t size, const std::string &filename) :
		Data(size),
		filename(filename)
	{
	}

	FileData::~FileData()
	{
	}

	const std::string &FileData::getFilename() const
	{
		return filename;
	}

	std::string FileData::getExtention()
	{
		auto index = filename.rfind('.');
		if (index != std::string::npos)
		{
			return filename.substr(index + 1);
		}
		return nullptr;
	}
}
