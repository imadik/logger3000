#include "DefaultSink.h"
#include <iostream>


namespace lgr3k
{
    void DefaultSink::saveMessage(const std::string& msg)
    {
        std::cout << msg;
    }

} // namespace lgr3k
