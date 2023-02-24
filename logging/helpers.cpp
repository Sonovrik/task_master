#include "helpers.h"

#include <sstream>
#include <chrono>
#include <iomanip>

namespace logging
{

std::string getCurrentTimeAsString()
{
    std::stringstream ss;
    auto now = std::chrono::system_clock::now();
    auto in_time = std::chrono::system_clock::to_time_t(now);

    ss << std::put_time(std::localtime(&in_time), "%Y-%m-%d-%X");
    return ss.str();
}

}
