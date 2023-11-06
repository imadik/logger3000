#include "CommandsQueue.h"

namespace lgr3k
{
    CommandsQueue::CommandsQueue()
    {
        mThread = std::thread(&CommandsQueue::workerThread, this);
    }

    CommandsQueue::~CommandsQueue()
    {
        {
            std::unique_lock<std::mutex> lock(mMutex);
            mStopFlag = true;
        }
        mCondVar.notify_all();
        if (mThread.joinable())
        {
            mThread.join();
        }
    }

    void CommandsQueue::addCommand(std::unique_ptr<ICommand> command)
    {
        std::unique_lock<std::mutex> lock(mMutex);
        mCommands.push(std::move(command));
        mCondVar.notify_all();
    }

    void CommandsQueue::workerThread()
    {
        std::queue<std::unique_ptr<ICommand>> tempCommands;
        std::unique_lock<std::mutex> lock(mMutex);
        do
        {
            mCondVar.wait(lock, [this](){return (mStopFlag || !mCommands.empty());});
            if (!mCommands.empty())
            {
                tempCommands.swap(mCommands);
                lock.unlock();
                while (!tempCommands.empty())
                {
                    tempCommands.front()->execute();
                    tempCommands.pop();
                }
                lock.lock();
            }
        }
        while (!mStopFlag);
    }
} // namespace lgr3k
