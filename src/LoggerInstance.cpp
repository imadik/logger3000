#include "LoggerInstance.h"
#include "SaveMessageCommand.h"
#include "FormatMessageCommand.h"
#include "SinkMessageCommand.h"
#include <mutex>
#include <functional>

#ifdef DEBUG
#include <iostream>
#include <iomanip>

#endif

namespace lgr3k
{

    LoggerInstance::LoggerInstance(std::size_t bufferSize)
        : mSortedCircularBuffer(bufferSize, std::bind(&LoggerInstance::popCallback, this, std::placeholders::_1))
    {

    }

    void LoggerInstance::saveLog(MessageWithInfo msg)
    {
        #ifdef DEBUG
        std::cout<<__PRETTY_FUNCTION__
                <<msg.threadId<<" "
                <<msg.time.time_since_epoch().count()<<" "
                <<msg.logLevel.getStr()<<" "
                <<msg.sourceLocation.file_name()<<" "
                <<msg.sourceLocation.line()<<" "
                <<msg.sourceLocation.function_name()<<" "
                <<msg.text<<std::endl;
        #endif
        mCommandsQueue.addCommand(std::unique_ptr<SaveMessageCommand>(new SaveMessageCommand(std::move(msg), 
            std::bind(&LoggerInstance::saveMsgCallback, this, std::placeholders::_1))));
        // mCommandsQueue.addCommand();
        // std::lock_guard<std::mutex> lock(mMutex);
        // mMessages.push(std::move(msg));
    }

    void LoggerInstance::addSink(std::unique_ptr<ISink> sink)
    {
        mSinkVector.push_back(std::move(sink));
    }

    void LoggerInstance::saveMsgCallback(MessageWithInfo msg)
    {
        mSortedCircularBuffer.put(std::move(msg));
    }

    void LoggerInstance::popCallback(MessageWithInfo msg)
    {
        mCommandsQueue.addCommand(std::unique_ptr<FormatMessageCommand>(new FormatMessageCommand(std::move(msg), 
            std::bind(&LoggerInstance::formatedMsgCallback, this, std::placeholders::_1))));
    }

    void LoggerInstance::formatedMsgCallback(std::string msg)
    {
        mCommandsQueue.addCommand(std::unique_ptr<SinkMessageCommand>(new SinkMessageCommand(std::move(msg), 
            std::bind(&LoggerInstance::pushToAllSinksCallback, this, std::placeholders::_1))));
    }

    void LoggerInstance::pushToAllSinksCallback(std::string msg)
    {
        for (const auto& sink : mSinkVector)
        {
            sink->saveMessage(msg);
        }
    }

}
