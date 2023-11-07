#pragma once

#include "Interfaces/IFilter.h"

namespace lgr3k
{
    class DefaultFilter : public IFilter
    {
    public:
        bool isNeededToSave(const MessageWithInfo& msg) const override;
    };
} // namespace lgr3k
