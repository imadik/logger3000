#include "SaveMessageCommand.h"

#ifdef DEBUG
#include <iostream>
#include <iomanip>

#endif

namespace lgr3k
{
    SaveMessageCommand::SaveMessageCommand(MessageWithInfo msg, std::function<void(MessageWithInfo)> callback)
        : mMsg(std::move(msg))
        , mCallback(std::move(callback))
    {

    }

    void SaveMessageCommand::execute()
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
        mCallback(std::move(mMsg));
    }

    CommandType SaveMessageCommand::getType() const
    {
        return CommandType::SAVE_MESSAGE;
    }

} // namespace lgr3k
