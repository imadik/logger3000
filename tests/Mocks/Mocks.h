#pragma once

#include "Interfaces/ICommand.h"
#include "Interfaces/ISink.h"
#include <gmock/gmock.h>

namespace lgr3kTest
{
    class MockCommand : public lgr3k::ICommand
    {
    public:
        MOCK_METHOD(void, execute, (), (override));
        MOCK_METHOD(lgr3k::CommandType, getType, (), (const, override));
    };

    class MockSink : public lgr3k::ISink
    {
    public:
        MOCK_METHOD(void, saveMessage, (const std::string&), (override));
    };
}