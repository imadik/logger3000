#pragma once

#include <Interfaces/ICommand.h>
#include "InnerTypes.h"
#include <functional>

namespace lgr3k
{
    class SaveMessageCommand : public ICommand
    {
    public:
        SaveMessageCommand(MessageWithInfo msg, std::function<void(MessageWithInfo)> callback);
        void execute() override;
        CommandType getType() const override;
    private:
        MessageWithInfo mMsg;
        std::function<void(MessageWithInfo)> mCallback;
    };
} // namespace lgr3k
