#pragma once

#include "Interfaces/IInstance.h"
#include "InnerTypes.h"
#include "CommandsQueue.h"
#include "SortedCircularBuffer.h"
#include <vector>
#include <memory>

namespace lgr3k
{
    class IFilter;
    class IFormatter;
    class ISink;
    class LoggerInstance : public IInstance
    {
    public:
        LoggerInstance(std::size_t bufferSize,
            std::shared_ptr<IFilter> filter,
            std::shared_ptr<IFormatter> formatter,
            std::shared_ptr<ISink> sink);
 
        void saveLog(MessageWithInfo msg) override;
        void addSink(std::shared_ptr<ISink> sink) override;

    private:
        void addSinkImpl(std::shared_ptr<ISink> sink);
        void popMsgImpl(MessageWithInfo msg);
        void saveMsgImpl(MessageWithInfo msg);
        void formatMsgImpl(std::string msg);
        void pushToAllSinksImpl(std::string msg);

        std::vector<std::shared_ptr<ISink>> mSinkVector;
        std::shared_ptr<IFilter> mFilter;
        std::shared_ptr<IFormatter> mFormatter;
        SortedCircularBuffer<MessageWithInfo> mSortedCircularBuffer; //
        CommandsQueue mCommandsQueue;

    };
}
