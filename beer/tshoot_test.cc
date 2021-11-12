#include <iostream>
#include <stdexcept>
#include <chrono>
#include <thread>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace windows
{
    enum class Severity
    {
        LOW,
        MEDIUM,
        CRITICAL
    };
    // proprietary library, slow and licensed
    bool troubleshooting_tool(Severity severity)
    {
        std::cout << "Looking for solution...\n";
        std::this_thread::sleep_for(std::chrono::seconds(7));
        throw std::runtime_error{"System Windows cannot find the solution."};
    }
} // namespace windows

// client tool that need to be tested
struct AdvancedTroubleshootingTool
{
    std::function<bool(windows::Severity)> predicate = &windows::troubleshooting_tool;
    void FixMonitorDriver()
    {
        try
        {
            predicate(windows::Severity::CRITICAL);
        }
        catch (const std::exception &ex)
        {
            std::cout << "Success: " << ex.what() << "\n";
            throw ex;
        }
    }
};

TEST(AdvancedTroubleshootingToolTest, DoesNotFixMonitorDriver)
{
    ::testing::MockFunction<bool(windows::Severity)> windowsTrouleshootingMock;
    EXPECT_CALL(windowsTrouleshootingMock, Call(windows::Severity::CRITICAL))
        .WillOnce(::testing::Throw(std::runtime_error{"Exception thrown from mock."}));

    AdvancedTroubleshootingTool unit_under_test{windowsTrouleshootingMock.AsStdFunction()};

    EXPECT_THROW(unit_under_test.FixMonitorDriver(), std::exception);
}