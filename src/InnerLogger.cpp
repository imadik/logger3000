#include "InnerLogger.h"
#include "LoggerInstance.h"
#include <mutex>

namespace
{
    lgr3k::IInstance* loggerMainInstance = nullptr;
    std::mutex initMutex;
}

namespace lgr3k
{

    LoggerLog::~LoggerLog()
    {
        if (loggerMainInstance != nullptr)
        {
            mMsg.text = std::move(mStream.str());
            loggerMainInstance->saveLog(mMsg);
        }
    };

   
    void initLogger(IInstance* instance)
    {
        std::lock_guard<std::mutex> lock(initMutex);
        if (loggerMainInstance == nullptr)
        {
            loggerMainInstance = instance;  
        }
    }

    void finishLogger()
    {
        loggerMainInstance = nullptr;
    }
}
