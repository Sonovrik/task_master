#include "Strategy.h"

#include <iostream>

#include "helpers.h"

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
    if (!m_File.is_open() || !std::filesystem::exists(m_FilePath))
    {
        m_File.close();
        m_FilePath = m_LogsDir.string() + "/" + getCurrentTimeAsString();
        m_File.open(m_FilePath, std::ios_base::out | std::ios_base::app);
        if (!m_File.is_open())
        {
            return false;
        }
        m_CurrentFileSize = 0;
    }

    return true;
}

void FileStrategy::write(std::stringstream &ss)
{
    const std::string& message = ss.str();

    if (message.size() > m_MaxFileSize)
    {
        std::cerr << "Error message size: too big" << std::endl;
        return;
    }

    if (message.size() + m_CurrentFileSize > m_MaxFileSize)
    {
        // create new file

        m_File.close();
        if (!openFile())
        {
            // do something
            std::cerr << "Error while creating log file" << std::endl;
            return;
        }
    }

    m_File << message;
    m_File.flush();
    m_CurrentFileSize += message.size();
}

}