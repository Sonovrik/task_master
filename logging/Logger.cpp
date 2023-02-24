#include "Logger.h"

namespace logging
{

Logger::Logger(std::string_view path_to_logs)
    : m_LogsDir(path_to_logs)
{}

Logger Logger::getLogger() {
    static const std::string logs_dir = "./";
    static Logger logger(logs_dir);

    return logger;
}

}