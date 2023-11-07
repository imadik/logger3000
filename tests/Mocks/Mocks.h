#pragma once

#include "Interfaces/ICommand.h"
#include "Interfaces/ISink.h"
#include "Interfaces/IFilter.h"
#include "Interfaces/IFormatter.h"
#include <gmock/gmock.h>

namespace lgr3kTest
{
    class MockCommand : public lgr3k::ICommand
    {
    public:
        MOCK_METHOD(void, execute, (), (override));
    };

    class MockSink : public lgr3k::ISink
    {
    public:
        MOCK_METHOD(void, saveMessage, (const std::string&), (override));
    };

    class MockFormatter : public lgr3k::IFormatter
    {
    public:
        MOCK_METHOD(std::string, format,(const lgr3k::MessageWithInfo&), (const, override));
    };

    class MockFilter : public lgr3k::IFilter
    {
    public:
        MOCK_METHOD(bool, isNeededToSave,(const lgr3k::MessageWithInfo&), (const, override));
    };
}