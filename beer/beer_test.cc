#include <memory>
#include <ctime>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

// Prod environment
enum WeekDays
{
    SUNDAY = 0,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
};

struct CalendarInterface
{
    // pure virtual (or abstract function )
    // that requires to be overwritten in an derived class
    virtual WeekDays what_day_is_today() const = 0;
    virtual ~CalendarInterface() = default;
};

struct CalendarImplementation : public CalendarInterface
{
    WeekDays what_day_is_today() const override;
};

struct Me
{
    std::unique_ptr<CalendarInterface> calendar = std::make_unique<CalendarImplementation>();

    bool can_drink_beer_today()
    {
        const auto today = calendar->what_day_is_today();
        return today == WeekDays::FRIDAY || today == WeekDays::SATURDAY;
    }
};

// Test enviroment
class MockCalendar : public CalendarInterface
{
public:
    MOCK_METHOD(WeekDays, what_day_is_today, (), (const, override));
};

TEST(MeTest, CanNotDrinkBeerOnWeekDays)
{
    auto calendar_mock = std::make_unique<::testing::StrictMock<MockCalendar>>();
    EXPECT_CALL(*calendar_mock, what_day_is_today)
        .Times(::testing::AtLeast(2))
        .WillOnce(::testing::Return(WeekDays::THURSDAY))
        .WillOnce(::testing::Return(WeekDays::SATURDAY))
        .WillRepeatedly(::testing::Return(WeekDays::SUNDAY));
    Me unit_under_test{std::move(calendar_mock)};

    EXPECT_FALSE(unit_under_test.can_drink_beer_today());
    EXPECT_TRUE(unit_under_test.can_drink_beer_today());
}

// some legacy impl code used in prod env.
WeekDays CalendarImplementation::what_day_is_today() const
{
    std::tm time_in{};
    std::time_t time_temp = std::mktime(&time_in);
    const std::tm *time_out = std::localtime(&time_temp);
    return static_cast<WeekDays>(time_out->tm_wday);
}