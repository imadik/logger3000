#include "AddSinkCommand.h"

namespace lgr3k
{
    AddSinkCommand::AddSinkCommand(std::shared_ptr<ISink> sink, std::function<void(std::shared_ptr<ISink>)> callback)
        : mSink(std::move(sink))
        , mCallback(std::move(callback))
    {

    }

    void AddSinkCommand::execute()
    {
        mCallback(std::move(mSink));
    }
} // namespace lgr3k
