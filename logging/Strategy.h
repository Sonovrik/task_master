#pragma once

#include <sstream>
#include <filesystem>

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
    std::filesystem::path m_LogsDir;
    std::filesystem::path m_FileName;

    const std::size_t m_MaxFileSize;
    std::size_t m_CurrentFileSize;

public:
    FileStrategy() = delete;
    FileStrategy(std::string_view logs_dir, std::size_t max_log_size);

    void write(std::stringstream& stream) override;
};

}

