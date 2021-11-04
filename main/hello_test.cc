#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "hello_greet.h"
#include "proto/person.pb.h"

namespace hello
{
    namespace
    {

        TEST(TestSuiteName, TestName0)
        {
            demo::Person p;
            p.set_name("John Doe");
            p.set_email("johndoe@google.com");
            EXPECT_EQ("Hello John Doe, your email: johndoe@google.com", get_greet(p));
        }

        TEST(TestSuiteName, TestName1)
        {
            EXPECT_EQ(21, 3 * 7);
        }

        TEST(TestSuiteName, TestName2)
        {
            testing::StaticAssertTypeEq<double, double>();
            EXPECT_THAT("abc7", testing::MatchesRegex("\\w*"));
        }
    }
}