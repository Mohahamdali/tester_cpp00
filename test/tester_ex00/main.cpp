#include "tester.hpp"
#define RED_TEXT "\033[31m"
#define RESET_TEXT "\033[0m"

#ifndef MEGAPHONE_PATH
#define MEGAPHONE_PATH "./megaphone"
#endif

TEST(test_megaphone, no_argumet)
{
    std::string out = RUN_AND_CLEAN(MEGAPHONE_PATH);
    EXPECT_EQ(out, "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n") 
        << RED_TEXT << "TESTER ERROR: No arguments should produce the default loud feedback" << RESET_TEXT;
}

TEST(test_megaphone, TOO_argument)
{
    std::string cmd = std::string(MEGAPHONE_PATH) + " a b c";
    EXPECT_EQ(RUN_AND_CLEAN(cmd), "ABC\n") 
        << RED_TEXT << "TESTER ERROR: Multiple arguments should be concatenated and uppercased" << RESET_TEXT;
}

TEST(test_megaphone, one_argument)
{
    std::string cmd = std::string(MEGAPHONE_PATH) + " hello";
    EXPECT_EQ(RUN_AND_CLEAN(cmd), "HELLO\n") 
        << RED_TEXT << "TESTER ERROR: Single argument should be converted to uppercase" << RESET_TEXT;
}

TEST(test_megaphone, numbers_argument)
{
    std::string cmd = std::string(MEGAPHONE_PATH) + " 123 abc 456";
    EXPECT_EQ(RUN_AND_CLEAN(cmd), "123ABC456\n")
        << RED_TEXT << "TESTER ERROR: Numbers should not change, only letters uppercased"
        << RESET_TEXT;
}

TEST(test_megaphone, long_argument)
{
    std::string long_arg(2000, 'a');
    std::string expected(2000, 'A');
    std::string cmd = std::string(MEGAPHONE_PATH) + " " + long_arg;
    
    EXPECT_EQ(RUN_AND_CLEAN(cmd), expected + "\n")
        << RED_TEXT << "TESTER ERROR: Program should handle long inputs"
        << RESET_TEXT;
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::TestEventListeners& listeners = 
        ::testing::UnitTest::GetInstance()->listeners();
    delete listeners.Release(listeners.default_result_printer());
    listeners.Append(new UIXPrinterEx00());
    return RUN_ALL_TESTS();
}