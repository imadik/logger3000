#pragma once

#include <Interfaces/ICommand.h>
#include <Interfaces/IFilter.h>
#include "InnerTypes.h"
#include <functional>
#include <memory>

namespace lgr3k
{
    class SaveMessageCommand : public ICommand
    {
    public:
        SaveMessageCommand(MessageWithInfo msg, std::shared_ptr<IFilter> filter,
            std::function<void(MessageWithInfo)> nextStepCallback);
        void execute() override;
        
    private:
        MessageWithInfo mMsg;
        std::shared_ptr<IFilter> mFilter;
        std::function<void(MessageWithInfo)> mNextStepCallback;
    };
} // namespace lgr3k
