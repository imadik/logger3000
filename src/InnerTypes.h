#pragma once

#include <chrono>
#include <string>
#include <thread>
#include "source_location/source_location.hpp"

namespace lgr3k
{
    enum class LEVEL
    {
        LEVEL_DEFAULT,
        LEVEL_FATAL,
        LEVEL_ERROR,
        LEVEL_WARNING,
        LEVEL_INFO,
        LEVEL_DEBUG,
        LEVEL_TRACE,
    };

    class LogLevel
    {
    public:
        LogLevel()
            : mLevel(LEVEL::LEVEL_DEFAULT)
        {}

        LogLevel(LEVEL level)
            : mLevel(level)
        {}

        std::string getStr() const
        {
            std::string result;
            switch (mLevel)
            {
            case LEVEL::LEVEL_DEFAULT:
                result = "DEFAULT";
                break;
            case LEVEL::LEVEL_FATAL:
                result = "FATAL";
                break;
            case LEVEL::LEVEL_ERROR:
                result = "ERROR";
                break;
            case LEVEL::LEVEL_WARNING:
                result = "WARNING";
                break;
            case LEVEL::LEVEL_INFO:
                result = "INFO";
                break;
            case LEVEL::LEVEL_DEBUG:
                result = "DEBUG";
                break;
            case LEVEL::LEVEL_TRACE:
                result = "TRACE";
                break;
            default:
                result = "DEFAULT";
                break;
            }
            return result;
        }

        LEVEL getLevel() const
        {
            return mLevel;
        }
    private:
        LEVEL mLevel;
    };

    struct MessageWithInfo
    {
        // TODO add module
        LogLevel logLevel;
        std::chrono::time_point<std::chrono::steady_clock> time;
        std::thread::id threadId;
        source_location sourceLocation;
        std::string text;
    };

    inline bool operator==(const MessageWithInfo& left, const MessageWithInfo& right)
    {
        return left.time == right.time;
    }

    inline bool operator!=(const MessageWithInfo& left, const MessageWithInfo& right)
    {
        return left.time != right.time;
    }

    inline bool operator>(const MessageWithInfo& left, const MessageWithInfo& right)
    {
        return left.time > right.time;
    }

    inline bool operator<(const MessageWithInfo& left, const MessageWithInfo& right)
    {
        return left.time < right.time;
    }

    inline bool operator>=(const MessageWithInfo& left, const MessageWithInfo& right)
    {
        return left.time >= right.time;
    }
} // namespace lgr3k
