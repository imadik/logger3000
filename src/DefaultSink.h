#pragma once

#include "Interfaces/ISink.h"

namespace lgr3k
{
    class DefaultSink : public ISink
    {
    public:
        void saveMessage(const std::string& msg) override;
    };
} // namespace lgr3k
