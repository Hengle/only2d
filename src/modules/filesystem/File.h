//
// Created by leafnsand on 2015/5/29.
//

#ifndef ONLY2D_FILE_H
#define ONLY2D_FILE_H

#include "FileData.h"

#include <string>
#include <fstream>
#include <memory>

namespace only2d
{
    enum class FileMode
    {
        READ,
        WRITE,
        APPEND,
        BINARY_READ,
        BINARY_WRITE,
        BINARY_APPEND
    };

    enum class FileReadMode
    {
        BLOCK,
        ALL
    };

    class File
    {
    public:
        File(const std::string &filename, FileMode mode);

        virtual ~File();

        bool good();

        size_t getSize();

        std::shared_ptr<FileData> read(FileReadMode readMode, size_t size = 0);

        bool read(std::string &line);

        bool write(std::shared_ptr<Data> data);

        bool write(const std::string &line);

        bool flush();

        bool eof();

        size_t tell();

        size_t available();

        bool seek(size_t pos);

    private:
        bool isRead();

        bool isBinary();

    private:
        std::string filename;
        FileMode mode;
        std::fstream handle;
    };
}

#endif //ONLY2D_FILE_H
