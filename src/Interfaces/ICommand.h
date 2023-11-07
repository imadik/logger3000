#pragma once

namespace lgr3k
{
    class ICommand
    {
    public:
        virtual ~ICommand() = default;
        virtual void execute() = 0;
    };
}
