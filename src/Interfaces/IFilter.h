#pragma once

#include "InnerTypes.h"
#include <string>

namespace lgr3k
{
    class IFilter
    {
    public:
        virtual ~IFilter() = default;
        virtual bool isNeededToSave(const MessageWithInfo& msg) const = 0;
    };
} // namespace lgr3k
