#include "FormatMessageCommand.h"
#include <ostream>
#include <sstream>
#ifdef DEBUG
#include <iostream>
#include <iomanip>

#endif

namespace lgr3k
{
    FormatMessageCommand::FormatMessageCommand(MessageWithInfo msg, std::function<void(std::string)> callback)
        : mMsg(std::move(msg))
        , mCallback(std::move(callback))
    {

    }

    void FormatMessageCommand::execute()
    {
        #ifdef DEBUG
        std::cout<<__PRETTY_FUNCTION__
                <<mMsg.threadId<<" "
                <<mMsg.time.time_since_epoch().count()<<" "
                <<mMsg.logLevel.getStr()<<" "
                <<mMsg.sourceLocation.file_name()<<" "
                <<mMsg.sourceLocation.line()<<" "
                <<mMsg.sourceLocation.function_name()<<" "
                <<mMsg.text<<std::endl;
        #endif
        std::ostringstream stream;
        stream<<mMsg.threadId<<" "
                <<mMsg.time.time_since_epoch().count()<<" "
                <<mMsg.logLevel.getStr()<<" "
                <<mMsg.sourceLocation.file_name()<<" "
                <<mMsg.sourceLocation.line()<<" "
                <<mMsg.sourceLocation.function_name()<<" "
                <<mMsg.text<<std::endl;
        mCallback(stream.str());
    }

    CommandType FormatMessageCommand::getType() const
    {
        return CommandType::SINK_MESSAGE;
    }

} // namespace lgr3k
