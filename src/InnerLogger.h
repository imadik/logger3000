#pragma once

#include "InnerTypes.h"
#include "CommandsQueue.h"
#include <chrono>
#include <ostream>
#include <sstream>
#include <thread>
#include <mutex>
#include <queue>
#ifdef DEBUG
#include <iostream>
#include <iomanip>

#endif
#include "source_location/source_location.hpp"

namespace lgr3k
{
    


    
    class LoggerLog
    {
    public:
        LoggerLog(LogLevel logLevel, source_location sourceLocation, std::chrono::time_point<std::chrono::steady_clock> time)
            : mSourceLocation(sourceLocation)
            , mLogLevel(logLevel)
            , mTime(time)
        {
            mThreadId = std::this_thread::get_id();
        };
        virtual ~LoggerLog();

        #define LGR_STREAM(MSG_TYPE)\
        inline LoggerLog& operator<<(MSG_TYPE msg) {\
        this->stream() << msg;\
        this->stream() << " ";\
        return *this;\
        }\

        inline LoggerLog& operator<<(const std::string& msg)
        {
            return operator<<(msg.c_str());
        }
        LGR_STREAM(char)
        LGR_STREAM(bool)
        LGR_STREAM(signed short)
        LGR_STREAM(unsigned short)
        LGR_STREAM(signed int)
        LGR_STREAM(unsigned int)
        LGR_STREAM(signed long)
        LGR_STREAM(unsigned long)
        LGR_STREAM(float)
        LGR_STREAM(double)
        LGR_STREAM(char*)
        LGR_STREAM(const char*)
        LGR_STREAM(const void*)
        LGR_STREAM(long double)
        inline LoggerLog& operator<<(const std::wstring& msg)
        {
            return operator<<(msg.c_str());
        }
        LoggerLog& operator<<(const wchar_t* msg);

    private:
        std::ostringstream &stream() 
        {
            return mStream;
        }

        std::ostringstream mStream;
        source_location mSourceLocation;
        LogLevel mLogLevel;
        std::chrono::time_point<std::chrono::steady_clock> mTime;
        std::thread::id mThreadId;
    };


    class LoggerInstance;

    void initLogger(LoggerInstance* instance);
    void finishLogger();
    void saveLog(MessageWithInfo msg);
}
