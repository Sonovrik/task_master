#pragma once

#include "Strategy.h"
#include "helpers.h"


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
    std::unique_ptr<ILoggerStrategy> m_LogStrategy;

public:
    Logger(LoggerType loggerType, std::string_view logs_dir, std::size_t max_log_size = GB(1));

};

}
