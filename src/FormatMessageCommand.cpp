#include "FormatMessageCommand.h"



namespace lgr3k
{
    FormatMessageCommand::FormatMessageCommand(MessageWithInfo msg, std::shared_ptr<IFormatter> formatter, 
        std::function<void(std::string)> callback)
        : mMsg(std::move(msg))
        , mFormatter(std::move(formatter))
        , mNextStepCallback(std::move(callback))
    {
    }

    void FormatMessageCommand::execute()
    {
        mNextStepCallback(mFormatter->format(mMsg));
    }
} // namespace lgr3k
