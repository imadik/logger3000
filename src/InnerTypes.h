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
        LEVEL_DEBUG,
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
            if (mLevel == LEVEL::LEVEL_DEBUG)
                return "DEBUG";
            return "default";
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
