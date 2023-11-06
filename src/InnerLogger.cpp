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
        #ifdef DEBUG
        std::cout<<__PRETTY_FUNCTION__
                <<mThreadId<<" " 
                <<mTime.time_since_epoch().count()<<" "
                <<mLogLevel.getStr()<<" "
                <<mSourceLocation.file_name()<<" "
                <<mSourceLocation.line()<<" "
                <<mSourceLocation.function_name()<<" "
                <<mStream.str()<<std::endl;
        #endif
        if (loggerMainInstance != nullptr)
        {
            loggerMainInstance->saveLog({std::move(mLogLevel), std::move(mTime), std::move(mThreadId), 
                std::move(mSourceLocation), std::move(mStream.str())});
        }
    };

   
    void initLogger(LoggerInstance* instance)
    {
        std::lock_guard<std::mutex> lock(initMutex);
        if (loggerMainInstance == nullptr)
        {
            // TODO change owner
            loggerMainInstance = instance;  
        }
    }

    void finishLogger()
    {
        loggerMainInstance = nullptr;
    }

    // void saveLog(MessageWithInfo msg)
    // {
    //     if (loggerMainInstance != nullptr)
    //     {
    //         loggerMainInstance->saveLog(msg);
    //     }
    // }


}
