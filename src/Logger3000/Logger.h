#pragma once

// #include <ostream>
// #include <sstream>
// #ifdef DEBUG
// #include <iostream>
// #endif
// #include "source_location/source_location.hpp"

#include "InnerLogger.h"
namespace lgr3k
{
    class LogDebug : public LoggerLog
    {
    public:
        LogDebug(std::chrono::time_point<std::chrono::steady_clock> time = std::chrono::steady_clock::now(), source_location sourceLocation = source_location::current())
            : LoggerLog(LogLevel(LEVEL::LEVEL_DEBUG), sourceLocation, time)
        {}
    private:
    };

    class LogEnter
    {

    };

    class LoggerInstance;
    void initLogger3000(LoggerInstance* instance)
    {
        initLogger(instance);
    };
    
    void finishLogger3000()
    {
        finishLogger();
    };

} // namespace lgr3k
