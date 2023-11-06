#pragma once

#include "Interfaces/IInstance.h"
#include "InnerTypes.h"
#include "CommandsQueue.h"
#include "SortedCircularBuffer.h"
#include <mutex>
#include <vector>

namespace lgr3k
{
    class LoggerInstance : public IInstance
    {
    public:
        LoggerInstance(std::size_t bufferSize);
 
        void saveLog(MessageWithInfo msg) override;
        void addSink(std::unique_ptr<ISink> sink) override;
    private:
        void popCallback(MessageWithInfo msg);
        void saveMsgCallback(MessageWithInfo msg);
        void formatedMsgCallback(std::string msg);
        void pushToAllSinksCallback(std::string msg);

        std::mutex mMutex;
        CommandsQueue mCommandsQueue;
        SortedCircularBuffer<MessageWithInfo> mSortedCircularBuffer; //
        std::vector<std::unique_ptr<ISink>> mSinkVector;
    };
}
