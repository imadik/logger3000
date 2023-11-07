#pragma once

#include "InnerLogger.h"
namespace lgr3k
{
    class LogDefault : public LoggerLog
    {
    public:
        LogDefault(std::chrono::time_point<std::chrono::steady_clock> time = std::chrono::steady_clock::now(), 
            source_location sourceLocation = source_location::current())
            : LoggerLog(LogLevel(LEVEL::LEVEL_DEFAULT), sourceLocation, time)
        {}
    };

    class LogFatal : public LoggerLog
    {
    public:
        LogFatal(std::chrono::time_point<std::chrono::steady_clock> time = std::chrono::steady_clock::now(), 
            source_location sourceLocation = source_location::current())
            : LoggerLog(LogLevel(LEVEL::LEVEL_FATAL), sourceLocation, time)
        {}
    };
    class LogError : public LoggerLog
    {
    public:
        LogError(std::chrono::time_point<std::chrono::steady_clock> time = std::chrono::steady_clock::now(), 
            source_location sourceLocation = source_location::current())
            : LoggerLog(LogLevel(LEVEL::LEVEL_ERROR), sourceLocation, time)
        {}
    };

    class LogWarn : public LoggerLog
    {
    public:
        LogWarn(std::chrono::time_point<std::chrono::steady_clock> time = std::chrono::steady_clock::now(), 
            source_location sourceLocation = source_location::current())
            : LoggerLog(LogLevel(LEVEL::LEVEL_WARNING), sourceLocation, time)
        {}
    };

    class LogInfo : public LoggerLog
    {
    public:
        LogInfo(std::chrono::time_point<std::chrono::steady_clock> time = std::chrono::steady_clock::now(), 
            source_location sourceLocation = source_location::current())
            : LoggerLog(LogLevel(LEVEL::LEVEL_INFO), sourceLocation, time)
        {}
    };

    class LogDebug : public LoggerLog
    {
    public:
        LogDebug(std::chrono::time_point<std::chrono::steady_clock> time = std::chrono::steady_clock::now(), 
            source_location sourceLocation = source_location::current())
            : LoggerLog(LogLevel(LEVEL::LEVEL_DEBUG), sourceLocation, time)
        {}
    };

    class LogTrace : public LoggerLog
    {
    public:
        LogTrace(std::chrono::time_point<std::chrono::steady_clock> time = std::chrono::steady_clock::now(), 
            source_location sourceLocation = source_location::current())
            : LoggerLog(LogLevel(LEVEL::LEVEL_TRACE), sourceLocation, time)
        {}
    };

    class LogEnter
    {

    };

    class IInstance;

    void initLogger3000(IInstance* instance)
    {
        initLogger(instance);
    };

    void finishLogger3000()
    {
        finishLogger();
    };

} // namespace lgr3k
