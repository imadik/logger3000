#pragma once

#include <Interfaces/ICommand.h>
#include "InnerTypes.h"
#include <functional>

namespace lgr3k
{
    class FormatMessageCommand : public ICommand
    {
    public:
        FormatMessageCommand(MessageWithInfo msg, std::function<void(std::string)> callback);
        void execute() override;
        CommandType getType() const override;
    private:
        MessageWithInfo mMsg;
        std::function<void(std::string)> mCallback;
    };
} // namespace lgr3k
