#include "Logger.h"

int main()
{
    logging::Logger logger(logging::LoggerType::FILE, "./", 150);
    logger.info("Hello", "world", "disteny");
}