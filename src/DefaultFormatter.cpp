#include "DefaultFormatter.h"
#include <ostream>
#include <sstream>
#include <iomanip>
#include <string.h>


namespace lgr3k
{
    std::string DefaultFormatter::format(const MessageWithInfo& msg) const
    {
        std::ostringstream stream;
        stream << "[";
        stream << std::fixed << std::setprecision(6) << 
            std::chrono::duration<double, std::ratio<1, 1>>(msg.time.time_since_epoch()).count();
        stream << "] ";
        stream << msg.logLevel.getStr() << " ";
        stream << std::hex << std::uppercase << msg.threadId << std::dec << " ";
        stream << (strrchr(msg.sourceLocation.file_name(), '/') ? 
            strrchr(msg.sourceLocation.file_name(), '/') + 1 : 
            msg.sourceLocation.file_name()) << "(" << msg.sourceLocation.line()<<") - " <<
            msg.sourceLocation.function_name()<<": " <<
            msg.text<<std::endl;
        return stream.str();    
    }
} // namespace lgr3k
