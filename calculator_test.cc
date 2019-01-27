#include "gtest/gtest.h"
#include "calculator.h"

TEST(CalculatorTest, TestOperationSimplePlus1)
{
    auto result = calculate("2 2 +");
    EXPECT_DOUBLE_EQ(4, result);
}

TEST(CalculatorTest, TestOperationSimplePlus2)
{
    auto result = calculate("2.3 2 +");
    EXPECT_DOUBLE_EQ(4.3, result);
}

TEST(CalculatorTest, TestOperationSimplePlus3)
{
    auto result = calculate("2 2.3 +");
    EXPECT_DOUBLE_EQ(4.3, result);
}

TEST(CalculatorTest, TestOperationSimpleMinus)
{
    auto result = calculate("5 2 -");
    EXPECT_DOUBLE_EQ(3, result);
}

TEST(CalculatorTest, TestOperationSimpleMultiply)
{
    auto result = calculate("2 3 *");
    EXPECT_DOUBLE_EQ(6, result);
}

TEST(CalculatorTest, TestOperationSimpleDivide)
{
    auto result = calculate("4 2 /");
    EXPECT_DOUBLE_EQ(2, result);
}

TEST(CalculatorTest, TestCalculateLongNotation)
{
    auto result = calculate("5 3 + 7 * 2 /");
    EXPECT_DOUBLE_EQ(28, result);
}

TEST(CalculatorTest, TestCalculateDivideByZero)
{
    auto result = calculate("5 1 - 0 /");
    EXPECT_DOUBLE_EQ(0, result);
}

TEST(CalculatorTest, TestCalculateEmptyString)
{
    auto result = calculate("");
    EXPECT_DOUBLE_EQ(0, result);
}

TEST(CalculatorTest, TestCalculateTwoSpaces)
{
    auto result = calculate("5 1  - 4 /");
    EXPECT_DOUBLE_EQ(1, result);
}

TEST(CalculatorTest, TestCalculateWrongOperands)
{
    auto result = calculate("2 2 + 2 2");
    EXPECT_DOUBLE_EQ(0, result);
}

TEST(CalculatorTest, TestCalculateWrongOperators)
{
    auto result = calculate("2 2 + -");
    EXPECT_DOUBLE_EQ(0, result);
}

TEST(CalculatorTest, TestCalculateWrongArguments)
{
    auto result = calculate("2a as +");
    EXPECT_DOUBLE_EQ(0, result);
}

TEST(CalculatorTest, TestCalculateWrongSymbolsInString)
{
    auto result = calculate("2 3 + qwe");
    EXPECT_DOUBLE_EQ(0, result);
}

TEST(CalculatorTest, TestCalculateRandomString)
{
    auto result = calculate("qwerty");
    EXPECT_DOUBLE_EQ(0, result);
}

TEST(CalculatorTest, TestCalculateOperationsWithDoubles)
{
    auto result = calculate("5 2 /");
    EXPECT_DOUBLE_EQ(2.5, result);
}

//TEST(CalculatorTest, TestCalculateNumericLimitsWithPlus)
//{
//    auto result = calculate("1.79769e+308 1.79769e+308 +");
//    EXPECT_DOUBLE_EQ(0, result);
//}

//TEST(CalculatorTest, TestCalculateNumericLimitsWithMinus1)
//{
//    auto result = calculate("-10 1.79769e+308 -");
//    EXPECT_DOUBLE_EQ(0, result);
//}

//TEST(CalculatorTest, TestCalculateNumericLimitsWithMinus2)
//{
//    auto result = calculate("1.79769e+307 1.79769e+308 -");
//    EXPECT_DOUBLE_EQ(0, result);
//}

//TEST(CalculatorTest, TestCalculateNumericLimitsWithMultiply)
//{
//    auto result = calculate("1.79769e+308 1.79769e+308 *");
//    EXPECT_DOUBLE_EQ(0, result);
//}

//TEST(CalculatorTest, TestCalculateNumericLimitsWithDivide)
//{
//    auto result = calculate("1 1.79769e+308 /");
//    EXPECT_DOUBLE_EQ(0, result);
//}

//int main()
//{
//    double maxVal = std::numeric_limits<double>::max();
//    std::cout << maxVal << std::endl;
//    double val = 1.79769e+1 + 1;
//    std::cout << val << std::endl;
//    std::cout << calculate("2a 4 +") << std::endl;
//    return 0;
//}
