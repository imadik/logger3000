#pragma once

#include "InnerTypes.h"
#include <string>

namespace lgr3k
{
    class IFormatter
    {
    public:
        virtual ~IFormatter() = default;
        virtual std::string format(const MessageWithInfo& msg) const = 0;
    };
} // namespace lgr3k
