#pragma once

#include <string>

namespace lgr3k
{
    class ISink
    {
    public:
        virtual ~ISink() = default;
        virtual void saveMessage(const std::string& msg) = 0;
    };
}
