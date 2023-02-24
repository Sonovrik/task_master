#include "Strategy.h"

#include <iostream>

namespace logging
{

void DisabledStrategy::write(std::stringstream &stream)
{

}

void StdOutStrategy::write(std::stringstream &stream)
{
    std::cout << stream.str() << std::endl;
}

FileStrategy::FileStrategy(std::string_view logs_dir, std::size_t max_log_size)
    : m_LogsDir(logs_dir)
    , m_MaxFileSize(max_log_size)
{

}

bool FileStrategy::openFile()
{
    stati
    if (m_File.is_open() && std::filesystem::exists(m_FilePath))
    {
        return true;
    }

    m_File.close();
    m_FilePath = m_LogsDir.string() + "/" +
}

void FileStrategy::write(std::stringstream &ss)
{
    const std::string& message = ss.str();

    if (message.size() > m_MaxFileSize)
    {
        // cannot write. Message size too big
        return;
    }

    if (message.size() + m_CurrentFileSize > m_MaxFileSize)
    {

    }
}

}