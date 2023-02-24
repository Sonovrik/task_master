#pragma once

#include <sstream>
#include <filesystem>

namespace logging
{

class ILoggerStrategy
{
public:
    virtual void write(std::stringstream& stream) = 0;
};


class DisabledStrategy : public ILoggerStrategy
{
public:
    void write(std::stringstream& stream) override;
};

class StdOutStrategy : public ILoggerStrategy
{
public:
    void write(std::stringstream& stream) override;
};

class FileStrategy : public ILoggerStrategy
{
private:



public:
    void write(std::stringstream& stream) override;
};

}

