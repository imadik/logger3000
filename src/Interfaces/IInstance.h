#pragma once

#include "InnerTypes.h"
#include "ISink.h"

namespace lgr3k
{
    class IInstance
    {
    public:
        virtual ~IInstance() = default;
        virtual void saveLog(MessageWithInfo msg) = 0;
        virtual void addSink(std::unique_ptr<ISink> sink) = 0;
    };
}
