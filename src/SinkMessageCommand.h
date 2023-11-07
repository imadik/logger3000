#pragma once

#include <Interfaces/ICommand.h>
#include "InnerTypes.h"
#include <functional>

namespace lgr3k
{
    class SinkMessageCommand : public ICommand
    {
    public:
        SinkMessageCommand(std::string msg, std::function<void(std::string)> callback);
        void execute() override;

    private:
        std::string mMsg;
        std::function<void(std::string)> mCallback;
    };
} // namespace lgr3k
