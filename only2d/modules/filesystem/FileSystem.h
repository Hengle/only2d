#pragma once

#include "File.h"
#include "FileData.h"

#include <vector>
#include <utility>
#include <memory>

namespace only2d
{
	class FileSystem
	{
	public:
		FileSystem();

		virtual ~FileSystem();

		void init(const char *path);

		std::shared_ptr<File> createFile(const std::string &filename);

		std::shared_ptr<File> createBinaryFile(const std::string &filename);

		std::shared_ptr<File> appendFile(const std::string &filename);

		std::shared_ptr<File> appendBinaryFile(const std::string &filename);

		std::shared_ptr<File> openFile(const std::string &filename);

		std::shared_ptr<File> openBinaryFile(const std::string &filename);

		std::shared_ptr<FileData> newFileData(size_t size, const std::string &filename);

		const std::vector<std::pair<std::string, std::string>> &getSettings() const;

		const std::string &getAppdataDir() const;

		const std::string &getSourceDir() const;

		const std::string &getSeparator() const;

	private:
		std::string separator;
		std::string appdataDir;
		std::string sourceDir;
		std::vector<std::pair<std::string, std::string>> settings;
	};
}