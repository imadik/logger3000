#pragma once

#include "Interfaces/IFormatter.h"

namespace lgr3k
{
    class DefaultFormatter : public IFormatter
    {
    public:
        std::string format(const MessageWithInfo& msg) const override;
    };
} // namespace lgr3k
