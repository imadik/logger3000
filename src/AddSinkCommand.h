#pragma once

#include <Interfaces/ICommand.h>
#include <Interfaces/ISink.h>
#include <functional>
#include <memory>

namespace lgr3k
{
    class AddSinkCommand : public ICommand
    {
    public:
        AddSinkCommand(std::shared_ptr<ISink> sink, std::function<void(std::shared_ptr<ISink>)> callback);
        void execute() override;
        
    private:
        std::shared_ptr<ISink> mSink;
        std::function<void(std::shared_ptr<ISink>)> mCallback;
    };
} // namespace lgr3k
