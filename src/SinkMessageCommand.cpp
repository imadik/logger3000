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
        mCallback(mMsg);
    }
} // namespace lgr3k
