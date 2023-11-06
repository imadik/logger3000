#include "Logger3000/Logger.h"
#include "LoggerInstance.h"
#include "Mocks/Mocks.h"

#include <chrono>
#include <iostream>
#include <thread>

#include <memory>

#include <gmock/gmock.h>

#include <gtest/gtest.h>

namespace lgr3kTest
{
    using ::testing::_;
    using ::testing::Return;

    class Logger3000Test : public ::testing::Test
    {
    public:
        Logger3000Test() = default;
    };

    TEST_F(Logger3000Test, simple_test)
    {
        std::unique_ptr<lgr3k::LoggerInstance> instance(new lgr3k::LoggerInstance(3));
        lgr3k::initLogger3000(instance.get());
        lgr3k::LogDebug()<<"test1";
        lgr3k::LogDebug()<<"test2";
        lgr3k::LogDebug()<<"test3";
        lgr3k::LogDebug()<<"test4";
        lgr3k::LogDebug()<<"test5";

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));


        lgr3k::finishLogger3000();
    }
}