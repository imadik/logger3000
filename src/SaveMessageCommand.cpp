#include "SaveMessageCommand.h"

#ifdef DEBUG
#include <iostream>
#include <iomanip>

#endif

namespace lgr3k
{
    SaveMessageCommand::SaveMessageCommand(MessageWithInfo msg, std::shared_ptr<IFilter> filter,
        std::function<void(MessageWithInfo)> nextStepCallback)
        : mMsg(std::move(msg))
        , mFilter(std::move(filter))
        , mNextStepCallback(std::move(nextStepCallback))
    {
    }

    void SaveMessageCommand::execute()
    {
        if (mFilter->isNeededToSave(mMsg))
        {
            mNextStepCallback(std::move(mMsg));
        }
    }
} // namespace lgr3k
