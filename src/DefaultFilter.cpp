#include "DefaultFilter.h"

namespace lgr3k
{
    bool DefaultFilter::isNeededToSave(const MessageWithInfo& msg) const
    {
        // TODO change
        bool result = true;
        if (msg.logLevel.getLevel() > LEVEL::LEVEL_DEBUG)
            result = false;
        return result;
    }
} // namespace lgr3k
