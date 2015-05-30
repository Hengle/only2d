//
// Created by leafnsand on 2015/5/29.
//

#ifndef ONLY2D_FILEDATA_H
#define ONLY2D_FILEDATA_H

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

        const std::string getExtention() const;

    private:
        std::string filename;
    };
}

#endif //ONLY2D_FILEDATA_H
