#include "Logger.h"

#include <sstream>
#include <chrono>

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

std::string Logger::getCurrentTimeAsString()
{
    std::stringstream ss;
    auto now = std::chrono::system_clock::now();
    auto in_time = std::chrono::system_clock::to_time_t(now);

    ss << std::put_time(std::localtime(&in_time), "%Y-%m-%d_%X");
    return ss.str();
}

}