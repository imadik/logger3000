#pragma once

#include "Interfaces/ICommand.h"
#include <atomic>
#include <condition_variable>
#include <memory>
#include <mutex>
#include <queue>
#include <thread>

namespace lgr3k
{
    class CommandsQueue
    {
    public:
        CommandsQueue();
        virtual~CommandsQueue();
        void addCommand(std::unique_ptr<ICommand> command);

    private:
        void workerThread();

        std::atomic_bool mStopFlag{false};
        std::mutex mMutex;
        std::condition_variable mCondVar;
        std::queue<std::unique_ptr<ICommand>> mCommands;
        std::thread mThread;
    };
} // namespace lgr3k
