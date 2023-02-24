#pragma once

#include "Strategy.h"
#include "helpers.h"

#include <filesystem>
#include <map>
#include <memory>
#include <future>

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

private:
    template<typename... TArgs>
    void log(std::string_view level, TArgs&&... args) const
    {
        auto log_func = [&]()
        {
            std::stringstream ss;

            ss << getCurrentTimeAsString() << ' ' << level << ": ";
            ((ss << std::forward<TArgs&&>(args) << ' '), ...);
            ss << '\n';

            m_LogStrategy->write(ss);
        };

        // TODO generate only 1 thread
        auto res = std::async(std::launch::async, log_func);
    }

public:
    Logger(LoggerType loggerType, std::string_view logs_dir, std::size_t max_log_size = GB(1));

    template<typename... TArgs>
    void info(TArgs&&... args) const
    {
        log("[INFO]", args...);
    }

    template<typename... TArgs>
    void warn(TArgs&&... args) const
    {
        log("[WARN]", args...);
    }

    template<typename... TArgs>
    void error(TArgs&&... args) const
    {
        log("[ERROR]", args...);
    }

    template<typename... TArgs>
    void fatal(TArgs&&... args) const
    {
        log("[FATAL]", args...);
    }

    template<typename... TArgs>
    void debug(TArgs&&... args) const
    {
        log("[DEBUG]", args...);
    }

};

}
