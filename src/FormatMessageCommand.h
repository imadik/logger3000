#pragma once

#include <Interfaces/ICommand.h>
#include <Interfaces/IFormatter.h>
#include "InnerTypes.h"
#include <functional>
#include <memory>

namespace lgr3k
{
    class FormatMessageCommand : public ICommand
    {
    public:
        FormatMessageCommand(MessageWithInfo msg, std::shared_ptr<IFormatter> formatter, 
            std::function<void(std::string)> nextStepCallback);
        void execute() override;

    private:
        MessageWithInfo mMsg;
        std::shared_ptr<IFormatter> mFormatter;
        std::function<void(std::string)> mNextStepCallback;
    };
} // namespace lgr3k
