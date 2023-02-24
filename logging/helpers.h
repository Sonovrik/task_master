#pragma once

#include <string>

namespace logging
{

#define B(x)    ((size_t) (x))
#define KB(x)   ((size_t) (x) << 10)
#define MB(x)   ((size_t) (x) << 20)
#define GB(x)   ((size_t) (x) << 30)

std::string getCurrentTimeAsString();

}
