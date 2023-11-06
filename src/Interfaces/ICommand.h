#pragma once

namespace lgr3k
{
    enum class CommandType : unsigned int
    {
        SAVE_MESSAGE,
        SINK_MESSAGE,
        FORMAT_MESSAGE,
    };

    class ICommand
    {
    public:
        virtual ~ICommand() = default;
        virtual void execute() = 0;
        virtual CommandType getType() const = 0;
    };
}
