#include <gtest/gtest.h>


TEST (nametest, subtest)
{
    ASSERT_FALSE(2 == 1);
}


int main (int ac, char **av)
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}


