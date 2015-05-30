//
// Created by leafnsand on 2015/5/29.
//

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

    const std::string FileData::getExtention() const
    {
        auto index = filename.rfind('.');
        if (index != std::string::npos)
        {
            return filename.substr(index + 1);
        }
        return nullptr;
    }
}