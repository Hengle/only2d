//
// Created by leafnsand on 2015/5/29.
//

#include "File.h"

#include "common/Console.h"

#include <algorithm>

namespace only2d
{
    File::File(const std::string &filename, FileMode mode) :
            filename(filename),
            mode(mode)
    {
        if (mode == FileMode::READ)
        {
            handle.open(filename, std::ios::in);
        }
        else if (mode == FileMode::WRITE)
        {
            handle.open(filename, std::ios::out);
        }
        else if (mode == FileMode::APPEND)
        {
            handle.open(filename, std::ios::app);
        }
        if (mode == FileMode::BINARY_READ)
        {
            handle.open(filename, std::ios::in | std::ios::binary);
        }
        else if (mode == FileMode::BINARY_WRITE)
        {
            handle.open(filename, std::ios::out | std::ios::binary);
        }
        else if (mode == FileMode::BINARY_APPEND)
        {
            handle.open(filename, std::ios::app | std::ios::binary);
        }
        if (!good())
        {
            Console::log << "open file " << filename << "fail." << Console::endl;
        }
    }

    File::~File()
    {
        handle.flush();
        handle.close();
    }

    bool File::good()
    {
        return handle.good();
    }

    size_t File::getSize()
    {
        if (good() && isRead())
        {
            auto pos = handle.tellg();
            handle.seekg(0, std::ios::beg);
            auto begin = handle.tellg();
            handle.seekg(0, std::ios::end);
            auto end = handle.tellg();
            handle.seekg(pos);
            return static_cast<size_t>(end - begin);
        }
        return 0;
    }

    std::shared_ptr<FileData> File::read(FileReadMode readMode, size_t size)
    {
        std::shared_ptr<FileData> out = nullptr;
        if (good() && isRead() && isBinary())
        {
            if (readMode == FileReadMode::BLOCK)
            {
                size = std::min(size, available());
            }
            else if (readMode == FileReadMode::ALL)
            {
                size = available();
            }
            out = std::shared_ptr<FileData>(new FileData(size, filename));
            handle.read(out->getBuffer(), size);
        }
        return out;
    }

    bool File::read(std::string &line)
    {
        if (good() && isRead() && !isBinary() && !eof())
        {
            std::getline(handle, line);
            return true;
        }
        return false;
    }

    bool File::write(std::shared_ptr<Data> data)
    {
        if (good() && !isRead() && isBinary())
        {
            handle.write(data->getBuffer(), data->getSize());
        }
        return false;
    }

    bool File::write(const std::string &line)
    {
        if (good() && !isRead() && !isBinary())
        {
            handle << line << std::endl;
        }
        return false;
    }

    bool File::flush()
    {
        if (good())
        {
            handle.flush();
            return true;
        }
        return false;
    }

    bool File::eof()
    {
        return !good() || handle.eof();
    }

    size_t File::tell()
    {
        if (good())
        {
            if (mode == FileMode::READ)
            {
                return static_cast<size_t>(handle.tellg());
            }
            else
            {
                return static_cast<size_t>(handle.tellp());
            }
        }
        return 0;
    }

    size_t File::available()
    {
        return getSize() - tell();
    }

    bool File::seek(size_t pos)
    {
        if (good())
        {
            if (mode == FileMode::READ)
            {
                handle.seekg(pos);
            }
            else
            {
                handle.seekp(pos);
            }
            return true;
        }
        return false;
    }

    bool File::isRead()
    {
        return mode == FileMode::READ || mode == FileMode::BINARY_READ;
    }

    bool File::isBinary()
    {
        return mode == FileMode::BINARY_READ || mode == FileMode::BINARY_WRITE || mode == FileMode::BINARY_APPEND;
    }
}
