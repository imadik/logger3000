#include "SinkMessageCommand.h"

#ifdef DEBUG
#include <iostream>
#include <iomanip>

#endif

namespace lgr3k
{
    SinkMessageCommand::SinkMessageCommand(std::string msg, std::function<void(std::string)> callback)
        : mMsg(std::move(msg))
        , mCallback(std::move(callback))
    {

    }

    void SinkMessageCommand::execute()
    {
        #ifdef DEBUG
        std::cout<<__PRETTY_FUNCTION__
                <<mMsg<<std::endl;
        #endif
    }

    CommandType SinkMessageCommand::getType() const
    {
        return CommandType::SINK_MESSAGE;
    }

} // namespace lgr3k
