//
// Created by leafnsand on 2015/5/29.
//

#include "FileSystem.h"
#include "common/Console.h"

#include <SDL2/SDL_filesystem.h>
#include <sstream>

namespace only2d
{
    ModuleType FileSystem::getType() const
    {
        return ModuleType::FILESYSTEM;
    }

    const char *FileSystem::getName() const
    {
        return "FileSystem";
    }

    FileSystem::FileSystem()
    {
        registerModule(this);
    }

    FileSystem::~FileSystem()
    {
        deregisterModule(this);
    }

    void FileSystem::init(const char *path)
    {
        sourceDir = SDL_GetBasePath();
        if (sourceDir.empty())
        {
            Console::error << "initialize file system fail." << Console::endl;
        }
        separator = sourceDir.back();
        if (path && path[0] != '\0')
        {
            sourceDir = path;
            sourceDir.append(separator);
        }
        std::string config = sourceDir + "setting";
        std::fstream file(config);
        if (!file.good())
        {
            Console::error << "no file named 'setting' was found in the source path.\n"
            << "usage: only2d.exe {souce_path}" << Console::endl;
        }
        std::string company = "leafnsand";
        std::string name = "only2d";
        while (!file.eof())
        {
            std::string line;
            std::getline(file, line);
            auto separatorIndex = line.find(":");
            auto setting = std::pair<std::string, std::string>(line.substr(0, separatorIndex),
                                                               line.substr(separatorIndex + 1,
                                                                           line.size() - separatorIndex - 1));
            if (setting.first == "company")
            {
                company = setting.second;
            }
            else if (setting.first == "name")
            {
                name = setting.second;
            }
            else
            {
                settings.push_back(setting);
            }
        }
        appdataDir = SDL_GetPrefPath(company.c_str(), name.c_str());
    }

    std::shared_ptr<File> FileSystem::createFile(const std::string &filename)
    {
        return std::shared_ptr<File>(new File(filename, FileMode::WRITE));
    }

    std::shared_ptr<File> FileSystem::createBinaryFile(const std::string &filename)
    {
        return std::shared_ptr<File>(new File(filename, FileMode::BINARY_WRITE));
    }

    std::shared_ptr<File> FileSystem::appendFile(const std::string &filename)
    {
        return std::shared_ptr<File>(new File(filename, FileMode::APPEND));
    }

    std::shared_ptr<File> FileSystem::appendBinaryFile(const std::string &filename)
    {
        return std::shared_ptr<File>(new File(filename, FileMode::BINARY_APPEND));
    }

    std::shared_ptr<File> FileSystem::openFile(const std::string &filename)
    {
        return std::shared_ptr<File>(new File(filename, FileMode::READ));
    }

    std::shared_ptr<File> FileSystem::openBinaryFile(const std::string &filename)
    {
        return std::shared_ptr<File>(new File(filename, FileMode::BINARY_READ));
    }

    std::shared_ptr<FileData> FileSystem::newFileData(size_t size, const std::string &filename)
    {
        return std::shared_ptr<FileData>(new FileData(size, filename));
    }

    const std::vector<std::pair<std::string, std::string>> &FileSystem::getSettings() const
    {
        return settings;
    }

    const std::string &FileSystem::getAppdataDir() const
    {
        return appdataDir;
    }

    const std::string &FileSystem::getSourceDir() const
    {
        return sourceDir;
    }
}