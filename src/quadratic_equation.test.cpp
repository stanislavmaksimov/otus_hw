#include <gtest/gtest.h>
#include "quadratic_equation.hpp"

GTEST_TEST(QuadraticEquation, Test3_No_roots)
{
    constexpr const double a = 2, b = 0, c = 1;

    const auto result = solve(a, b, c);

    EXPECT_TRUE(result.empty());
}

GTEST_TEST(QuadraticEquation, Test5_Two_roots)
{
    constexpr const double a = 1, b = 0, c = -1;
    
    const auto result = solve(a, b, c);

    EXPECT_EQ(result.size(), 2);
    EXPECT_EQ(result.at(0), 1);
    EXPECT_EQ(result.at(1), -1);
}

GTEST_TEST(QuadraticEquation, Test7_One_root)
{
    constexpr const double a = 1, b = 2, c = 1;
    
    const auto result = solve(a, b, c);

    EXPECT_EQ(result.size(), 1);
    EXPECT_EQ(result.at(0), -1);
}

GTEST_TEST(QuadraticEquation, Test9_A_is_zero)
{
    constexpr const double a = 0, b = 0, c = 0;
    
    EXPECT_THROW(solve(a, b, c), std::invalid_argument);
}

GTEST_TEST(QuadraticEquation, Test13_other_types)
{
    constexpr const int int_value = 0;
    EXPECT_THROW(solve(int_value, int_value, int_value), std::invalid_argument);

    const std::string string_value("0");
    EXPECT_THROW(solve(string_value, string_value, string_value), std::invalid_argument);
}
