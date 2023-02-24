#include "Logger.h"

namespace logging
{

Logger::Logger(LoggerType loggerType, std::string_view logs_dir, std::size_t max_log_size)
{
    switch (loggerType) {
        case LoggerType::DISABLED:
            m_LogStrategy = std::make_unique<DisabledStrategy>();
            break;
        case LoggerType::STDOUT:
            m_LogStrategy = std::make_unique<StdOutStrategy>();
            break;
        case LoggerType::FILE:
            m_LogStrategy = std::make_unique<FileStrategy>(logs_dir, max_log_size);
            break;
    }
}

}