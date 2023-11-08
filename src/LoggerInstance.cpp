#include "LoggerInstance.h"
#include "AddSinkCommand.h"
#include "FormatMessageCommand.h"
#include "SaveMessageCommand.h"
#include "SinkMessageCommand.h"
#include "DefaultFormatter.h"
#include "DefaultFilter.h"
#include "DefaultSink.h"
#include <mutex>
#include <functional>

namespace lgr3k
{

    LoggerInstance::LoggerInstance(std::size_t bufferSize,
        std::shared_ptr<IFilter> filter,
        std::shared_ptr<IFormatter> formatter,
        std::shared_ptr<ISink> sink)
        : mSortedCircularBuffer(bufferSize, std::bind(&LoggerInstance::popMsgImpl, this, std::placeholders::_1))
    {
        if (!filter)
        {
            mFilter = std::make_shared<DefaultFilter>();
        }
        if (!formatter)
        {
            mFormatter = std::make_shared<DefaultFormatter>();
        }
        if (!sink)
        {
            mSinkVector.push_back(std::make_shared<DefaultSink>());
        }
    }

    void LoggerInstance::saveLog(MessageWithInfo msg)
    {
        mCommandsQueue.addCommand(std::unique_ptr<SaveMessageCommand>(new SaveMessageCommand(std::move(msg), 
            mFilter, std::bind(&LoggerInstance::saveMsgImpl, this, std::placeholders::_1))));
    }

    void LoggerInstance::addSink(std::shared_ptr<ISink> sink)
    {
        mCommandsQueue.addCommand(std::unique_ptr<AddSinkCommand>(new AddSinkCommand(std::move(sink), 
            std::bind(&LoggerInstance::addSinkImpl, this, std::placeholders::_1))));
    }

    void LoggerInstance::saveMsgImpl(MessageWithInfo msg)
    {
        mSortedCircularBuffer.put(std::move(msg));
    }

    void LoggerInstance::popMsgImpl(MessageWithInfo msg)
    {
        mCommandsQueue.addCommand(std::unique_ptr<FormatMessageCommand>(new FormatMessageCommand(std::move(msg), 
            mFormatter, std::bind(&LoggerInstance::formatMsgImpl, this, std::placeholders::_1))));
    }

    void LoggerInstance::formatMsgImpl(std::string msg)
    {
        mCommandsQueue.addCommand(std::unique_ptr<SinkMessageCommand>(new SinkMessageCommand(std::move(msg), 
            std::bind(&LoggerInstance::pushToAllSinksImpl, this, std::placeholders::_1))));
    }

    void LoggerInstance::pushToAllSinksImpl(std::string msg)
    {
        for (const auto& sink : mSinkVector)
        {
            sink->saveMessage(msg);
        }
    }

    void LoggerInstance::addSinkImpl(std::shared_ptr<ISink> sink)
    {
        bool repeated = false;
        for (const auto& existingSink : mSinkVector)
        {
            if (existingSink == sink)
            {
                repeated = true;
                break;
            }
        }    
        if (!repeated)
        {
            mSinkVector.push_back(std::move(sink));
        }
    }
}
