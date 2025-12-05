
#include "tester.hpp"






// TEST (check_result_file, check_if_equal)
// {
//     std::string
// }



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    auto& listeners = ::testing::UnitTest::GetInstance()->listeners();
    delete listeners.Release(listeners.default_result_printer());
    listeners.Append(new UIXPrinterEx02);

    return RUN_ALL_TESTS();
}