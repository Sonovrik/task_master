#include "Logger.h"

namespace logging
{

Logger::Logger(LoggerType loggerType, std::string_view logs_dir, std::size_t max_log_size)
    : m_LogStrategy(nullptr)
{
    switch (loggerType) {
        case LoggerType::DISABLED:
            m_LogStrategy = std::make_shared<DisabledStrategy>();
            break;
        case LoggerType::STDOUT:
            m_LogStrategy = std::make_shared<StdOutStrategy>();
            break;
        case LoggerType::FILE:
            m_LogStrategy = std::make_shared<FileStrategy>(logs_dir, max_log_size);
            break;
        default:
            throw std::runtime_error("Invalid strategy for logger");
    }
}

}