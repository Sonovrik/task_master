#pragma once

#include <sstream>
#include <filesystem>
#include <fstream>

namespace logging
{

class ILoggerStrategy
{
public:
    virtual void write(std::stringstream& stream) = 0;
};


class DisabledStrategy : public ILoggerStrategy
{
public:
    void write(std::stringstream& stream) override;
};

class StdOutStrategy : public ILoggerStrategy
{
public:
    void write(std::stringstream& stream) override;
};

class FileStrategy : public ILoggerStrategy
{
private:
    std::ofstream m_File;

    std::filesystem::path m_LogsDir;
    std::filesystem::path m_FilePath;

    const std::size_t m_MaxFileSize;
    std::size_t m_CurrentFileSize;

private:
    bool openFile();

public:
    FileStrategy() = delete;
    FileStrategy(std::string_view logs_dir, std::size_t max_log_size);

    void write(std::stringstream& ss) override;
};

}

