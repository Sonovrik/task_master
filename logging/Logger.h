#pragma once

#include <filesystem>
#include <map>
#include <memory>

namespace logging
{

enum class LoggerType
{
    DISABLED,
    STDOUT,
    FILE
};

class Logger {

private:
    std::filesystem::path m_LogsDir;

private:
    Logger(std::string_view path_to_logs);



public:
    Logger() = delete;
    static Logger getLogger();

public:
    template<typename... TArgs>
    void info(TArgs&&... args) const
    {

    }
};

}
