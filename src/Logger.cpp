#include "Logger3000/Logger.h"
#include <mutex>

// namespace
// {
//     lgr3k::LoggerInstance* loggerMainInstance = nullptr;
//     std::mutex initMutex;
// }

// namespace lgr3k
// {
//     void initLogger()
//     {
//         std::lock_guard<std::mutex> lock(initMutex);
//         if (loggerMainInstance == nullptr)
//         {
//             // TODO change owner
//             loggerMainInstance = new LoggerInstance();
//         }
//     }
// }
