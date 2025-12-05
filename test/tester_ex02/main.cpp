
#include "tester.hpp"




TEST(check_result_file, check_if_equal) 
{
    std::string output = RUN_PROGRAME("../../cpp00/ex02/account_exec");
    std::string log = file_log();
    EXPECT_EQ(output, log) 
        << "\n❌ Test failed: Program output does not match the expected log file.\n"
        << "---- Program Output ----\n" << output << "\n"
        << "---- Expected Log ----\n" << log << "\n"
        << "Please check differences carefully (extra characters, missing lines, or formatting issues).";
}



int main(int argc, char **argv)
{
    if (access("../../cpp00/ex02/account_exec", X_OK) != 0)
    {
        std::cerr << "❌ Executable  not found or not executable\n";
        return 1;
    }
    ::testing::InitGoogleTest(&argc, argv);

    auto& listeners = ::testing::UnitTest::GetInstance()->listeners();
    delete listeners.Release(listeners.default_result_printer());
    listeners.Append(new UIXPrinterEx02);
    return RUN_ALL_TESTS();
}