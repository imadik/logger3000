#pragma once

#include "InnerTypes.h"
#include "ISink.h"
#include <memory>

namespace lgr3k
{
    class IInstance
    {
    public:
        virtual ~IInstance() = default;
        virtual void saveLog(MessageWithInfo msg) = 0;
        virtual void addSink(std::shared_ptr<ISink> sink) = 0;
    };
}
